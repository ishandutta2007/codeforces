//  Codeforces Beta Round #25
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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

int N;
int g[1010][1010];
int vis[1010];

int R, roots[1010];
int E, as[1010], bs[1010];

void dfs(int u, int oy) {
    int v;
    vis[u] = 1;
    for (v = 1; v <= N; ++v) if (g[u][v] && v != oy) {
        if (vis[v]) {
            if (u < v) {
                as[E] = u;
                bs[E] = v;
                ++E;
            }
        } else {
            dfs(v, u);
        }
    }
}

int main() {
    int i;
    int u, v;
    
    N = in();
    for (i = 0; i < N - 1; ++i) {
        u = in();
        v = in();
        g[u][v] = g[v][u] = 1;
    }
    for (u = 1; u <= N; ++u) if (!vis[u]) {
        dfs(u, ~0);
        roots[R++] = u;
    }
    assert(E == R - 1);
    printf("%d\n", E);
    for (i = 0; i < E; ++i) {
        printf("%d %d %d %d\n", as[i], bs[i], roots[i], roots[E]);
    }
    
    return 0;
}