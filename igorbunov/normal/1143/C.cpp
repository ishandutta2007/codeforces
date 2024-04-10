//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
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

vector<int> g[100005];
vector<int> g2[100005];
set<int> g1[100005];
vector<int> c(100005);
vector<bool> used(100005);

void dfs1(int v, int p = -1) {
    used[v] = true;
    if (p != -1 && c[v] == 1 && c[p] == 1) {
        g1[v].insert(p);
    }
    for (auto u: g[v]) {
        if (!used[u]) {
            dfs1(u, v);
        }
    }
}

signed main() {
    int n;
    cin >> n;
    int ind;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p >> c[i];
        p--;
        if (p == -2){
            ind = i;
        } else {
            g[p].push_back(i);
        }
    }
    bool check = 1;
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
            continue;
        }
        bool flag = 1;
        for (auto u: g[i]) {
            if (c[u] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            check = 0;
            cout << i + 1 << " ";
        }
    }
    if (check == true) {
        cout << -1;
    }
    return 0;
}