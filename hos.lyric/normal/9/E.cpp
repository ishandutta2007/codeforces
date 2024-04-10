//  Codeforces Beta Round #9
//  Problem E

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

int root(int p[], int x) {
    return (p[x] < 0) ? x : (p[x] = root(p, p[x]));
}
bool conn(int p[], int x, int y) {
    x = root(p, x); y = root(p, y);
    if (x == y) return 0;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y]; p[y] = x;
    return 1;
}

int N, M;
int uf[60], deg[60];

int main() {
    int i;
    int u, v;
    
    N = in();
    M = in();
    memset(uf, ~0, N << 2);
    for (i = 0; i < M; ++i) {
        u = in() - 1;
        v = in() - 1;
        ++deg[u];
        ++deg[v];
        if (deg[u] > 2 || deg[v] > 2) goto failed;
        if (!conn(uf, u, v)) {
            if (-uf[root(uf, u)] < N) goto failed;
        }
    }
    
    puts("YES");
    printf("%d\n", N - M);
    for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) for (int reps = 2; reps--; ) {
        ++deg[u];
        ++deg[v];
        if (deg[u] > 2 || deg[v] > 2) {
            --deg[u];
            --deg[v];
            continue;
        }
        if (!conn(uf, u, v)) {
            if (-uf[root(uf, u)] < N) {
                --deg[u];
                --deg[v];
                continue;
            }
        }
        printf("%d %d\n", u + 1, v + 1);
    }
    return 0;
    
failed:
    puts("NO");
    
    return 0;
}