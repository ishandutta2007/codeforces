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
    cout << "BucketPotato";
}