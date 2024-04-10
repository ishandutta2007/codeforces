//  Codeforces Beta Round #15
//  Problem A

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

int N, T;
int X[1010], A[1010];
set<int> ss;

void check(int xc) {
    int i;
    for (i = 0; i < N; ++i) {
        if (X[i] - A[i] < xc + T && xc - T < X[i] + A[i]) return;
    }
    ss.insert(xc);
}

int main() {
    int i;
    
    N = in();
    T = in();
    for (i = 0; i < N; ++i) {
        X[i] = in() * 2;
        A[i] = in();
    }
    for (i = 0; i < N; ++i) {
        check(X[i] - A[i] - T);
        check(X[i] + A[i] + T);
    }
    cout << ss.size() << endl;
    
    return 0;
}