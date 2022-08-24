//  Codeforces Beta Round #14
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

int M, N;
char S[110][110];

int main() {
    int x, y;
    int p, q, r, s;
    
    M = in();
    N = in();
    for (x = 0; x < M; ++x) {
        scanf("%s", S[x]);
    }
    
    p = M;
    q = N;
    r = -1;
    s = -1;
    for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (S[x][y] == '*') {
        if (p > x) p = x;
        if (q > y) q = y;
        if (r < x) r = x;
        if (s < y) s = y;
    }
    
    for (x = p; x <= r; ++x) {
        for (y = q; y <= s; ++y) {
            putchar(S[x][y]);
        }
        puts("");
    }
    
    
    return 0;
}