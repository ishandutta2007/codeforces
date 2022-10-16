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


// a a + c
// b b + d       ab + ab + ac + bc + cc

#define int long long
#define endl '\n'


signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    ans.push_back(s[0]);
    char last = s[0];
    for (int i = 1; i < n; i++) {
        if (last == '#') {
            ans.push_back(s[i]);
            last = s[i];
        } else {
            if (s[i] != last) {
                ans.push_back(s[i]);
                last = '#';
            }
        }
    }
    if (ans.size() % 2 == 1) {
        ans.pop_back();
    }
    cout << s.size() - ans.size() << endl;
    cout << ans;
}