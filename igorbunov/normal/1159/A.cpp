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
#include <deque>
#include <queue>
#include <set>
#include <map>

using namespace std;

//#define int long long
#define endl "\n"

int gcd(int a, int b) {
    if (!b) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int now = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        if (type == '+') {
            now++;
        } else {
            now--;
        }
        ans = min(now, ans);
    }
    cout << now - ans;
    return 0;
}