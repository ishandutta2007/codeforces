//  Codeforces Beta Round #11
//  Problem D

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

int N, M, L;
int g[30][30];
Int dp[0x8000a][20];

int main() {
    int i, h, u, v, w;
    Int ans = 0;
    
    N = in();
    M = in();
    for (i = 0; i < M; ++i) {
        u = in() - 1;
        v = in() - 1;
        g[u][v] = g[v][u] = 1;
    }
    for (u = N; u--; ) {
        L = 1 << u;
        for (h = 0; h < L; ++h) for (v = 0; v <= u; ++v) {
            dp[h][v] = 0;
        }
        dp[0][u] = 1;
        for (h = 0; h < L; ++h) for (v = 0; v <= u; ++v) if (dp[h][v]) {
            for (w = 0; w < u; ++w) if (g[v][w] && !(h & 1 << w)) {
                dp[h | 1 << w][w] += dp[h][v];
            }
            if ((h & h - 1) && g[v][u]) {
                ans += dp[h][v];
            }
        }
    }
    cout << ans / 2 << endl;
    
    return 0;
}