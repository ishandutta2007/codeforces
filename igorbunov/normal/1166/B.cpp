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

#define pb push_back
//#define int long long
#define endl "\n"

signed main() {
    vector<char> arr(5);
    arr[0] = 'a';
    arr[1] = 'e';
    arr[2] = 'i';
    arr[3] = 'o';
    arr[4] = 'u';
    int k;
    cin >> k;
    int a = -1;
    int b = -1;
    for (int i = 5; i * i <= k; i++) {
        if (k % i == 0) {
            if (k / i > 4) {
                a = i;
                b = k / i;
            }
        }
    }
    if (a == -1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[(i + j) % 5];
        }
    }
    return 0;
}