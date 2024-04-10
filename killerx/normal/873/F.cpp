#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct SuffixAutomata {
    static const int sigma = 26;

    int tot, lst;
    vector <int> len, link;
    vector <array <int, sigma> > go;
    vector <int> tms;
    vector <vector <int> > g;

    int newNode() {
        int x = ++ tot;
        len.pb(0);
        link.pb(0);
        go.pb(array <int, sigma> ());
        return x;
    }

    SuffixAutomata() {
        tot = 0;
        len.resize(1);
        link.resize(1);
        go.resize(1);
        lst = newNode();
    }

    void append(int c) {
        int p = lst;
        int np = newNode();
        lst = np;
        len[np] = len[p] + 1;
        for (; p && !go[p][c]; p = link[p]) go[p][c] = np;
        if (!p) link[np] = 1;
        else {
            int q = go[p][c];
            if (len[q] == len[p] + 1) link[np] = q;
            else {
                int nq = newNode();
                len[nq] = len[p] + 1;
                copy(go[q].begin(), go[q].end(), go[nq].begin());
                link[nq] = link[q];
                link[q] = link[np] = nq;
                for (; go[p][c] == q; p = link[p]) go[p][c] = nq;
            }
        }
    }

    void build() {
        tms.resize(tot + 1);
        g.resize(tot + 1);
        for (int i = 2; i <= tot; ++ i)
            g[link[i]].pb(i);
    }

    void dfs(int u) {
        rep(i, g[u].size()) dfs(g[u][i]), tms[u] += tms[g[u][i]];
    }
};

int main() {
    int n;
    static char s[200005], t[200005];
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    SuffixAutomata sam;
    rep(i, n) sam.append(s[i] - 'a');
    sam.build();
    int u = 1;
    rep(i, n) {
        u = sam.go[u][s[i] - 'a'];
        sam.tms[u] += !(t[i] - '0');
    }
    sam.dfs(1);
    ll ans = 0;
    for (int i = 1; i <= sam.tot; ++ i)
        ans = max(ans, 1LL * sam.len[i] * sam.tms[i]);
    printf("%lld\n", ans);
    return 0;
}