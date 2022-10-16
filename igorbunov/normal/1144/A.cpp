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
    int q;
    cin >> q;
    for (int k = 0; k < q; k++) {
    bool flag = true;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int now = s[0] - 'a';
    for (int i = 1; i < s.size(); i++) {
        if (s[i] - 'a' != now + 1) {
            cout << "NO";
            flag = false;
            break;
        }
        now++;
    }
    if (flag) {
        cout << "YES";
    }
    cout << endl;
}
}