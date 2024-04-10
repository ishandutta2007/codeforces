//  Codeforces Beta Round #58 (D)

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

#define MAXN 110
#define MAXM 10010

int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
int zeit, dis[MAXN], fin[MAXN], low[MAXN], par[MAXN], dep[MAXN];

void dfsinfo(int u, int oy, int d) {

    dis[u] = low[u] = zeit++; par[u] = oy; dep[u] = d;

    int i, v;

    for (i = ptr[u]; ~i; i = next[i]) if ((v = zu[i]) != oy) {

        if (!~dis[v]) {

            dfsinfo(v, u, d + 1);

            low[u] = min(low[u], low[v]);

        } else {

            low[u] = min(low[u], dis[v]);

        }

    }

    fin[u] = zeit++;

}

void dfsinfos() {

    memset(dis, ~0, n << 2); zeit = 0;

    for (int u = 0; u < n; ++u) if (!~dis[u]) dfsinfo(u, ~0, 0);

}

bool isbridge(int u, int v) {

    if (dis[u] > dis[v]) swap(u, v);

    return (u == par[v] && dis[v] <= low[v]);

}


int N, M;
int A[MAXM];
int g[MAXN][MAXN];
int as[MAXM];
int deg[MAXN];

bool solve(int i0) {
    int i;
    int u, v;
if(0){
cout<<"solve "<<i0<<endl;
for(u=0;u<N;++u)pv(g[u],g[u]+N);
cout<<"====="<<endl;
}
    for (i = i0; i <= M; ++i) {
        n = N;
        m = 0;
        memset(ptr, ~0, n << 2);
        for (u = 0; u < N; ++u) for (v = u + 1; v < N; ++v) {
            for (int reps = g[u][v]; reps--; ) {
                next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
                next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
            }
        }
        dfsinfos();
        memset(deg, 0, n << 2);
        for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
            deg[u] += g[u][v];
        }
        u = as[i - 1];
        for (v = 0; v < N; ++v) if (g[u][v]) {
            if (i == i0 && v <= A[i]) continue;
//cout<<"try : v = "<<v<<endl;
            if (deg[u] > 1 && isbridge(u, v)) continue;
//cout<<"ok : v = "<<v<<endl;
            --g[u][v];
            --g[v][u];
            as[i] = v;
            break;
        }
        if (v == N) {
//cout<<"failed : i = "<<i<<endl;
            return 0;
        }
    }
    for (i = 0; i <= M; ++i) {
        if (i) putchar(' ');
        printf("%d", as[i] + 1);
    }
    puts("");
    return 1;
}

int main() {
    int i;
    
    N = in();
    M = in();
    for (i = 0; i <= M; ++i) {
        A[i] = in() - 1;
    }
    for (i = 0; i <= M; ++i) {
        as[i] = A[i];
    }
    for (i = M; i > 0; --i) {
        ++g[A[i - 1]][A[i]];
        ++g[A[i]][A[i - 1]];
        if (solve(i)) {
            return 0;
        }
    }
    puts("No solution");
    
    return 0;
}