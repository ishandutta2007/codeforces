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

//#define int long long


map<int, int> m;

signed main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int max1 = 0;
    int type1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
        if (m[arr[i]] > max1) {
            max1 = m[arr[i]];
            type1 = i;
        }
    }
    vector<pair<int, pair<int, int>>> ans;
    for (int i = type1 - 1; i >= 0; i--) {
        if (arr[i] == arr[i + 1]) {
            continue;
        }
        if (arr[i] > arr[i + 1]) {
            ans.push_back(make_pair(2, make_pair(i, i + 1)));
            //cout << 2 << " " << i + 1 << " " << i << endl;
        } else {
            ans.push_back(make_pair(1, make_pair(i, i + 1)));
            //cout << 1 << " " << i + 1 << " " << i << endl;
        }
        arr[i] = arr[i + 1];
    }
    for (int i = type1; i < arr.size() - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            continue;
        }
        if (arr[i] < arr[i + 1]) {
            ans.push_back(make_pair(2, make_pair(i + 1, i)));
            //cout << 2 << " " << i + 1 << " " << i << endl;
        } else {
            ans.push_back(make_pair(1, make_pair(i + 1, i)));
            //cout << 1 << " " << i + 1 << " " << i << endl;
        }
        arr[i + 1] = arr[i];
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second.first + 1 << " " << ans[i].second.second + 1 << endl;
    }
    return 0;
}