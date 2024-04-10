//  Codeforces Beta Round #14
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

void chmax(int &t, int f) { if (t < f) t = f; }

int N;
vector<vint> g;
int d[210], p[210];

void dfs(int u, int dep, int oy) {
    d[u] = dep;
    p[u] = oy;
    int o = g[u].size(), j;
    for (j = 0; j < o; ++j) if (g[u][j] != oy) {
        dfs(g[u][j], dep + 1, u);
    }
}

bool vis[210];

pint dfs2(int u) {
    pint ret = mp(0, 0);
    vis[u] = 1;
    int o = g[u].size(), j;
    for (j = 0; j < o; ++j) if (!vis[g[u][j]]) {
        pint tmp = dfs2(g[u][j]);
        ++tmp.first;
        chmax(ret.second, tmp.second);
        chmax(ret.second, ret.first + tmp.first);
        chmax(ret.first, tmp.first);
    }
    chmax(ret.second, ret.first);
    return ret;
}

int solve(int x, int y) {
//cout<<"solve "<<x<<" "<<y<<" : ";
    int path1 = 0;
    memset(vis, 0, sizeof(vis));
    for (; ; ++path1) {
        vis[x] = vis[y] = 1;
        if (x == y) break;
        (d[x] > d[y]) ? x = p[x] : y = p[y];
    }
    int u;
    int dai = 0;
    for (u = 0; u < N; ++u) if (!vis[u]) {
        chmax(dai, dfs2(u).second);
    }
//cout<<path1<<" "<<dai<<endl;
    return path1 * dai;
}

int main() {
    int i, u, v;
    int ans = 0;
    
    N = in();
    g = vector<vint>(N);
    for (i = 0; i < N - 1; ++i) {
        u = in() - 1;
        v = in() - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, d[0] = 0, p[0] = ~0);
    
    for (u = 0; u < N; ++u) for (v = 0; v < u; ++v) {
        chmax(ans, solve(u, v));
    }
    printf("%d\n", ans);
    
    return 0;
}