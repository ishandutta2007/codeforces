//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")*/
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
#define endl "\n"

bool check(int x) {
    bool b = 1;
    for (int i = 0; i < 25; i++) {
        if ((x & (1 << i)) == 0) {
            //cout << 0;
            b = 0;
        } else {
            //cout << 1;
            if (!b) {
                return false;
            }
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    vector<int> arr(25);
    for (int i = 0; i < 25; i++) {
        if (x & (1 << i) != 0) {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
    int count1 = 0;
    vector<int> ans;
    while (!check(x) && count1 < 100) {
        bool b = 0;
        for (int i = 0; i < 25; i++) {
            if ((x & (1 << i)) != 0) {
                x ^= ((1 << (i)) - 1);
                ans.push_back(i);
                break;
            }
        }
        count1++;
        if (check(x)) {
            break;
        }
        x++;
        count1++;
    }
    cout << count1 << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}