//  Codeforces Beta Round #73

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

#define MAX 200010

int uf[MAX];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

struct Edge {
    int c, a, b, id;
    bool operator<(const Edge &o) const {
        return (c < o.c);
    }
};

int N;
Edge es[MAX];

int V, flg[MAX], tr[MAX];
int E, ptr[MAX], next[MAX], zu[MAX], num[MAX];
int vis[MAX];
Int sz[MAX], sum[MAX];
Int ans[MAX];

void dfs0(int u, int p) {
    int i, v;
    vis[u] = 1;
    sum[u] = sz[u];
    for (i = ptr[u]; ~i; i = next[i]) if ((v = zu[i]) != p) {
        dfs0(v, u);
        sum[u] += sum[v];
    }
}
void dfs1(int u, int p, Int tot) {
    int i, v;
    for (i = ptr[u]; ~i; i = next[i]) if ((v = zu[i]) != p) {
        ans[num[i]] = sum[v] * (tot - sum[v]) * 2;
        dfs1(v, u, tot);
    }
}
void solve() {
    int u;
    memset(vis, 0, V << 2);
    for (u = 0; u < V; ++u) if (!vis[u]) {
        dfs0(u, -1);
        dfs1(u, -1, sum[u]);
    }
}

int main() {
    int i, j, k;
    int u, v;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N - 1; ++i) {
            es[i].a = in() - 1;
            es[i].b = in() - 1;
            es[i].c = in();
            es[i].id = i;
        }
        sort(es, es + N - 1);
        memset(uf, ~0, N << 2);
        memset(flg, ~0, sizeof(flg));
        memset(ans, 0, sizeof(ans));
        for (i = 0; i < N - 1; i = j) {
            for (j = i; j < N - 1 && es[i].c == es[j].c; ++j);
            V = 0;
            E = 0;
            for (k = i; k < j; ++k) {
                u = root(es[k].a);
                v = root(es[k].b);
                if (flg[u] != i) { flg[u] = i; sz[V] = -uf[u]; tr[u] = V++; }
                if (flg[v] != i) { flg[v] = i; sz[V] = -uf[v]; tr[v] = V++; }
            }
//cout<<"V = "<<V<<endl;
//cout<<"sz : ";pv(sz,sz+V);
            memset(ptr, ~0, V << 2);
            for (k = i; k < j; ++k) {
                u = root(es[k].a);
                v = root(es[k].b);
                u = tr[u];
                v = tr[v];
//cout<<"ae "<<u<<" "<<v<<endl;
                next[E] = ptr[u]; ptr[u] = E; zu[E] = v; num[E] = es[k].id; ++E;
                next[E] = ptr[v]; ptr[v] = E; zu[E] = u; num[E] = es[k].id; ++E;
            }
            solve();
            for (k = i; k < j; ++k) {
                conn(es[k].a, es[k].b);
            }
        }
//pv(ans,ans+N-1);
        Int dai = 0;
        for (i = 0; i < N - 1; ++i) {
            chmax(dai, ans[i]);
        }
        int cnt = 0;
        for (i = 0; i < N - 1; ++i) {
            if (dai == ans[i]) ++cnt;
        }
        cout << dai << " " << cnt << endl;
        int ou = 0;
        for (i = 0; i < N - 1; ++i) {
            if (dai == ans[i]) {
                if (ou++) putchar(' ');
                printf("%d", i + 1);
            }
        }
        puts("");
    }
    
    return 0;
}