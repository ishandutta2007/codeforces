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

#define int long long

vector<vector<int>> g(100000);
vector<int> s(100000);
vector<int> p(100000);
vector<int> a(100000);

bool flag = false;

void dfs_check(int v, int depth, int max1) {
    if (s[v] != -1 && s[v] < max1) {
        flag = true;
    }
    for (int u: g[v]) {
        dfs_check(u, depth + 1, max(max1, s[v]));
    }
}

void dfs(int v, int depth) {
    if (depth % 2 == 1) {
        int last = s[p[v]];
        int min1 = 10000000000LL;
        if (g[v].size() == 0) {
            return;
        }
        for (int u: g[v]) {
            if (s[u] < min1) {
                min1 = s[u];
            }
        }
        a[v] = min1 - last;
        for (int u: g[v]) {
            a[u] = s[u] - a[v] - last;
        }
        for (int u: g[v]) {
            dfs(u, depth + 1);
        }
    } else {
        for (int u: g[v]) {
            dfs(u, depth + 1);
        }
    }
}


signed main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p1;
        cin >> p1;
        p1--;
        p[i] = p1;
        g[p1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    a[0] = s[0];
    dfs_check(0, 0, -1);
    dfs(0, 0);
    if (flag) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans;
    return 0;
}