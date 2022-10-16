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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
        if (m[arr[i]] >= 3) {
            cout << "NO";
            return 0;
        }
    }
    sort(arr.begin(), arr.end());
    cout << "YES \n";
    cout << (arr.size() + 1) / 2 << endl;
    for (int i = 0; i < (int)arr.size(); i += 2) {
        cout << arr[i] << " ";
    }
    cout << endl << (int)arr.size() - ((int)arr.size() + 1) / 2 << endl;
    for (int i = (int)arr.size() - 1 - (int)arr.size() % 2; i >= 0; i -= 2) {
        cout << arr[i] << " ";
    }
    return 0;
}