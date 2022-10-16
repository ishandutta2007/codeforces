//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#pragma GCC_OPTIMAZE("ofast")
#include <algorithm>
#include <iostream>
//#include <multiset>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
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
    for (int gg = 0; gg < q; gg++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 != l2) {
            cout << l1 << " " << l2 << endl;
            continue;
        }
        if (r1 != r2) {
            cout << r1 << " " << r2 << endl;
            continue;
        }
        cout << l1 << " " << l1 + 1 << endl;
    }
    return 0;
}