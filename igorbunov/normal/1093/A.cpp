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

char arr[1000][1000];

signed main(){
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        cout << n / 7 + ((n % 7) != 0) << endl;
    }
    return 0;
}