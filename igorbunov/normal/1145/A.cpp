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

int arr[16];

bool check (int l, int r) {
    if (l > r) {
        return false;
    }
    for (int i = l; i < r; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int ans = 1;
void get(int l, int r) {
    if (r <= l) {
        return;
    }
    if (check(l, r)) {
        ans = max(ans, r - l + 1);
    }
    get(l, (l + r) / 2);
    get((l + r) / 2 + 1, r);
}


signed main() {
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
        cin >> arr[i];
   }
   get(0, n - 1);
   cout << ans;
}