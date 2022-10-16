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
#define endl "\n"

signed main() {
    int t;
    cin >> t;
    for (int cnt = 0; cnt < t; cnt++) {
        int n, k;
        cin >> n >> k;
        int r = 0;
        while (r != n) {
            cout << (char)('a' + (r % k));
            r++;
        }
        cout << endl;
    }
}