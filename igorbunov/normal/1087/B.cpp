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

double eps = 1e-3;

#define int long long
#define double long double
#define endl "\n"


signed main() {
    int n, k;
    cin >> n >> k;
    int now = 1;
    while (true) {
        if (n % now == 0) {
            if (n / now < k) {
                cout << now * k + (n / now);
                return 0;
            }
        }
        now++;
    }
    return 0;
}