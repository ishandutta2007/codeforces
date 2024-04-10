//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define _USE_MATH_DEFINES

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

double eps = 1e-6;

vector<int> arr(100000);

int n;
int sum = 0;
bool b = 0;

void gen(int now) {
    if (now == n) {
        if (sum % 360 == 0) {
            b = 1;
        }
        return;
    }
    sum += arr[now];
    gen(now + 1);
    sum -= 2 * arr[now];
    gen(now + 1);
    sum += arr[now];
}

int check(string b) {
    vector<char> now;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '(') {
            now.push_back(b[i]);
        } else {
            if (now.size() == 0) {
                now.push_back(b[i]);
                continue;
            }
            if (now.back() == '(') {
                now.pop_back();
            } else {
                now.push_back(b[i]);
            }
        }
    }
    if (now.size() == 0) {
        return 0;
    }
    char now1 = now[0];
    for (int i = 0; i < now.size(); i++) {
        if (now[i] != now1) {
            return 1000000;
        }
    }
    if (now1 == '(') {
        return now.size();
    } else {
        return now.size() * -1;
    }
}

signed main() {
    int n;
    cin >> n;
    map<int, int> m;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string b;
        cin >> b;
        m[check(b)]++;
        arr.push_back(b);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int d = check(arr[i]);
        if (d == 0) {
            ans += m[0] / 2;
            m[0] = 0;
        }
        if (d > 0) {
            int e = d * -1;
            int k = min(m[d], m[e]);
            ans += k;
            m[d] -= k;
            m[e] -= k;
        }
    }
    cout << ans;
    return 0;
}