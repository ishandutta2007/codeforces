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
#define double long double
#define endl "\n"

vector<vector<int>> g(100000);

signed main() {
    cout << fixed << setprecision(6);
    int n;
    double s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            ans += 1.0;
        }
    }
    cout << (s / ans) * 2;
    return 0;
}