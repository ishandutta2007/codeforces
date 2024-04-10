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
//#define int long long
#define endl "\n"

signed main() {
    int n;
    vector<int> arr(30);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        arr[s[0] - 'a']++;
    }
    int x = 0;
    for (int i = 0; i < 30; i++) {
        int a = arr[i] / 2;
        int b = (arr[i] + 1) / 2;
        x += (a * (a - 1)) / 2 + (b * (b - 1))/ 2;
    }
    cout << x;
    return 0;
}