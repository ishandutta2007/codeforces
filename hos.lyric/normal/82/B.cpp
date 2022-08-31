//  Yandex.Algorithm 2011 Qual 2

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

#define MAX 410
const int LIM = 205;

int uf[MAX];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

int N;
int K[20010], A[20010][MAX];
vint app[MAX];
vint sets[MAX];

int T;
map<vint,int> tr;

int main() {
    int i, j;
    int u;
    int k;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N * (N - 1) / 2; ++i) {
            K[i] = in();
            for (j = 0; j < K[i]; ++j) {
                u = in();
                A[i][j] = u;
            }
        }
        if (N == 2) {
            printf("%d %d\n", 1, A[0][0]);
            printf("%d", K[0] - 1);
            for (j = 1; j < K[0]; ++j) {
                printf(" %d", A[0][j]);
            }
            puts("");
            continue;
        }
        for (u = 0; u < LIM; ++u) {
            app[u].clear();
        }
        for (i = 0; i < N * (N - 1) / 2; ++i) {
            for (j = 0; j < K[i]; ++j) {
                u = A[i][j];
                app[u].push_back(i);
            }
        }
        for (k = 0; k < N; ++k) {
            sets[k].clear();
        }
        T = 0;
        for (u = 0; u < LIM; ++u) if (!app[u].empty()) {
            if (!tr.count(app[u])) {
                tr[app[u]] = T++;
            }
            sets[tr[app[u]]].push_back(u);
        }
//assert(T==N);
        for (k = 0; k < N; ++k) {
            printf("%d", sets[k].size());
            for (uint l = 0; l < sets[k].size(); ++l) {
                printf(" %d", sets[k][l]);
            }
            puts("");
        }
    }
    
    return 0;
}