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

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int Q;
int N;
vint g[110];
int d[110];

void dfs(int u, int p, int c) {
    d[u] = c;
    for (unsigned j = 0; j < g[u].size(); ++j) {
        int v = g[u][j];
        if (v != p) {
            dfs(v, u, c + 1);
        }
    }
}

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    
    int i;
    int u, v;
    int um;
    
    for (; ~scanf("%d", &Q); ) {
        int ans = 0;
        for (; Q--; ) {
            N = in();
            for (u = 0; u < N; ++u) g[u].clear();
            for (i = 0; i < N - 1; ++i) {
                u = in() - 1;
                v = in() - 1;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            um = 0;
            for (int phase = 0; phase < 2; ++phase) {
                dfs(um, -1, 0);
                for (u = 0; u < N; ++u) if (d[um] < d[u]) um = u;
            }
            ans += d[um];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}