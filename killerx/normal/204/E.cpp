#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
const int sigma = 26;

struct SuffixAutomaton {
    int tot;
    int go[mxn << 1][sigma];
    int len[mxn << 1];
    int link[mxn << 1];

    SuffixAutomaton(): tot(1) { }

    int append(int c, int las) {
        int p = las;
        int np = ++ tot;
        len[np] = len[p] + 1;
        for (; p && !go[p][c]; p = link[p]) go[p][c] = np;
        if (!p) link[np] = 1;
        else {
            int q = go[p][c];
            if (len[q] == len[p] + 1) link[np] = q;
            else {
                int nq = ++ tot;
                len[nq] = len[p] + 1;
                link[nq] = link[q];
                memcpy(go[nq], go[q], sigma << 2);
                link[q] = link[np] = nq;
                for (; go[p][c] == q; p = link[p]) go[p][c] = nq;
            }
        }
        return np;
    }
};

struct ExSuffixAutomaton {
    int tot;
    int go[mxn][sigma];
    SuffixAutomaton sam;
    int las[mxn];
    int vec[mxn];
    int vsz;

    void insert(char s[]) {
        int n = strlen(s);
        int u = 0;
        rep(i, n) {
            int &to = go[u][s[i] - 'a'];
            if (!to) to = ++ tot;
            u = to;
        }
    }

    void build() {
        las[0] = 1;
        vec[vsz ++] = 0;
        rep(i, vsz) {
            int u = vec[i];
            rep(c, sigma) {
                int v = go[u][c];
                if (v) {
                    las[v] = sam.append(c, las[u]);
                    vec[vsz ++] = v;
                }
            }
        }
    }
} sam;

/*
struct Graph {
    int tot;
    int head[mxn << 1];
    int nex[mxn << 1];
    int to[mxn << 1];

    void add_edge(int u, int v) {
        nex[++ tot] = head[u];
        to[tot] = v;
        head[u] = tot;
    }
} adj;
*/

struct Graph {
    vector <int> adj[mxn << 1];

    void add_edge(int u, int v) {
        adj[u].pb(v);
    }
} g;

struct Point {
    int x, y;

    Point(): x(), y() { }
    Point(int _x, int _y): x(_x), y(_y) { }

    bool operator < (const Point &oth) const {
        return x != oth.x ? x < oth.x : y < oth.y;
    }
};

struct Event {
    int x, i, v, tp;

    Event(): x(), i(), v(), tp() { }
    Event(int _x, int _i, int _v, int _tp): x(_x), i(_i), v(_v), tp(_tp) { }

    bool operator < (const Event &oth) const {
        return x != oth.x ? x < oth.x : i < oth.i;
    }
};

struct BIT {
    int s[mxn << 1];

    void upd(int x, int v) { for (++ x; x < (mxn << 1); x += x & -x) s[x] += v; }
    int qry(int x) { int ans = 0; for (++ x; x; x -= x & -x) ans += s[x]; return ans; }
} bit;

int n, lim;
char s[mxn];
int st[mxn];
int sl[mxn];
int dfn[mxn << 1];
int ed[mxn << 1];
int vec[mxn];
int vsz;
Point pnts[mxn];
int psz;
Event evts[mxn << 2];
int esz;
int ans[mxn << 1];

void dfs(int u) {
    static int tim;
    dfn[u] = tim ++;
    rep(i, g.adj[u].size()) {
        int v = g.adj[u][i];
        dfs(v);
    }
    ed[u] = tim;
}

void dfs1(int u) {
    rep(i, g.adj[u].size()) {
        int v = g.adj[u][i];
        ans[v] += ans[u];
        dfs1(v);
    }
}

int main() {
//  freopen("c.in", "r", stdin);
//  freopen("c.out", "w", stdout);
    scanf("%d %d", &n, &lim);
    rep(i, n) {
        scanf("%s", s + st[i]);
        sl[i] = strlen(s + st[i]);
        sam.insert(s + st[i]);
        st[i + 1] = st[i] + sl[i];
    }
    sam.build();
    rep(i, sam.sam.tot + 1) if (sam.sam.link[i])
        g.add_edge(sam.sam.link[i], i);
    dfs(1);
    rep(i, n) {
        int u = 1;
        vsz = 0;
        rep(j, sl[i]) {
            u = sam.sam.go[u][s[st[i] + j] - 'a'];
            vec[vsz ++] = dfn[u];
        }
        sort(vec, vec + vsz);
        rep(j, vsz) {
            pnts[psz ++] = Point(vec[j], j ? vec[j - 1] : -1);
        }
    }
    sort(pnts, pnts + psz);
    rep(i, sam.sam.tot + 1) if (i) {
        evts[esz ++] = Event(dfn[i], i, dfn[i], -1);
        evts[esz ++] = Event(ed[i], i, dfn[i], +1);
    }
    sort(evts, evts + esz);
    for (int i = 0, p = 0, q = 0; i <= ed[1]; ++ i) {
        while (q < esz && evts[q].x <= i) {
            ans[evts[q].i] += evts[q].tp * bit.qry(evts[q].v);
            ++ q;
        }
        while (p < psz && pnts[p].x <= i) {
            bit.upd(pnts[p].y + 1, +1);
            ++ p;
        }
    }
    rep(i, sam.sam.tot + 1) if (i) {
        ans[i] = ans[i] >= lim ? sam.sam.len[i] - sam.sam.len[sam.sam.link[i]] : 0;
    }
    dfs1(1);
    rep(i, n) {
        int u = 1;
        ll res = 0;
        rep(j, sl[i]) {
            u = sam.sam.go[u][s[st[i] + j] - 'a'];
            res += ans[u];
        }
        printf("%lld%c", res, " \n"[i + 1 == n]);
    }
    return 0;
}