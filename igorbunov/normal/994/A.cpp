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

bool arr3[100];
bool arr4[100];

signed main() {
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr3[arr1[i]] = 1;
    }
    for (int j = 0; j < m; j++) {
        cin >> arr2[j];
        arr4[arr2[j]] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (arr3[arr1[i]] && arr4[arr1[i]]) {
            cout << arr1[i] << " ";
        }
    }
}