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

int MAX = 1e6;

vector<vector<int>> g(MAX);
vector<int> colour(MAX, 0);
vector<bool>colour1(MAX, true);
vector<int>p(MAX, -1);
bool ans = true;
vector<int> ans1;
vector<int> ans2;

void dfsvisit(int u) {
    colour[u] = 1;
    if (colour1[u]) {
        ans1.push_back(u);
    } else {
        ans2.push_back(u);
    }
    for (int v : g[u]) {
        if (0 == colour[v]) {
            p[v] = u;
            colour1[v] = !colour1[u];
            dfsvisit(v);
        } else {
            if (colour1[u] == colour1[v]) {
                ans = false;
            }
        }
    }
    colour[u] = 2;
}

int dfs(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (0 == colour[i]) {
            dfsvisit(i);
            count++;
        }
    }
    return count;
}

signed main() {
    int n, m;
    cin >> n;
    int m1, m2;
    cin >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        cin >> m1 >> m2;
        edges.push_back(make_pair(m1 - 1, m2 - 1));
        g[m1 - 1].push_back(m2 - 1);
        g[m2 - 1].push_back(m1 - 1);
    }
    dfs(n);
    if (!ans) {
        cout << "NO";
        return 0;
    }
    cout << "YES \n";
    for (int i = 0; i < m; i++) {
        int a = edges[i].first;
        if (colour1[a]) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
    return 0;
}