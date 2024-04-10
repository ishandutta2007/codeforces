#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<vector<int> > g;
int topsort = 0;
vector<int> B, E;

int cnt(int x)
{
    int ans = 0;
    while (x) {
        if (x & 1) {
            ++ans;
        }
        x >>= 1;
    }
    return ans;
}

void dfs(int v, int p)
{
    B[v] = topsort;
    ++topsort;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
    E[v] = topsort - 1;
}

struct node
{
    int promise;
    int b1, b2;
    node()
    {
        promise = 0;
        b1 = b2 = 0;
    }
};

vector<node> t;

void push(int v)
{
    if (!t[v].promise) {
        return;
    }
    int color = t[v].promise;
    t[v * 2].b1 = t[v * 2].b2 = t[v * 2 + 1].b1 = t[v * 2 + 1].b2 = 0;
    if (color <= 30) {
        t[v * 2].b1 = t[v * 2 + 1].b1 = 1 << color;
    } else {
        t[v * 2].b2 = t[v * 2 + 1].b2 = 1 << (color - 30);
    }
    t[v * 2].promise = color;
    t[v * 2 + 1].promise = color;
    t[v].promise = 0;
}

void update(int v, int tl, int tr, int l, int r, int color)
{
    if (tl == l && tr == r) {
        t[v].promise = color;
        t[v].b1 = t[v].b2 = 0;
        if (color <= 30) {
            t[v].b1 = 1 << color;
        } else {
            t[v].b2 = 1 << (color - 30);
        }
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update(v * 2, tl, tm, l, min(r, tm), color);
    }
    if (r > tm) {
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, color);
    }
    t[v].b1 = t[v * 2].b1 | t[v * 2 + 1].b1;
    t[v].b2 = t[v * 2].b2 | t[v * 2 + 1].b2;
}

pair<int, int> get(int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return mp(t[v].b1, t[v].b2);
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (r <= tm) {
        return get(v * 2, tl, tm, l, min(r, tm));
    }
    if (l > tm) {
        return get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    pair<int, int> a = get(v * 2, tl, tm, l, min(r, tm));
    pair<int, int> b = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return mp(a.first | b.first, a.second | b.second);
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> init(n);
    for (int i= 0; i < n; ++i) {
        scanf("%d", &init[i]);
    }

    g.resize(n);
    B.resize(n), E.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1);

    t.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        update(1, 0, n - 1, B[i], B[i], init[i]);
    }

    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int v, color;
            scanf("%d%d", &v, &color);
            --v;
            update(1, 0, n - 1, B[v], E[v], color);
        } else {
            int v;
            scanf("%d", &v);
            --v;
            pair<int, int> tmp = get(1, 0, n - 1, B[v], E[v]);
            int ans = cnt(tmp.first) + cnt(tmp.second);
            printf("%d\n", ans);
        }
    }

}