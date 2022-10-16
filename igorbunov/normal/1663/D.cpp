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

const int MAXN = 1e6 + 15;

char arr[1000][1000];


int x[8] = {-1, 1, 1, -1, 1, -1, 0, 0};
int y[8] = {-1, 1, -1, 1, 0, 0, 1, -1};

int ban[8] = {1, 0, 1, 1, 1, 1, 1, 1};
signed main() {
    string s;
    cin >> s;
    int x;
    cin >> x;
    if (s == "ABC") {
        if (x < 2000) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    if (s == "ARC") {
        if (x < 2800) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    if (s == "AGC") {
        if (x >= 1200) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
}