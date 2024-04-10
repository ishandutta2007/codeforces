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

//keldyshev

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
    string t;
    cin >> t;
    string s;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != 'a') {
            s.push_back(t[i]);
        }
    }
    if (s.size() % 2 == 1) {
        cout << ":(";
        return 0;
    }
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[i + s.size() / 2]) {
            cout << ":(";
            return 0;
        }
    }
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != t[i + t.size() - s.size() / 2]) {
            cout << ":(";
            return 0;
        }
    }
    for (int i = 0; i < t.size() - s.size() / 2; i++) {
        cout << t[i];
    }
    return 0;
}