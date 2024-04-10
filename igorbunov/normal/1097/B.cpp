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

vector<int> arr(100000);

int n;
int sum = 0;
bool b = 0;

void gen(int now) {
    if (now == n) {
        if (sum % 360 == 0) {
            b = 1;
        }
        return;
    }
    sum += arr[now];
    gen(now + 1);
    sum -= 2 * arr[now];
    gen(now + 1);
    sum += arr[now];
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    gen(0);
    if (b) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}