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

#define int long long
#define endl '\n'

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool is = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '8') {
                if (n - i - 1 >= 10) {
                    is = true;
                    cout << "YES \n";
                    break;
                }
            }
        }
        if (!is) {
            cout << "NO";
            cout << endl;
        }
    }
}