//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define _USE_MATH_DEFINES

#include <algorithm>
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
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

double eps = 1e-6;

vector<int> arr(100000);

int n;
int sum = 0;
bool b = 0;

void gen(int now) {
    if (now == n) {
        if (sum % 360 == 0) {
            b = 1;
        }
        return;
    }
    sum += arr[now];
    gen(now + 1);
    sum -= 2 * arr[now];
    gen(now + 1);
    sum += arr[now];
}

int check(string b) {
    vector<char> now;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '(') {
            now.push_back(b[i]);
        } else {
            if (now.size() == 0) {
                now.push_back(b[i]);
                continue;
            }
            if (now.back() == '(') {
                now.pop_back();
            } else {
                now.push_back(b[i]);
            }
        }
    }
    if (now.size() == 0) {
        return 0;
    }
    char now1 = now[0];
    for (int i = 0; i < now.size(); i++) {
        if (now[i] != now1) {
            return 1000000;
        }
    }
    if (now1 == '(') {
        return now.size();
    } else {
        return now.size() * -1;
    }
}

signed main() {
    int w, h;
    cin >> w >> h;
    int u1, d1;
    cin >> u1 >> d1;
    int u2, d2;
    cin >> u2 >> d2;
    for (int i = h; i >= 0; i--) {
        w += i;
        if (i == d1) {
            w -= u1;
        }
        if (i == d2) {
            w -= u2;
        }
        if (w < 0) {
            w = 0;
        }
    }
    cout << w;
    return 0;
}