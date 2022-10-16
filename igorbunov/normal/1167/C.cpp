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
#define endl '\n'

vector<int> g[600000];
vector<int> now;
vector<bool> used(600000);
vector<vector<int>> arr(600000);
vector<vector<int>> arr1(600000);
set<int> ans;

void dfs(int v) {
    used[v] = true;
    now.push_back(v);
    for (int i = 0; i < arr1[v].size(); i++) {
        ans.insert(arr1[v][i]);
    }
    for (auto u: g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            a--;
            arr[a].push_back(i);
            arr1[i].push_back(a);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)arr[i].size() - 1; j++) {
            //cout << arr[i][j] << " " << arr[i][j + 1] << endl;
            g[arr[i][j]].push_back(arr[i][j + 1]);
            g[arr[i][j + 1]].push_back(arr[i][j]);
        }
    }
    vector<int> ans1(n, 1);
    
    //return 0;
    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            ans.clear();
            now.clear();
            dfs(i);
            for (int j = 0; j < now.size(); j++) {
                int a = now[j];
                for (int k = 0; k < arr1[a].size(); k++) {
                    ans1[arr1[a][k]] = ans.size();
                }
            }
        }
    }
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << " ";
    }
}