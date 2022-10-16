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

//#define int long long

signed main(){
    int n;
    cin >> n;
    int count1 = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        count1 += (c == '8');
    }
    int ans = 0;
    do {
        count1--;
        n -= 11;
        ans++;
    } while (count1 >= 0 && n >= 0);
    cout << ans - 1;
    return 0;
}