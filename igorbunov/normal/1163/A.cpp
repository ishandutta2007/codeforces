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
#include <deque>
#include <queue>
#include <set>
#include <map>

using namespace std;

//#define int long long
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (n % 2 == 0) {
        int k = n / 2;
        if (m <= k) {
            cout << max(1, m);
        } else {
            cout << n - m;
        }
    } else {
        int k = n / 2;
        if (m <= k) {
            cout << max(1, m);
        } else {
            cout << n - m;
        }
    }
    return 0;
}