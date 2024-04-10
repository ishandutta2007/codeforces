//  Created by Ivanq on 30.9.18.
//  Copyright (c) 2018 Ivan Gorbunov. All rights reserved.
//
#include <iostream>
#include <cstdlib>
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
#include <algorithm>

using namespace std;

#define pb push_back
#define int long long
#define endl "\n"

vector<vector<int>> g;

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    bool a = false;
    bool b = false;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            a = true;
        } else {
            b = true;
        }
    }
    if (!(a && b)) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        return 0;
    } else {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}