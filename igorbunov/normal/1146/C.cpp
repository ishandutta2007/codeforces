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
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++) {
        int n;
        cin >> n;
        cout << "1 " << n - 1 << " ";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
        int ans;
        cin >> ans;
        int l = 1;
        int r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            cout << "1 " << m - l << " 1 ";
            for (int i = l; i < m; i++) {
                cout << i + 1 << " ";
            }
            cout << endl;
            int now;
            cin >> now;
            if (ans == now) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << "1 " << n - 1 << " ";
        cout << l + 1 << " ";
        for (int i = 0; i < l; i++){
            cout << i + 1 << " ";
        }
        for (int i = l + 1; i < n; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
        cin >> ans;
        cout << "-1 " << ans << endl;
    }
    return 0;
}