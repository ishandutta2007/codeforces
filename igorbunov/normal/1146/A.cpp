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

//keldyshev

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
    string s;
    cin >> s;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            count1++;
        } else {
            count2++;
        }
    }
    while (count1 <= count2) {
        count2--;
    }
    cout << count1 + count2;
    return 0;
}