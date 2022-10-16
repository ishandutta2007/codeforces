//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")*/
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

//#define int long long
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> now;
    for (int i = 2; i <= 500000; i++) {
        bool can = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                can = false;
                break;
            }
        }
        if (can) {
            now.push_back(i);
        }
    }
    int a = 0;
    int b = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            a++;
        } else {
            b++;
        }
    }
    int now1 = 0;
    int ind = 0;
    int time1 = 0;
    while (a + b != 0) {
        int p = now[ind];
        int dist = p - now1;
        if (b != 0 && dist > 1) {
            b--;
            cout << "2 ";
            now1 += 2;
        } else {
            if (a != 0) {
                a--;
                cout << "1 ";
                now1++;
            } else {
                now1 += 2;
                cout << "2 ";
                b--;
            }
        }
        while (p <= now1) {
            ind++;
            p = now[ind];
        }
    }

}