//  Codeforces Beta Round #86

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

namespace SA {
    #define MAXN 2010
    int n;
    char t[MAXN];
    int ki[MAXN], ik[MAXN], is[MAXN], hh;
    bool cmp(const int &a, const int &b) {
        return (a == b) ? 0 : (ik[a] != ik[b]) ? (ik[a] < ik[b]) : (ik[a + hh] < ik[b + hh]);
    }
    void makesa() {
        n = strlen(t);
        int i;
        for (i = 0; i <= n; ++i) ik[ki[i] = i] = t[i];
        is[0] = is[n] = hh = 0;
        sort(ki, ki + n + 1, cmp);
        for (hh = 1; is[n] != n; hh <<= 1) {
            sort(ki, ki + n + 1, cmp);
            for (i = 0; i < n; ++i) is[i + 1] = is[i] + (cmp(ki[i], ki[i + 1]) ? 1 : 0);
            for (i = 0; i <= n; ++i) ik[ki[i]] = is[i];
        }
    }
    int lcp[MAXN];
    void makeha() {
        int h = 0, i, j;
        for (i = 0; i < n; ++i) {
            for (j = ki[ik[i] - 1]; t[j + h] == t[i + h]; ++h);
            lcp[ik[i] - 1] = h;
            if (h) --h;
        }
    }
}

int L, M, N;
char A[2010], B[2010], C[2010];
int isB[2010], isC[2010];

int solve() {
    int i, j, x, y;
    int ret = 0;
    
    strcpy(SA::t, A);
    SA::makesa();
    SA::makeha();
    for (x = 1; x <= L; ++x) {
        y = SA::lcp[x - 1];
        i = SA::ki[x];
        for (j = i; j <= L; ++j) if (j - i > y) {
            if (j - i >= M && j - i >= N) {
                if (isB[i] && isC[j - N]) {
                    ++ret;
                }
            }
        }
    }
    
    return ret;
}

int main() {
    int i;
    
    for (; ~scanf("%s%s%s", A, B, C); ) {
        L = strlen(A);
        M = strlen(B);
        N = strlen(C);
        memset(isB, 0, sizeof(isB));
        memset(isC, 0, sizeof(isC));
        for (i = 0; i + M <= L; ++i) {
            if (!strncmp(A + i, B, M)) isB[i] = 1;
        }
        for (i = 0; i + N <= L; ++i) {
            if (!strncmp(A + i, C, N)) isC[i] = 1;
        }
        int res = solve();
        printf("%d\n", res);
    }
    
    return 0;
}