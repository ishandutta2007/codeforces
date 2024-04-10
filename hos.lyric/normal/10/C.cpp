//  Codeforces Beta Round #10
//  Problem C

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

int N;
Int is[10];

int main() {
    int i;
    int a, b;
    Int ans = 0, hik = 0;
    
    N = in();
    for (i = 1; i <= N; ++i) {
        ++is[i % 9];
        hik += N / i;
    }
    for (a = 0; a < 9; ++a) for (b = 0; b < 9; ++b) {
        ans += is[a] * is[b] * is[a * b % 9];
    }
    
    cout << ans - hik << endl;
    
    return 0;
}