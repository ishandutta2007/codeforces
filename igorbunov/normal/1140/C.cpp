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
    int n, k;
    vector<pair<int, int>> a(300009);
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(), a.begin() + n);
    int ans = 0;
    int sum = 0;
    set<pair<int, int> > s;
    for(int i = n - 1; i >= 0; i--){
        s.insert(make_pair(a[i].second, i));
        sum += a[i].second;
        while(s.size() > k){
            auto it = s.begin();
            sum -= it->first;
            s.erase(it);
        }
        ans = max(ans, sum * a[i].first);
    }

    cout << ans << endl;

    return 0;
}