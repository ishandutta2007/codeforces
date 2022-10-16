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

bool check(int ind, string &s) {
    for (int i = ind; i < s.size(); i++) {
        if (s[i] != '9') {
            return false;
        }
    }
    return true;
}

int find(int ind, string &s) {
    if (ind < 0) {
        return 1;
    }
    int now = s[0] - '0';
    for (int i = 1; i <= ind; i++) {
        now *= (s[i] - '0');
    }
    return now;
}

int pow1(int count) {
    int now = 1;
    for (int i = 0; i < count; i++) {
        now *= 9;
    }
    return now;
}

signed main() {
    string s;
    cin >> s;
    int ans = find(s.size() - 1, s);
    bool check = true;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '0') {
            check = false;
        }
    }
    if (check && s[0] == '0') {
        cout << pow1(s.size() - 1);
        return 0;
    }
    ans = max(ans, pow1(s.size() - 1));
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            continue;
        }
        int now = find(i - 1, s) * (s[i] - '0' - 1) * pow1(s.size() - i - 1);
        if (now > ans) {
            ans = now;
        }
    }
    cout << ans;
    return 0;
}