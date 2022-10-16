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

int ans[100005];

signed main() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 2; i <= n; i++) {
        if (!ans[i]) {
            c++;
            ans[i] = c;
            for (int j = i; j <= n; j += i) {
                ans[j] = c;
            }
        }
        cout << ans[i] << " ";
    }
    return 0;
}