//  Codeforces Beta Round #77

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

const Int INF = 1001001001001001001LL;

#define MAXN 1010
#define MAXM 2010

int N, M, S, T;
int m, ptr[MAXN], next[MAXM], zu[MAXM];
Int ca[MAXM];
Int E[MAXN], F[MAXN];
Int dist[MAXN][MAXN];

void dijkstra(int start, Int d[]) {
    int i, u, v;
    Int c, cc;
    typedef pair<Int,int> node;
    priority_queue< node,vector<node>,greater<node> > q;
    d[start] = 0;
    q.push(mp(0, start));
    for (; !q.empty(); ) {
        c = q.top().first;
        u = q.top().second;
        q.pop();
        if (d[u] != c) continue;
        for (i = ptr[u]; ~i; i = next[i]) {
            v = zu[i];
            cc = c + ca[i];
            if (d[v] > cc) {
                d[v] = cc;
                q.push(mp(cc, v));
            }
        }
    }
}

Int D[MAXN];

int main() {
    int i, u, v;
    Int c, cc;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        S = in() - 1;
        T = in() - 1;
        m = 0;
        memset(ptr, ~0, N << 2);
        for (i = 0; i < M; ++i) {
            u = in() - 1;
            v = in() - 1;
            c = in();
            next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ca[m] = c; ++m;
            next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ca[m] = c; ++m;
        }
        for (u = 0; u < N; ++u) {
            E[u] = in();
            F[u] = in();
        }
        
        memset(dist, 0x3f, sizeof(dist));
        memset(D, 0x3f, sizeof(D));
        for (u = 0; u < N; ++u) {
            dijkstra(u, dist[u]);
        }
//cout<<"dist : "<<endl;for(u=0;u<N;++u)pv(dist[u],dist[u]+N);
        
        Int ans = INF;
        typedef pair<Int,int> node;
        priority_queue< node,vector<node>,greater<node> > q;
        D[S] = 0;
        q.push(mp(0, S));
        for (; !q.empty(); ) {
            c = q.top().first;
            u = q.top().second;
            q.pop();
            if (D[u] != c) continue;
            if (u == T) {
                chmin(ans, c);
                break;
            }
            for (v = 0; v < N; ++v) {
                if (dist[u][v] <= E[u]) {
                    cc = c + F[u];
                    if (D[v] > cc) {
                        D[v] = cc;
                        q.push(mp(cc, v));
                    }
                }
            }
        }
        if (ans >= INF) ans = -1;
        cout << ans << endl;
    }
    
    return 0;
}