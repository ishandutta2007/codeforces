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

vector<int> arr(200);

signed main() {
    int n;
    cin >> n;
    int min1 = 10000000;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        min1 = min(arr[i], min1);
    }
    cout << 2 + (arr[2] ^ min1);
}