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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAX 200010
char ANS[][110] = { "none", "at least one", "any" };

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
    int a, b, c;
    int id;
    int ans;
    bool operator<(const Edge &e) const {
        return (c < e.c);
    }
};

int N, M;
Edge es[MAX];

int usLen;
int us[MAX];
int ans[MAX];

int V;
int m, ptr[MAX], next[MAX], zu[MAX];

void init(int _V) {
    V = _V;
    m = 0;
    memset(ptr, ~0, V << 2);
}
void ae(int u, int v) {
    next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
    next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
}

int Z, dis[MAX], low[MAX], par[MAX], parE[MAX];
void dfs(int u, int p, int pE) {
    dis[u] = low[u] = Z++;
    par[u] = p;
    parE[u] = pE;
    int i, v;
    for (i = ptr[u]; ~i; i = next[i]) {
        v = zu[i];
        // if (v == p) continue;
        if (i == (pE ^ 1)) continue;
        if (~dis[v]) {
            chmin(low[u], dis[v]);
        } else {
            dfs(v, u, i);
            chmin(low[u], low[v]);
        }
    }
}
void dfss() {
    int u;
    Z = 0;
    memset(dis, ~0, V << 2);
    for (u = 0; u < V; ++u) if (!~dis[u]) dfs(u, -1, -1);
}
bool isBridge(int u, int v) {
    if (dis[u] > dis[v]) swap(u, v);
    return (u == par[v] && dis[v] <= low[v]);
}

int main() {
    int i, j, k;
    int u, v;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        for (i = 0; i < M; ++i) {
            es[i].a = in() - 1;
            es[i].b = in() - 1;
            es[i].c = in();
            es[i].id = i;
            es[i].ans = 0;
        }
        sort(es, es + M);
        memset(uf, ~0, N << 2);
        for (i = 0; i < M; i = j) {
            for (j = i; j < M && es[i].c == es[j].c; ++j);
            usLen = 0;
            for (k = i; k < j; ++k) {
                us[usLen++] = root(es[k].a);
                us[usLen++] = root(es[k].b);
            }
            sort(us, us + usLen);
            usLen = unique(us, us + usLen) - us;
// cout<<"weight : "<<es[i].c<<endl;
// cout<<"us : ";pv(us,us+usLen);
            init(usLen);
            for (k = i; k < j; ++k) {
                u = lower_bound(us, us + usLen, root(es[k].a)) - us;
                v = lower_bound(us, us + usLen, root(es[k].b)) - us;
                if (u != v) {
                    ae(u, v);
                }
            }
            dfss();
            for (k = i; k < j; ++k) {
                u = lower_bound(us, us + usLen, root(es[k].a)) - us;
                v = lower_bound(us, us + usLen, root(es[k].b)) - us;
                if (u != v) {
// cout<<" isBridge "<<u<<" "<<v<<" : "<<isBridge(u,v)<<endl;
                    es[k].ans = isBridge(u, v) ? 2 : 1;
                }
            }
            for (k = i; k < j; ++k) {
                conn(es[k].a, es[k].b);
            }
        }
        for (i = 0; i < M; ++i) {
            ans[es[i].id] = es[i].ans;
        }
        for (i = 0; i < M; ++i) {
            puts(ANS[ans[i]]);
        }
    }
    
    return 0;
}