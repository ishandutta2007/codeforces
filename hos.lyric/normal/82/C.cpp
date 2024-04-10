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

#define MAX 10010

int N;
pint ps[MAX];
int m, ptr[MAX], next[MAX], zu[MAX], ca[MAX];
int par[MAX], pari[MAX];
int cs[MAX];
int pos[MAX];
int ans[MAX];

void dfs(int u, int p, int pi) {
    int i, v;
    par[u] = p;
    pari[u] = pi;
    for (i = ptr[u]; ~i; i = next[i]) {
        v = zu[i];
        if (v != p) {
            dfs(v, u, i >> 1);
        }
    }
}

int main() {
    int i, u, v;
    int j;
    int c;
    
    for (; ~scanf("%d", &N); ) {
        for (u = 0; u < N; ++u) {
            ps[u] = mp(in(), u);
        }
        sort(ps, ps + N);
//pvp(ps,ps+N);
        m = 0;
        memset(ptr, ~0, sizeof(ptr));
        for (i = 0; i < N - 1; ++i) {
            u = in() - 1;
            v = in() - 1;
            c = in();
            next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ca[i] = c; ++m;
            next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ca[i] = c; ++m;
        }
        dfs(0, -1, -1);
        for (u = 0; u < N; ++u) {
            pos[u] = u;
            ans[u] = -1;
        }
        for (i = 0; i <= N; ++i) {
//cout<<"pos: ";pv(pos,pos+N);
            for (u = 0; u < N; ++u) if (pos[u] == 0 && !~ans[u]) {
                ans[u] = i;
            }
            memset(cs, 0, N << 2);
            for (j = 0; j < N; ++j) {
                u = ps[j].second;
                v = pos[u];
//cout<<" move "<<u<<" (now "<<v<<")"<<endl;
                if (v != 0) {
                    if (cs[pari[v]] < ca[pari[v]]) {
//cout<<"  success"<<endl;
                        ++cs[pari[v]];
                        pos[u] = par[v];
                    }
                }
            }
        }
        for (u = 0; u < N; ++u) {
            if (u) putchar(' ');
            printf("%d", ans[u]);
        }
        puts("");
    }
    
    return 0;
}