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

long long gcd(long long a, long long b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

long long NOK(long long a, long long b) {
    return a * b / gcd(a, b);
}

pair<long long, long long> solve(long long n, long long k, long long a, long long b) {
    long long s = a;
    long long l = (b - a + k + k + k + k + k) % k;
    long long min1 = 100000000000LL;
    long long max1 = -1000000LL;
    long long size1 = n * k;
    if (a == k || b == k) {
        return make_pair(min1, max1);
    }
    for (; l < n * k; l += k) {
        long long now;
        //cout << n * k << " " << l << endl;
        if (l == 0LL) {
            now = 1LL;
        } else {
            now = n * k / gcd(size1, l);
        }
        if (now < min1) {
            min1 = now;
        }
        if (now > max1) {
            max1 = now;
        }
    }
    return make_pair(min1, max1);
}

signed main() {
    long long n, k;
    cin >> n >> k;
    long long a, b;
    cin >> a >> b;
    long long ans1 = 1000000000000LL, ans2 = -1000LL;
    auto p = solve(n, k, a, b);
    ans1 = min(p.first, ans1);
    ans2 = max(p.second, ans2);
    p = solve(n, k, k - a, b);
    ans1 = min(p.first, ans1);
    ans2 = max(p.second, ans2);
    p = solve(n, k, a, k - b);
    ans1 = min(p.first, ans1);
    ans2 = max(p.second, ans2);
    p = solve(n, k, k - a, k - b);
    ans1 = min(p.first, ans1);
    ans2 = max(p.second, ans2);
    cout << ans1 << " " << ans2;
    return 0;
}