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

int N;
vector<vint> G;
int deg[3010];
int que[3010], *qb, *qe;

int par[3010];
int d[3010];

int main() {
    int i, u, v;
    
    for (; ~scanf("%d", &N); ) {
        G = vector<vint>(N, vint());
        for (i = 0; i < N; ++i) {
            u = in() - 1;
            v = in() - 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(deg, 0, sizeof(deg));
        for (u = 0; u < N; ++u) {
            deg[u] = G[u].size();
        }
        qb = qe = que;
        for (u = 0; u < N; ++u) {
            if (deg[u] == 1) {
                *qe++ = u;
            }
        }
        memset(par, ~0, sizeof(par));
        for (; qb != qe; ) {
            u = *qb++;
            for (uint j = 0; j < G[u].size(); ++j) {
                v = G[u][j];
                if (!~par[v]) {
                    par[u] = v;
                    --deg[v];
                    if (deg[v] == 1) {
                        *qe++ = v;
                    }
                }
            }
        }
        memset(d, 0, sizeof(d));
        for (int *q = qe; q-- != que; ) {
            u = *q;
            v = par[u];
            d[u] = d[v] + 1;
        }
        for (u = 0; u < N; ++u) {
            if (u) printf(" ");
            printf("%d", d[u]);
        }
        puts("");
    }
    
    return 0;
}