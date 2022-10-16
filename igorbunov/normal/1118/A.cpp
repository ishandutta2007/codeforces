//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#pragma GCC_OPTIMAZE("ofast")
#include <algorithm>
#include <iostream>
//#include <multiset>
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

using namespace std;

#define int long long

signed main(){
    int q;
    cin >> q;
    for (int gg = 0; gg < q; gg++) {
        int n, a, b;
        cin >> n >> a >> b;
        if (2 * a <= b) {
            cout << n * a << endl;
            continue;
        } else {
            cout << (n / 2) * b + (n % 2) * a << endl;
        }
    }
    return 0;
}