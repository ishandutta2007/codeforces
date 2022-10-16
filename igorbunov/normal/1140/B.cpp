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
    int t, n;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> s;
        int res = n - 1;
        for(int i = 0; i < n; ++i)
            if(s[i] == '>' || s[n - 1 - i] == '<')
                res = min(res, i);
        
        cout << res << endl;
    }

    return 0;
}