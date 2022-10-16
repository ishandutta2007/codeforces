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
#define endl '\n'

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal = 0;
    vector<pair<int, char>> arr(s.size());
    for (int i = 0; i < s.size(); i++) {
        arr[i].second = s[i];
        arr[i].first = i;
    }
    vector<pair<int, char>> now;
    vector<int> arr1(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            now.push_back(arr[i]);
        } else {
            int a = now.back().first;
            now.pop_back();
            arr1[i] = a;
        }
    }
    vector<int> ans(s.size());
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            bal++;
            if (bal % 2 == 0) {
                ans[i] = 0;
            } else {
                ans[i] = 1;
            }
        } else {
            bal--;
            ans[i] = ans[arr1[i]];
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }







}