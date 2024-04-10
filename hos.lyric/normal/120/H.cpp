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

namespace BM {
    #define MAXN0 210
    #define MAXN1 80010
    #define MAXM  16000000
    int n0, n1, m, ptr[MAXN0], next[MAXM], zu[MAXM];
    int to[MAXN0], fr[MAXN1], us[MAXN1], total;
    int lev[MAXN0], que[MAXN0], *qb, *qe;
    void init(int _n0, int _n1) {
        n0 = _n0; n1 = _n1; m = 0; memset(ptr, ~0, n0 << 2);
    }
    void ae(int u, int v) {
        next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
    }
    int augment(int u) {
        int i, v, w;
        us[u] = total;
        for (i = ptr[u]; ~i; i = next[i]) {
            if (!~(w = fr[v = zu[i]]) || us[w] != total && lev[u] < lev[w] && augment(w)) {
                to[u] = v; fr[v] = u; return 1;
            }
        }
        return 0;
    }
    int hopk() {
        int f, i, u, w;
        memset(to, ~0, n0 << 2); memset(fr, ~0, n1 << 2); memset(us, ~0, n1 << 2);
        for (total = 0; ; total += f) {
            qb = qe = que;
            memset(lev, ~0, n0 << 2);
            for (u = 0; u < n0; ++u) if (!~to[u]) lev[*qe++ = u] = 0;
            for (; qb != qe; ) for (i = ptr[u = *qb++]; ~i; i = next[i]) {
                if (~(w = fr[zu[i]]) && !~lev[w]) lev[*qe++ = w] = lev[u] + 1;
            }
            for (f = 0, u = 0; u < n0; ++u) if (!~to[u]) f += augment(u);
            if (!f) return total;
        }
    }
}

int N;
string S[210], T[210];
bool dones[210];

int V, VV;
string ss[80010];
map<string,int> tr;

int psLen[210];
int ps[210][80010];
int is[80010], si[80010];

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    
    char buf[110];
    int i, k;
    int h;
    int u;
    int flow;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            scanf("%s", buf);
            S[i] = buf;
        }
        flow = 0;
        memset(dones, 0, sizeof(dones));
        V = 0;
        tr.clear();
        set<string> forbidden;
        memset(psLen, 0, sizeof(psLen));
        for (i = 0; i < N; ++i) {
            if(false){//if (S[i].size() <= 4) {
                T[i] = S[i];
                dones[i] = 1;
                ++flow;
                if (!forbidden.insert(S[i]).second) {
                    goto failed;
                }
            } else {
                for (h = 0; h < 1 << S[i].size(); ++h) if (1 <= __builtin_popcount(h) && __builtin_popcount(h) <= 4) {
                    string s = "";
                    for (unsigned j = 0; j < S[i].size(); ++j) if (h & 1 << j) {
                        s += S[i][j];
                    }
                    if (forbidden.count(s)) continue;
                    if (!tr.count(s)) { ss[V] = s; tr[s] = V++; }
                    ps[i][psLen[i]++] = tr[s];
//cout<<i<<" "<<s<<endl;
                }
            }
        }
        memset(is, 0, sizeof(is));
        for (i = 0; i < N; ++i) if (!dones[i]) {
            sort(ps[i], ps[i] + psLen[i]);
            psLen[i] = unique(ps[i], ps[i] + psLen[i]) - ps[i];
            for (k = 0; k < psLen[i]; ++k) {
                --is[ps[i][k]];
            }
        }
//for(i=0;i<N;++i){cout<<"ps[i] : ";pv(ps[i],ps[i]+psLen[i]);}
        VV = 0;
        for (u = 0; u < V; ++u) if (is[u] != -1) {
            si[VV] = u;
            is[u] = VV++;
        }
        BM::init(N, VV);
        for (i = 0; i < N; ++i) if (!dones[i]) {
            for (k = 0; k < psLen[i]; ++k) {
                if (is[ps[i][k]] == -1) {
                    T[i] = ss[ps[i][k]];
                    dones[i] = 1;
                    ++flow;
                    break;
                }
            }
            if (k < psLen[i]) continue;
            for (k = 0; k < psLen[i]; ++k) {
                BM::ae(i, is[ps[i][k]]);
            }
        }
        flow += BM::hopk();
        if (flow < N) goto failed;
        for (i = 0; i < N; ++i) if (!dones[i]) {
            T[i] = ss[si[BM::to[i]]];
            dones[i] = 1;
        }
        for (i = 0; i < N; ++i) {
            puts(T[i].c_str());
        }
        continue;
    failed:;
        puts("-1");
    }
    
    return 0;
}