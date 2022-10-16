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
    int n, k;
    cin >> n >> k;
    int ans1 = n + 1 + n;
    ans1 += min((k - 1) * 2 + n - k, (n - k) * 2 + (k - 1));
    cout << ans1;
    return 0;
}