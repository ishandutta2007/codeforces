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

const int MAXN = 1e6 + 15;

struct point {
    int x; int y;
};

point p[MAXN];

int v_pr(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

bool comp(point a, point b){
    if (a.x == b.x) {
        return a.y > b.y;
    }
    return a.x > b.x;
}

point operator -(point a, point b) {
    return (point){a.x - b.x, a.y - b.y};
}

int d[MAXN];


signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y - (long long)(x * x);
    }
    sort(p + 1, p + n + 1, comp);
    int ans = 1;
    d[ans] = 1;
    for (int i = 2; i <= n; i++){
        if (p[i].x == p[i - 1].x) {
            continue;
        }
        while (ans > 1 && v_pr(p[d[ans - 1]] - p[d[ans]], p[i] - p[d[ans]]) >=0 ) {
            ans--;
        }
        ans++;
        d[ans] = i;
    }
    cout << ans - 1 <<endl;
}