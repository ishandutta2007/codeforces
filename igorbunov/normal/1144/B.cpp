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


signed main(){
    vector<int> arr1;
    vector<int> arr2;
    int n, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c % 2) {
            arr1.push_back(c);
        } else {
            arr2.push_back(c);
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int ans = 2000000000LL;
    if (arr1.size() < arr2.size()) {
        int now = 0;
        for (int i = 0; i < (int)arr2.size() - (int)arr1.size() - 1; i++) {
            now += arr2[i];
        }
        ans = min(ans, now);
    } else {
        int now = 0;
        for (int i = 0; i < (int)arr1.size() - (int)arr2.size() - 1; i++) {
            now += arr1[i];
        }
        ans = min(ans, now);
    }
    cout << ans;
}