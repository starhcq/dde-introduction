/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NORMALMODULE_H
#define NORMALMODULE_H

#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QMap>

#include <DWidget>
#include <DPalette>

#include <com_deepin_wmswitcher.h>

using WMSwitcher = com::deepin::WMSwitcher;
DWIDGET_USE_NAMESPACE
DGUI_USE_NAMESPACE
class ModuleInterface;
class NavigationButton;
class NormalModule : public DWidget
{
    Q_OBJECT
public:
    explicit NormalModule(DWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;
    //void keyPressEvent(QKeyEvent *e);

private:
    void updateCurrentWidget(const int index);
    void updataButton(QAbstractButton *btn);
private slots:
    void initTheme(int type);

private:
    QVBoxLayout *m_leftNavigationLayout;
    QVBoxLayout *m_rightContentLayout;
    QButtonGroup *m_buttonGrp;
    QMap<QWidget*, int> m_buttonMap;
    QMap<QAbstractButton*, QString> m_titleMap;
    QMap<QAbstractButton*, QString> m_describeMap;
    QMap<int, QWidget*> m_modules;
    NavigationButton *m_button;
    QWidget *m_currentWidget;
    WMSwitcher *m_wmSwitcher;
    int m_index;
    bool isx86;
};

#endif // NORMALMODULE_H
