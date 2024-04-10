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

#define int long long

signed main() {
    int n;
    cin >> n;
    int k = n + ((n + 1) % 2);
    int m = k / 2 + 1;
    cout << m << endl;
    vector<pair<int, int>> ans;
    for (int i = 0; i < k - m; i++) {
        ans.push_back(make_pair(1, i + 1));
    }
    for (int i = 0; i < m; i++) {
        ans.push_back(make_pair(m, i + 1));
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}