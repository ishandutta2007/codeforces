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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> c(400000);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        c[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    n = arr.size();
    int ans = -1;
    for (int sum = 0; sum <= 300000; sum++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] * 2 > sum) {
                break;
            }
            if (arr[i] * 2 == sum) {
                count += c[arr[i]] / 2;
            } else {
                count += min(c[arr[i]], c[sum - arr[i]]);
            }
        }
        if (count > ans) {
            ans = count;
        }
    }
    cout << ans;
    return 0;
}