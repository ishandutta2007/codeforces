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
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
/* ------------   -------------
 |                          |
 |                          |
 |-----------             --|--
            |               |
            |               |
 ------------               |
 */

using namespace std;

#define int long long
#define double long double
#define pd pair<double, double>

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    for (int sum = 0; sum <= n + m - 2; sum++) {
        vector<int> arr1;
        vector<int> arr2;
        for (int i = 0; i < n; i++) {
            int j = sum - i;
            if (j < 0 || j > m - 1) {
                continue;
            }
            arr1.push_back(a[i][j]);
            arr2.push_back(b[i][j]);
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        if (arr1 != arr2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}