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

#define MAXV 100010

int M;
int N;
int L[110];
char S[100010];
char T[110][1010];

int V;
int next[MAXV][30];
int fail[MAXV];
int que[MAXV], *qb, *qe;
int vis[MAXV];
int usLen, us[MAXV];

int rs[2][110][1010];

void bfs() {
    int u, e;
    qb = qe = que;
    *qe++ = 0;
    usLen = 0;
    for (; qb != qe; ) {
        u = *qb++;
        us[usLen++] = u;
        for (e = 0; e < 26; ++e) {
            int &v = next[u][e];
            if (~v) {
                fail[v] = u ? next[fail[u]][e] : 0;
                *qe++ = v;
            } else {
                v = u ? next[fail[u]][e] : 0;
            }
        }
    }
}

int main() {
    int i, u, e;
    int x;
    int j;
    int phase;
    
    for (; ~scanf("%s", S); ) {
        M = in();
        for (i = 0; i < M; ++i) {
            scanf("%s", T[i]);
        }
        N = strlen(S);
        for (i = 0; i < M; ++i) {
            L[i] = strlen(T[i]);
        }
        for (phase = 0; phase < 2; ++phase) {
            V = 1;
            memset(next, ~0, sizeof(next));
            for (i = 0; i < M; ++i) {
                u = 0;
                for (x = 0; x < L[i]; ++x) {
                    e = T[i][x] - 'A';
// if(!~next[u][e]){cout<<V<<" : "<<string(T[i]).substr(0,x+1)<<endl;}
                    if (!~next[u][e]) next[u][e] = V++;
                    u = next[u][e];
                }
            }
            bfs();
// cout<<"fail : ";pv(fail,fail+V);
            for (u = 0; u < V; ++u) {
                vis[u] = N + 1;
            }
            u = 0;
            for (x = 0; x <= N; ++x) {
                chmin(vis[u], x);
// cout<<"vis "<<u<<" : "<<x<<endl;
                if (x == N) break;
                e = S[x] - 'A';
                u = next[u][e];
            }
            for (j = usLen; --j; ) {
                u = us[j];
                chmin(vis[fail[u]], vis[u]);
            }
// cout<<"vis : ";pv(vis,vis+V);
            for (i = 0; i < M; ++i) {
                u = 0;
                for (x = 0; x <= L[i]; ++x) {
                    rs[phase][i][x] = vis[u];
                    if (x == L[i]) break;
                    e = T[i][x] - 'A';
                    u = next[u][e];
                }
            }
            
            //  reverse
            reverse(S, S + N);
            for (i = 0; i < M; ++i) {
                reverse(T[i], T[i] + L[i]);
            }
        }
        
        int ans = 0;
        for (i = 0; i < M; ++i) {
            bool ok = 0;
            for (x = 1; x < L[i]; ++x) {
                if (rs[0][i][x] + rs[1][i][L[i] - x] <= N) {
                    ok = 1;
                }
            }
            if (ok) {
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}