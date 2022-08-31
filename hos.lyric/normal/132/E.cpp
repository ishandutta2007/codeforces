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

namespace MCF {
    #define MAXN 10010
    #define MAXM 10010
    #define wint int
    #define cint int
    const wint wEPS = 0;
    const wint wINF = 1001001001;
    const cint cEPS = 0;
    const cint cINF = 1001001001;
    int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
    wint capa[MAXM], tof;
    cint cost[MAXM], toc, d[MAXN], pot[MAXN];
    int vis[MAXN], pree[MAXN];
    void init(int _n) {
        n = _n; m = 0; memset(ptr, ~0, n << 2);
    }
    void ae(int u, int v, wint w, cint c) {
        next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
        next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
    }
    bool spRep(int src, int ink, wint flo = wINF) {
        wint f;
        cint c, cc;
        int i, u, v;
        memset(pot, 0, n * sizeof(cint));
    //*
        for (bool cont = 1; cont; ) {
            cont = 0;
            for (u = 0; u < n; ++u) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
                if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
                    pot[zu[i]] = pot[u] + cost[i]; cont = 1;
                }
            }
        }
    //*/
        for (toc = 0, tof = 0; tof + wEPS < flo; ) {
            typedef pair<cint,int> node;
            priority_queue< node,vector<node>,greater<node> > q;
            for (u = 0; u < n; ++u) { d[u] = cINF; vis[u] = 0; }
            for (q.push(mp(d[src] = 0, src)); !q.empty(); ) {
                c = q.top().first; u = q.top().second; q.pop();
                if (vis[u]++) continue;
                for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
                    cc = c + cost[i] + pot[u] - pot[v = zu[i]];
                    if (d[v] > cc) { q.push(mp(d[v] = cc, v)); pree[v] = i; }
                }
            }
            if (!vis[ink]) return 0;
            f = flo - tof;
            for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; chmin(f, capa[i]); }
            for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
            tof += f;
            toc += f * (d[ink] - pot[src] + pot[ink]);
            for (u = 0; u < n; ++u) pot[u] += d[u];
        }
        return 1;
    }
}

#define MAX 1010

int N, M;
int A[MAX], C[MAX];

int E;
int as[MAX], bs[MAX], cs[MAX];
int es[MAX];
int ms[MAX];

bool used[MAX];

int ansLen;
string ans[MAX];

void addAns(int c, int a) {
    ostringstream os;
    os << (char)('a' + c) << "=" << a;
    ans[ansLen++] = os.str();
}
void addAns(int c) {
    ostringstream os;
    os << "print(" << (char)('a' + c) << ")";
    ans[ansLen++] = os.str();
}
void printAns(int val) {
    int i;
    printf("%d %d\n", ansLen, val);
    for (i = 0; i < ansLen; ++i) {
        puts(ans[i].c_str());
    }
}

int main() {
    int i, j;
    int e;
    int c;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        for (i = 0; i < N; ++i) {
            C[i] = __builtin_popcount(A[i]);
        }
        map<int,int> app;
        int sum = 0;
        E = 0;
        memset(es, ~0, sizeof(es));
        for (i = 0; i < N; ++i) {
            sum += C[i];
            if (app.count(A[i])) {
                j = app[A[i]];
                if (j + 1 == i) {
                    sum -= C[i];
                    es[j] = -2;
                } else {
                    as[E] = j + 1;
                    bs[E] = i;
                    cs[E] = -C[i];
                    es[j] = E;
                    ++E;
                }
            }
            app[A[i]] = i;
        }
//cout<<"sum = "<<sum<<endl;
//cout<<"as : ";pv(as,as+E);cout<<"bs : ";pv(bs,bs+E);
        MCF::init(N);
        for (i = 0; i < N - 1; ++i) {
            MCF::ae(i, i + 1, M - 1, 0);
        }
        for (e = 0; e < E; ++e) {
            ms[e] = MCF::m;
            MCF::ae(as[e], bs[e], 1, cs[e]);
        }
        MCF::spRep(0, N - 1, M - 1);
//cout<<"toc = "<<MCF::toc<<endl;
        
        memset(used, 0, sizeof(used));
        map<int,int> varName;
        ansLen = 0;
        for (i = 0; i < N; ++i) {
            if (varName.count(A[i])) {
                c = varName[A[i]];
            } else {
                for (c = 0; c < M; ++c) if (!used[c]) break;
                used[c] = 1;
                varName[A[i]] = c;
                addAns(c, A[i]);
            }
            addAns(c);
            if (es[i] == -1 || es[i] >= 0 && MCF::capa[ms[es[i]]]) {
                varName.erase(A[i]);
                used[c] = 0;
            }
        }
        printAns(sum + MCF::toc);
        
    }
    
    return 0;
}