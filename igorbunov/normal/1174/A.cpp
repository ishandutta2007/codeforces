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
    n *= 2;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (arr[0] == arr[n - 1]) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}