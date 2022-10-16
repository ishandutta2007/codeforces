//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define _USE_MATH_DEFINES

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

double eps = 1e-6;

signed main() {
    string a;
    cin >> a;
    for (int i = 0; i < 5; i++) {
        string b;
        cin >> b;
        if (b[0] == a[0] || b[1] == a[1]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}