//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
//#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
//#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

double eps = 1e-3;

#define int long long
#define double long double
#define endl "\n"
#define insert1 insert

struct point{
    int x, y;
};

bool comp(point a, point b) {
    return a.x < b.x;
}

set<pair<int, int>> ans;
vector<point> prom;

void print_path_l(point a, point b) {
    int x1 = a.x;
    int y1 = a.y;
    int x2 = b.x;
    int y2 = b.y;
    int del = -1;
    if (y1 < y2) {
        del = 1;
    }
    int now_y = y1;

    point now;
    now.x = x1;
    now.y = y1; 
    while (now_y != y2) {
        prom.push_back(now);
        now_y += del;
        now.y = now_y;
    }
    prom.push_back(now);
    del = -1;
    if (x1 < x2) {
        del = 1;
    }
    int now_x = x1;
    now = a;
    now.y = y2; 
    while (now_x != x2) {
        prom.push_back(now);
        now_x += del;
        now.x = now_x;
    }
    prom.push_back(b);
    /*cout << a.x << " " << a.y << endl << b.x << " " << b.y << endl << 'L' << endl;
    for (int i = 0; i < prom.size(); i++) {
        cout << prom[i].x << " " << prom[i].y << endl;
    }
    cout << endl;*/
}

void print_path_r(point a, point b) {
    int x1 = a.x;
    int y1 = a.y;
    int x2 = b.x;
    int y2 = b.y;
    int del = -1;

    del = -1;
    if (x1 < x2) {
        del = 1;
    }
    int now_x = x1;
    point now = a;
    while (now_x != x2) {
        prom.push_back(now);
        now_x += del;
        now.x = now_x;
    }
    prom.push_back(now);
    del = -1;
    if (y1 < y2) {
        del = 1;
    }
    int now_y = y1;
    now = a; 
    now.x = x2;
    while (now_y != y2) {
        prom.push_back(now);
        now_y += del;
        now.y = now_y;
    }
    prom.push_back(b);
    /*cout << a.x << " " << a.y << endl << b.x << " " << b.y << endl << 'R' << endl;
    for (int i = 0; i < prom.size(); i++) {
        cout << prom[i].x << " " << prom[i].y << endl;
    }
    cout << endl;*/
}


signed main() {
    point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    if (a.x > b.x) {
        swap(a, b);
    }
    if (a.x > c.x) {
        swap(a, c);
    }
    if (b.x > c.x) {
        swap(b, c);
    }
    /*cout << a.x << " " << a.y << endl;
    cout << b.x << " " << b.y << endl;
    cout << c.x << " " << c.y << endl;*/
    prom.clear();
    int size = 10000000000;
    print_path_l(a, b);
    print_path_l(b, c);
    set<pair<int, int>> zvip;
    zvip.clear();
    for (int i = 0; i < prom.size(); i++) {
        zvip.insert1(make_pair(prom[i].x, prom[i].y));
    }
    if (zvip.size() < size) {
        size = zvip.size();
        ans = zvip;
    }
    prom.clear();
    print_path_l(a, b);
    //return 0;
    print_path_r(b, c);

    zvip.clear();
    for (int i = 0; i < prom.size(); i++) {
        zvip.insert1(make_pair(prom[i].x, prom[i].y));
    }
    if (zvip.size() < size) {
        size = zvip.size();
        ans = zvip;
    }
    //return 0;
    prom.clear();
    print_path_r(a, b);
    print_path_l(b, c);
    zvip.clear();
    for (int i = 0; i < prom.size(); i++) {
        zvip.insert1(make_pair(prom[i].x, prom[i].y));
    }
    if (zvip.size() < size) {
        size = zvip.size();
        ans = zvip;
    }
    prom.clear();
    print_path_r(a, b);
    print_path_r(b, c);
    zvip.clear();
    for (int i = 0; i < prom.size(); i++) {
        zvip.insert1(make_pair(prom[i].x, prom[i].y));
    }
    if (zvip.size() < size) {
        size = zvip.size();
        ans = zvip;
    }
    cout << size << endl;
    for (auto cnt : ans) {
        cout << cnt.first << " " << cnt.second << endl;
    }
    return 0;
}