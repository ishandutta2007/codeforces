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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i] >> arr[i];
    }
    int k;
    cin >> k;
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] < k) {
            ans--;
        }
    }
    cout << ans;
    return 0;
}