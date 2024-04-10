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

const int MAXN = 1000000;
int n, arr[MAXN], ans[MAXN];
vector<pair<int, int>> a, b;

signed main() {
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    a.push_back(make_pair(-1, -1));
    b.push_back(make_pair(MAXN, -1));
    for(int i = 0; i < n; i++) {
        if(arr[i] <= a.back().first && arr[i] >= b.back().first) {
            cout << "NO";
            return 0;
        }
        if(arr[i] > a.back().first) {
            ans[i] = 0;
            a.push_back(make_pair(arr[i],i));
            continue;
        }
        if(a.back().first < b.back().first && a.back().second > b.back().second) {
            ans[a.back().second] = 1;
            b.push_back(a.back());
            a.pop_back();
        }
        if(arr[i] > a.back().first) {
            ans[i] = 0;
            a.push_back(make_pair(arr[i], i));
            continue;
        }
        if(arr[i] < b.back().first) {
            ans[i] = 1;
            b.push_back(make_pair(arr[i], i));
            continue;
        }
        cout << "NO";
        return 0;
    }
    cout << "YES \n";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}