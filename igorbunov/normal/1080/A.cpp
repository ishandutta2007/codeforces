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
    int n, k;
    cin >> n >> k;
    cout << ((2 * n - 1) / k) + 1 + ((5 * n - 1) / k) + 1 + ((8 * n - 1) / k) + 1;
    return 0;
}