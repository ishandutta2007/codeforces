//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>

//#define int long long
#define endl "\n"
 
using namespace std;

vector<int> g[500000];
vector<int> gr[500000];
vector<int> ans(500000, -5);
vector<int> now;
vector<bool> used(500000);

void dfs(int v) {
    now.push_back(v);
    used[v] = 1;
    for (int u: g[v]) {
         if (!used[u]) {
            dfs(u);
            ans[u] = v;
         }
    }
}

int n, k;

int rount(int m) {
    double a = n * 1.0;
    double b = m * 1.0;
    double c = b / a * 100.0 + 0.5;
    int d = (int)c;
    return d;
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<pair<int, int>> now(k, make_pair(-1, -1));
    int ind = 0;
    int m = 0;
    int time1 = 0;
    int ans1 = 0;
    vector<bool> used(n, false);
    while (time1 < 1000000) {
        time1++;
        for (int i = 0; i < k; i++) {
            if (now[i].second == rount(m) && now[i].first > -1) {
                used[now[i].first] = true; 
                ans1++;
            }
        }
        //cout << time1 << " " << m << " " << rount(m) << " " << ans1 << endl;
        for (int i = 0; i < k; i++) {
            //cout << now[i].first << " " << now[i].second << endl;
        }
        //cout << endl;
        for (int i = 0; i < k; i++) {
            if (now[i] == make_pair(-1, -1) && ind >= n) {
                continue;
            }
            if (now[i] == make_pair(-1, -1) && ind < n) {
                now[i] = make_pair(ind, 1);
                ind++;
            } else {
                if (now[i].second == arr[now[i].first]) {
                    now[i] = make_pair(-1, -1);
                    m++;
                } else {
                    now[i].second++;
                }
            }
            if (now[i] == make_pair(-1, -1) && ind < n) {
                now[i] = make_pair(ind, 1);
                ind++;
            }
        }
        for (int i = 0; i < k; i++) {
            if (now[i].second == rount(m) && now[i].first > -1) {
                used[now[i].first] = true; 
                ans1++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}