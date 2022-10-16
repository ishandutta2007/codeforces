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
    for (int i = 0; i < q; i++) {
        int s, a, b, c;
        cin >> s >> a >> b >> c;
        int count1 = s / c;
        cout << (count1 / a) * (a + b) + (count1 % a) << endl;
    }
    return 0;
}