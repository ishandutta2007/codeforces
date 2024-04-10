#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef unsigned short u16;

struct Ans {
    u16 cnt, id;

    Ans(): cnt(), id() {}
};

bool operator < (const Ans &a, const Ans &b) {
    return a.cnt != b.cnt ? a.cnt < b.cnt : a.id > b.id;
}

struct Node {
    Ans s;
    Node *ls, *rs;

    Node(): s(), ls(), rs() {}
} pool[33333333], *ptr = pool;

Node *new_node() {
    *ptr = Node();
    return ptr ++;
}

void ins(Node *&i, int a, int b, int x, int v) {
    if (!i) i = new_node();
    if (a + 1 == b) { i->s.id = x; i->s.cnt += v; return ; }
    int m = (a + b) >> 1;
    if (x < m) ins(i->ls, a, m, x, v);
    else ins(i->rs, m, b, x, v);
    i->s = max(i->ls ? i->ls->s : Ans(), i->rs ? i->rs->s : Ans());
}

Ans qry(Node *i, int a, int b, int l, int r) {
    if (!i) return Ans();
    if (r <= a || b <= l) return Ans();
    if (l <= a && b <= r) return i->s;
    int m = (a + b) >> 1;
    return max(qry(i->ls, a, m, l, r), qry(i->rs, m, b, l, r));
}

Node *merge(Node *a, Node *b, int l, int r) {
    if (!a || !b) {
        if (a || !b) return a;
        Node *x = new_node();
        x->s = b->s;
        x->ls = b->ls;
        x->rs = b->rs;
        return x;
    }
    Node *x = new_node();
    x->s = a->s;
    x->ls = a->ls;
    x->rs = a->rs;
    a = x;
    if (l + 1 == r) {
        a->s.cnt += b->s.cnt;
        return a;
    }
    int m = (l + r) >> 1;
    a->ls = merge(a->ls, b->ls, l, m);
    a->rs = merge(a->rs, b->rs, m, r);
    a->s = max(a->ls ? a->ls->s : Ans(), a->rs ? a->rs->s : Ans());
    return a;
}

const int mxn = 1111111;

struct SuffixAutomaton {
    static const int sigma = 26;

    int tot, lst, go[mxn][sigma], len[mxn], link[mxn];

    SuffixAutomaton() {
        tot = lst = 1;
        memset(go, 0, sizeof(go));
        memset(len, 0, sizeof(len));
        memset(link, 0, sizeof(link));
    }

    void append(int c) {
        int p = lst, np = ++ tot; lst = np;
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
                memcpy(go[nq], go[q], sizeof(go[q]));
                link[q] = link[np] = nq;
                for (; go[p][c] == q; p = link[p]) go[p][c] = nq;
            }
        }
    }
} sam;

int n, m, q;
char s[mxn], t[mxn];
int st[mxn], lt[mxn];
Node *rt[mxn];
vector <int> adj[mxn];
int fa[mxn][25];
int pre[mxn];

void dfs(int u) {
    rep(j, 25 - 1) fa[u][j + 1] = fa[fa[u][j]][j];
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        fa[v][0] = u;
        dfs(v);
        rt[u] = merge(rt[u], rt[v], 0, m);
    }
}

int get(int l, int r) {
    int u = pre[r];
    for (int j = 25 - 1; ~j; -- j)
        if (sam.len[fa[u][j]] >= r - l) u = fa[u][j];
    return u;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    rep(i, n) sam.append(s[i] - 'a');
    scanf("%d", &m);
    rep(i, m) {
        scanf("%s", t + st[i]);
        lt[i] = strlen(t + st[i]);
        sam.lst = 1;
        rep(j, lt[i]) sam.append(t[st[i] + j] - 'a');
        st[i + 1] = st[i] + lt[i];
    }
    for (int i = 2; i <= sam.tot; ++ i)
        adj[sam.link[i]].pb(i);
    rep(i, m) {
        int u = 1;
        rep(j, lt[i]) {
            u = sam.go[u][t[st[i] + j] - 'a'];
            // for (int v = u; v; v = sam.link[v])
            //     ins(rt[v], 0, m, i, 1);
            ins(rt[u], 0, m, i, 1);
        }
    }
    dfs(1);
    int u = 1;
    rep(i, n) {
        u = sam.go[u][s[i] - 'a'];
        pre[i + 1] = u;
    }
    scanf("%d", &q);
    while (q --) {
        int l, r, pl, pr;
        scanf("%d %d %d %d", &l, &r, &pl, &pr);
        -- l, -- pl;
        int u = get(pl, pr);
        Ans ans = qry(rt[u], 0, m, l, r);
        printf("%d %d\n", max(ans.id, u16(l)) + 1, ans.cnt);
    }
    return 0;
}