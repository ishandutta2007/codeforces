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

int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

int nok(int a, int b) {
    return a * b / gcd(a, b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    if (b % a == 0) {
        cout << 0;
        return 0;
    }
    int d = b - a;
    if (a % d == 0) {
        cout << 0;
        return 0;
    }
    int ans = nok(a, b);
    int ans1 = 0;
    for (int i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            int e = i;
            int f = d / i;
            int ans2 = (a / e + 1) * e - a;
            if (nok(a + ans2, b + ans2) < ans) {
                ans = nok(a + ans2, b + ans2);
                ans1 = ans2;
            }
            ans2 = (a / f + 1) * f - a;
            if (nok(a + ans2, b + ans2) < ans) {
                ans = nok(a + ans2, b + ans2);
                ans1 = ans2;
            }
        }
    }
    cout << ans1;
    //cout << a + ans1 << " " << b + ans1;
    return 0;
}