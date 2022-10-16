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

#define int long long
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
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> s(n);
    for (int j = 0; j < n; j++) {
        cin >> s[j];
        s[j]--;
    }
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        c[i]--;
    }
    vector<vector<int>> arr1(m);
    for (int i = 0; i < n; i++) {
        arr1[s[i]].push_back(arr[i]);
    }
    for (int i = 0; i < m; i++) {
        sort(arr1[i].begin(), arr1[i].end());
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int ind = s[c[i]];
        int count = arr[c[i]];
        if (count != arr1[ind].back()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}