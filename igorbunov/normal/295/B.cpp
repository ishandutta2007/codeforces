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

int MAXN = 1000;
vector<vector<int>> d(MAXN, vector<int> (MAXN, 10000000000));

signed main() {
    //freopen("graphgame.in", "r", stdin);
    //freopen("graphgame.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[n - 1 - i];
    }
    vector<int> now;
    //cout << 57 << endl;
    vector<int> ans1;
    vector<bool> used(n);
    for (int k = 0; k < n; k++) {
        int ans = 0;
        now.push_back(x[k] - 1);
        used[x[k] - 1] = true;
        //return 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                int a = i;
                int b = j;
                d[a][b] = min(d[a][b], d[a][x[k] - 1] + d[x[k] - 1][b]);
                if (used[a] && used[b]) {
                    ans += d[a][b];
                }
            }
        }
        ans1.push_back(ans);
        //return 0;
    }
    reverse(ans1.begin(), ans1.end());
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << " ";
    }
    return 0;
}