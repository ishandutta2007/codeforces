#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

mt19937 gen(time(0));

struct node {
    int cnt, x, y;
    node* l;
    node* r;
    node() {}
    node(int x) : cnt(1), x(x), y(gen()), l(nullptr), r(nullptr) {}
};

typedef node* pnode;

void update(pnode t) {
    t->cnt = 1;
    if (t->l) t->cnt += t->l->cnt;
    if (t->r) t->cnt += t->r->cnt;
}

pnode merge(pnode a, pnode b) {
    if (!a) return b;
    if (!b) return a;
    if (a->y < b->y) {
        a->r = merge(a->r, b);
        update(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        update(b);
        return b;
    }
}

pair<pnode, pnode> split(pnode t, int x) {
    if (!t) return {nullptr, nullptr};
    if (t->x <= x) {
        auto res = split(t->r, x);
        t->r = res.fi;
        update(t);
        return {t, res.se};
    } else {
        auto res = split(t->l, x);
        t->l = res.se;
        update(t);
        return {res.fi, t};
    }
}

void insert(pnode& t, int x) {
    pnode A = new node(x);
    auto res = split(t, x);
    t = merge(res.fi, merge(A, res.se));
}

void erase(pnode& t, int x) {
    pnode L, M, R, U;
    tie(U, R) = split(t, x);
    tie(L, M) = split(U, x - 1);
    t = merge(L, merge(M->l, merge(M->r, R)));
}

ve<ve<pii>> qu;
ve<ve<int>> g;
ve<int> c;
ve<int> ans;
ve<map<int, int>> a;
ve<int> id;
ve<pnode> t;

void dfs(int v, int pr = -1) {
    id[v] = v;
    int j = -1;
    for (auto x : g[v]) {
        if (x != pr) {
            dfs(x, v);
            if (j == -1 || (sz(a[id[j]]) < sz(a[id[x]]))) j = x;
        }
    }
    if (j != -1) {
        id[v] = id[j];
    } else {
        t[v] = nullptr;
    }
    auto add = [&] (int c, int cnt) {
        if (a[id[v]].find(c) == a[id[v]].end()) a[id[v]][c] = 0;
        int p = a[id[v]][c];
        if (p) erase(t[id[v]], p);
        a[id[v]][c] += cnt;
        insert(t[id[v]], p + cnt);
    };
    add(c[v], 1);
    for (auto x : g[v]) {
        if (x != pr && x != j) {
            for (auto [c, cnt] : a[id[x]]) {
                add(c, cnt);
            }
        }
    }
    for (auto [x, ind] : qu[v]) {
        pnode L, R;
        tie(L, R) = split(t[id[v]], x - 1);
        ans[ind] = 0;
        if (R) ans[ind] = R->cnt;
        t[id[v]] = merge(L, R);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    qu.resize(n);
    c.resize(n);
    ans.resize(m);
    a.resize(n);
    t.resize(n);
    id.resize(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 0; i < m; i++) {
        int v, x;
        cin >> v >> x;
        v--;
        qu[v].pb({x, i});
    }
    dfs(0, -1);
    for (auto x : ans) {
        cout << x << " ";
    }
}