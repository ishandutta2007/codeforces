//  Created by Ivanq on 30.9.18.
//  Copyright (c) 2018 Ivan Gorbunov. All rights reserved.
//
#include <iostream>
#include <cstdlib>
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
#include <algorithm>

using namespace std;

#define int long long

signed main() {
    int x, y, z;
    cin >> x >> y >> z;
    int a = x - y;
    if (a == 0) {
        if (z > 0) {
            cout << "?";
        } else {
            cout << 0;
        }
    } else {
        if (a > 0) {
            if (z < a) {
                cout << "+";
            } else {
                cout << "?";
            }
        } else {
            if (a * -1 > z) {
                cout << "-";
            } else {
                cout << "?";
            }
        }
    }
    return 0;
}