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

string DAUN(string &b) {
    string ans;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] >= 'A' && b[i] <= 'Z') {
            ans.push_back(b[i] - 'A' + 'a');
        } else {
            ans.push_back(b[i]);
        }
    }
    return ans;
}

signed main() {
    cout << "Black";
}