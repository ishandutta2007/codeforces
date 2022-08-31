//  UOI 2011.04.12.

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

uint xrand() {
    uint x = 314159265, y = 358979323, z = 846264338, w = 327950288;
    uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}

int uf[210];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

const Int INF = 3001001001001001001LL;

int N, M;
Int G, S;
int A[50010], B[50010], C[50010], D[50010];
int gglen, gg[50010];
pint ps[50010];
map<int,Int> mem;

Int calc(int g) {
    if (mem.count(g)) return mem[g];
    int k, i;
    int s = 0;
    int cnt = 1;
    memset(uf, ~0, N << 2);
    for (k = 0; k < M; ++k) {
        i = ps[k].second;
        if (C[i] <= g) {
            if (conn(A[i], B[i])) {
                s = D[i];
                if (++cnt == N) {
                    return mem[g] = G * g + S * s;
                }
            }
        }
    }
    return INF;
}

int main() {
    int i, j, k;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        G = in();
        S = in();
        for (i = 0; i < M; ++i) {
            A[i] = in() - 1;
            B[i] = in() - 1;
            C[i] = in();
            D[i] = in();
            gg[i] = C[i];
            ps[i] = mp(D[i], i);
        }
        
        Int ans = INF;
        Int sho[3] = { INF, INF, INF, };
        int jm[3];
        
        memset(uf, ~0, N << 2);
        for (i = 0; i < M; ++i) {
            conn(A[i], B[i]);
        }
        if (-uf[root(0)] != N) {
            goto failed;
        }
        
        sort(ps, ps + M);
        sort(gg, gg + M);
        gglen = unique(gg, gg + M) - gg;
        
        for (j = 19; j < gglen; j += 90) {
            Int tmp = calc(gg[j]);
            int jj = j;
            for (k = 0; k < 3; ++k) if (sho[k] > tmp) {
                swap(sho[k], tmp);
                swap(jm[k], jj);
            }
        }
        ans = sho[0];
        for (k = 0; k < 3; ++k) {
            for (j = jm[k] - 150 / (k + 1); j <= jm[k] + 150 / (k + 1); ++j) if (0 <= j && j < gglen) {
                chmin(ans, calc(gg[j]));
            }
        }
        for (j = 0; j < 200; ++j) if (0 <= j && j < gglen) {
            chmin(ans, calc(gg[j]));
        }
        for (j = M - 200; j < M; ++j) if (0 <= j && j < gglen) {
            chmin(ans, calc(gg[j]));
        }
        
        cout << ans << endl;
        continue;
    failed:;
        puts("-1");
    }
    
    return 0;
}