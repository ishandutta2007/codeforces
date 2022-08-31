//  Codeforces Beta Round #71

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

#define MAXL 100010

char S[MAXL];
int L, N;
char T[10][11];
int M[10];
int len[10], P[10][MAXL];

int solve(int ll) {
    int i, j;
    for (j = 0; j + ll <= L; ++j) {
        for (i = 0; i < N; ++i) {
            int pp = *lower_bound(P[i], P[i] + len[i], j);
            if (j <= pp && pp + M[i] <= j + ll) {
                break;
            }
        }
        if (i == N) return j;
    }
    return -1;
}

int main() {
    int i, j, k;
    
    for (; ~scanf("%s", S); ) {
        L = strlen(S);
        N = in();
        for (i = 0; i < N; ++i) {
            scanf("%s", T[i]);
            M[i] = strlen(T[i]);
        }
        memset(len, 0, sizeof(len));
        for (i = 0; i < N; ++i) {
            for (j = 0; j + M[i] <= L; ++j) {
                for (k = 0; k < M[i]; ++k) if (S[j + k] != T[i][k]) break;
                if (k == M[i]) P[i][len[i]++] = j;
            }
            P[i][len[i]++] = L + 1;
        }
        int lo = 0, ho = L + 1;
        for (; lo + 1 < ho; ) {
            int mo = (lo + ho) / 2;
            int tmp = solve(mo);
            ~tmp ? (lo = mo) : (ho = mo);
        }
        int ans = solve(lo);
        printf("%d %d\n", lo, ans);
    }
    
    return 0;
}