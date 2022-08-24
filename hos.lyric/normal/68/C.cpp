//  Codeforces Beta Round #62

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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const int XLIM = 5;
const int INF = 1001001001;

int N;
int X[10][10], Y[10][10], A[10][10];
map<vint,int> mem[10][10];

int calc(int u, int v, vint s) {
    if (v == N) { ++u; v = u + 1; }
    if (v == N) return 0;
    if (!mem[u][v].count(s)) {
        int ret = -INF;
        int x = X[u][v], y = Y[u][v];
        int f;
        chmin(y, s[u]);
        if (v == N - 1) chmax(x, s[u]);
        for (f = x; f <= y; ++f) {
            vint t = s;
            t[u] -= f;
            t[v] += f;
            chmax(ret, (f ? (A[u][v] + f * f) : 0) + calc(u, v + 1, t));
        }
        mem[u][v][s] = ret;
    }
    return mem[u][v][s];
}

int main() {
    int i, u, v;
    int f;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N * (N - 1) / 2; ++i) {
            u = in() - 1;
            v = in() - 1;
            X[u][v] = in();
            Y[u][v] = in();
            A[u][v] = in();
        }
        for (u = 0; u < N; ++u) for (v = u + 1; v < N; ++v) {
            mem[u][v].clear();
        }
        for (f = 0; f <= XLIM * (N - 1); ++f) {
            vint start(N, 0);
            start[0] = f;
            int res = calc(0, 1, start);
            if (res >= 0) {
                printf("%d %d\n", f, res);
                goto found;
            }
        }
        puts("-1 -1");
    found:;
    }
    
    return 0;
}