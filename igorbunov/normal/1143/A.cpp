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

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> c(2);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        c[arr[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans++;
        c[arr[i]]--;
        if (c[arr[i]] == 0) {
            cout << ans;
            return 0;
        }
    }
    return 0;
}