#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

struct SuffixAutomaton {
    static const int mxnd = mxn << 1;
    static const int sigma = 26;

    int tot, lst, go[mxnd][sigma], len[mxnd], link[mxnd];

    SuffixAutomaton(): tot(1), lst(1) { }

    void append(int c) {
        int p = lst, np = lst = ++ tot;
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
    }
} sam;

struct Node {
    int s, mx;
    Node *ls, *rs;

    void push_up() {
        s = (ls ? ls->s : 0) + (rs ? rs->s : 0);
        mx = max(ls ? ls->mx : 0, rs ? rs->mx : 0);
    }
} pool[mxn << 6], *ptr = pool;

Node *new_node() { return ptr ++; }
Node *new_node(Node *x) { *ptr = *x; return ptr ++; }

void insert(Node *&i, int a, int b, int x) {
    if (!i) i = new_node();
    if (a + 1 == b) { i->s = 1; i->mx = a; return ; }
    int m = (a + b) >> 1;
    if (x < m) insert(i->ls, a, m, x); else insert(i->rs, m, b, x);
    i->push_up();
}

int qry(Node *&i, int a, int b, int l, int r) {
    if (!i || r <= a || b <= l) return 0;
    if (l <= a && b <= r) return i->s;
    int m = (a + b) >> 1;
    int ansl = qry(i->ls, a, m, l, r), ansr = qry(i->rs, m, b, l, r);
    return ansl + ansr;
}

Node *merge(Node *a, Node *b) {
    if (!a || !b) return !a && !b ? nullptr : new_node(a ? a : b);
    Node *x = new_node();
    x->ls = merge(a->ls, b->ls);
    x->rs = merge(a->rs, b->rs);
    x->push_up();
    return x;
}

int n;
char s[mxn];
int ed[mxn << 1];
Node *rt[mxn << 1];
vector <int> adj[mxn << 1];
int dp[mxn << 1];
int stk[mxn << 1], top;

void dfs(int u) {
    if (ed[u] >= 0)
        insert(rt[u], 0, n, ed[u]);
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        dfs(v);
        rt[u] = merge(rt[u], rt[v]);
    }
}

void solve(int u) {
    dp[u] = dp[sam.link[u]];
    int ps = rt[u]->mx;
    int lb = 0, rb = top - 1;
    while (lb < rb) {
        int md = (lb + rb + 1) >> 1;
        int v = stk[md];
        int minlen = sam.len[sam.link[v]] + 1;
        int L = ps - sam.len[u] + 1 + minlen - 1;
        int R = ps + 1;
        if (qry(rt[v], 0, n, L, R) >= 2) lb = md;
        else rb = md - 1;
    }
    int ptr = lb;
    if (ptr < top) dp[u] = max(dp[u], dp[stk[ptr]] + 1);
    stk[top ++] = u;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        solve(v);
    }
    -- top;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    rep(i, n) sam.append(s[i] - 'a');
    memset(ed, -1, sizeof(ed));
    for (int i = 0, u = 1; i < n; ++ i) {
        u = sam.go[u][s[i] - 'a'];
        ed[u] = i;
    }
    for (int i = 2; i <= sam.tot; ++ i)
        adj[sam.link[i]].pb(i);
    dfs(1);
    solve(1);
    int ans = 0;
    for (int i = 1; i <= sam.tot; ++ i) ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}