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
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int count1 = 0;
    for (int i = s.size() - x; i < s.size(); i++) {
        if (s[i] == '1') {
            count1++;
        }
    }
    if (s[s.size() - 1 - y] == '1') {
        cout << count1 - 1;
    } else {
        cout << count1 + 1;
    }
}