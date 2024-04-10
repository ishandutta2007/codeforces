//  Codeforces Beta Round #80

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

namespace MF {
    #define MAXN 10010
    #define MAXM 1000010
    #define wint Int
    const wint wEPS = 0;
    const wint wINF = 1001001001001001001LL;
    int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
    wint capa[MAXM], tof;
    int lev[MAXN], see[MAXN], que[MAXN], *qb, *qe;
    void init(int _n) {
        n = _n; m = 0; memset(ptr, ~0, n << 2);
    }
    void ae(int u, int v, wint w0, wint w1 = 0) {
        next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w0; ++m;
        next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = w1; ++m;
    }
    wint augment(int src, int ink, wint flo) {
        if (src == ink) return flo;
        wint f;
        for (int &i = see[src]; ~i; i = next[i]) if (capa[i] > wEPS && lev[src] < lev[zu[i]]) {
            if ((f = augment(zu[i], ink, min(flo, capa[i]))) > wEPS) {
                capa[i] -= f; capa[i ^ 1] += f; return f;
            }
        }
        return 0;
    }
    bool dinic(int src, int ink, wint flo = wINF) {
        wint f;
        int i, u, v;
        for (tof = 0; tof + wEPS < flo; ) {
            qb = qe = que;
            memset(lev, ~0, n << 2);
            for (lev[*qe++ = src] = 0, see[src] = ptr[src]; qb != qe; ) {
                for (i = ptr[u = *qb++]; ~i; i = next[i]) if (capa[i] > wEPS && !~lev[v = zu[i]]) {
                    lev[*qe++ = v] = lev[u] + 1; see[v] = ptr[v];
                    if (v == ink) goto au;
                }
            }
            return 0;
        au: for (; (f = augment(src, ink, flo - tof)) > wEPS; tof += f);
        }
        return 1;
    }
}

const wint BIG = 1001001001001LL;

int N;
int M[310], A[310][310];
int W[310];

int main() {
    int i, u, v;
    
    for (; ~scanf("%d", &N); ) {
        for (u = 0; u < N; ++u) {
            M[u] = in();
            for (i = 0; i < M[u]; ++i) {
                A[u][i] = in() - 1;
            }
        }
        for (u = 0; u < N; ++u) {
            W[u] = in();
        }
        MF::init(2 + N * 2);
        for (u = 0; u < N; ++u) {
            MF::ae(0, 2 + u, BIG);
        }
        for (v = 0; v < N; ++v) {
            MF::ae(2 + N + v, 1, BIG);
        }
        for (u = 0; u < N; ++u) {
            for (i = 0; i < M[u]; ++i) {
                MF::ae(2 + u, 2 + N + A[u][i], BIG);
            }
        }
        int negSum = 0;
        for (u = 0; u < N; ++u) {
            if (W[u] >= 0) {
                MF::ae(2 + u, 1, W[u]);
            } else {
                MF::ae(0, 2 + u, -W[u]);
                negSum += W[u];
            }
        }
        MF::dinic(0, 1);
        int ans = MF::tof - BIG * N + negSum;
        printf("%d\n", ans);
    }
    
    return 0;
}