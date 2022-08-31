#include <bits/stdc++.h>
using namespace std;

#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)

typedef long long ll;
const int N = 2111;
const int K = 3111;
int n;
int source[N], dest[N];

int ghash[10][10][10][10];
int g0s[K];
int g1s[K];
int g2s[K];
int g3s[K];
void init() {
    int k = 0;
    fr(g0,10) fe(g1,0,g0) fe(g2,0,g1) fe(g3,0,g2) {
        g0s[k] = g0;
        g1s[k] = g1;
        g2s[k] = g2;
        g3s[k] = g3;
        ghash[g0][g1][g2][g3] = k++;
    }
    // fprintf(stderr, "k = %d\n", k);
    assert(k < K);
}

int add(int gh, int f) {
    int g0 = g0s[gh];
    int g1 = g1s[gh];
    int g2 = g2s[gh];
    int g3 = f;
    assert(g3s[gh] == 0);
    if (g2 < g3) {
        swap(g2, g3);
        if (g1 < g2) {
            swap(g1, g2);
            if (g0 < g1) {
                swap(g0, g1);
            }
        }
    }
    assert(g0 >= g1 && g1 >= g2 && g2 >= g3);
    return ghash[g0][g1][g2][g3];
}
int rem(int gh, int f) {
    int g0 = g0s[gh];
    int g1 = g1s[gh];
    int g2 = g2s[gh];
    int g3 = g3s[gh];
    if (g0 == f) {
        g0 = g1; g1 = g2; g2 = g3; g3 = 0;
    } else if (g1 == f) {
        g1 = g2; g2 = g3; g3 = 0;
    } else if (g2 == f) {
        g2 = g3; g3 = 0;
    } else if (g3 == f) {
        g3 = 0;
    } else {
        assert(false);
    }
    assert(g3 == 0);
    assert(g0 >= g1 && g1 >= g2 && g2 >= g3);
    return ghash[g0][g1][g2][g3];

}

struct state {
    int i; char fl; int gh;
    bool has_avail() {
        return g3s[gh] == 0;
    }
    bool contains(int f) {
        return g0s[gh] == f || g1s[gh] == f || g2s[gh] == f || g3s[gh] == f;
    }
};


bool vis[N][10][K];
int solve() {
    vector<state> que;
    que.push_back({0, 1, 0});
    vis[0][1][0] = true;
    for (int ans = 1;; ans++) {
        vector<state> nque;
        for (state& s: que) {
            // printf("[d=%3d]... next=%d, at=%d [%d %d %d %d]\n", ans, s.i, s.fl, g0s[s.gh], g1s[s.gh], g2s[s.gh], g3s[s.gh]);
            // assert(1 <= s.fl && s.fl <= 9);
            // go up
            if (s.fl < 9) {
                state ns = {s.i, s.fl + 1, s.gh};
                // assert(1 <= ns.fl && ns.fl <= 9);
                if (!vis[ns.i][ns.fl][ns.gh]) {
                    vis[ns.i][ns.fl][ns.gh] = true;
                    nque.push_back(ns);
                    if (ns.i == n && ns.gh == 0) return ans;
                }
            }
            // assert(1 <= s.fl && s.fl <= 9);
            // go down
            if (s.fl > 1) {
                state ns = {s.i, s.fl - 1, s.gh};
                // assert(1 <= ns.fl && ns.fl <= 9);
                if (!vis[ns.i][ns.fl][ns.gh]) {
                    vis[ns.i][ns.fl][ns.gh] = true;
                    nque.push_back(ns);
                    if (ns.i == n && ns.gh == 0) return ans;
                }
            }
            // assert(1 <= s.fl && s.fl <= 9);
            // take
            if (s.i < n && s.has_avail() && source[s.i] == s.fl) {
                state ns = {s.i + 1, s.fl, add(s.gh, dest[s.i])};
                // assert(1 <= ns.fl && ns.fl <= 9);
                if (!vis[ns.i][ns.fl][ns.gh]) {
                    vis[ns.i][ns.fl][ns.gh] = true;
                    nque.push_back(ns);
                    if (ns.i == n && ns.gh == 0) return ans;
                }
            }
            // assert(1 <= s.fl && s.fl <= 9);
            // leave
            if (s.contains(s.fl)) {
                // assert(1 <= s.fl && s.fl <= 9);
                state ns = {s.i, s.fl, rem(s.gh, s.fl)};
                // assert(1 <= ns.fl && ns.fl <= 9);
                if (!vis[ns.i][ns.fl][ns.gh]) {
                    vis[ns.i][ns.fl][ns.gh] = true;
                    nque.push_back(ns);
                    if (ns.i == n && ns.gh == 0) return ans;
                }
            }
        }
        que = nque;
    }    
}
int main() {
    init();
    sf("%d", &n);
    fr(i,n) sf("%d%d", &source[i], &dest[i]);
    printf("%d\n", solve());
}