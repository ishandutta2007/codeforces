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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    string need = "theseus";
    for (int _ = 0; _ < 8; _++) {
        if (ban[_]) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = i;
                int b = j;
                bool good = true;
                for (int k = 0; k < need.size(); k++) {
                    if (min(a, b) < 0 || max(a, b) >= n) {
                        good = false;
                        break;
                    }
                    if (arr[a][b] != need[k]) {
                        good = false;
                        break;
                    }
                    a += x[_];
                    b += y[_];
                }
                if (good) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}