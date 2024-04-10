#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#include <chrono>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) \
    if (false)  \
        cerr << #x << " is " << x << endl;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
#define add 1
#define get 2

struct query
{
    int X, Y, typ, wierzcholek;

    query(int a, int b, int c, int d) : X(a), Y(b), typ(c), wierzcholek(d) {}
};

bool cmp(const query &B, const query &A)
{
    return B.X != A.X ? B.X < A.X : B.Y != A.Y ? B.Y < A.Y : B.typ != A.typ ? B.typ < A.typ : B.wierzcholek < A.wierzcholek;
}

const int MAXN = 100010;
const int LOG = 18;

vector<pii> G[MAXN];

bool taken[MAXN];
int sz[MAXN];
int depth[MAXN];
pii dist[LOG][MAXN];
int typ[LOG][MAXN];
int ancestor[LOG][MAXN];

vector<query> zapytania[MAXN];
indexed_set zbiory[MAXN];
long long ans = 0;

int n, l, w;

void update_sz(int u)
{
    taken[u] = 1;
    sz[u] = 1;
    for (auto P : G[u])
    {
        int v = P.st;
        if (!taken[v])
        {
            update_sz(v);
            sz[u] += sz[v];
        }
    }
    taken[u] = 0;
}

pii centroid(int u, int n)
{
    taken[u] = 1;
    pii r = pii(n - sz[u], u);
    for (auto P : G[u])
    {
        int v = P.st;
        if (!taken[v])
            r.st = max(r.st, sz[v]);
    }
    for (auto P : G[u])
    {
        int v = P.st;
        if (!taken[v])
            r = min(r, centroid(v, n));
    }
    taken[u] = 0;
    return r;
}
void fill_dist(int u, pii d, int layer, int ktora_czesc, int anc)
{
    taken[u] = 1;
    dist[layer][u] = d;
    typ[layer][u] = ktora_czesc;
    ancestor[layer][u] = anc;

    for (auto P : G[u])
    {
        int v = P.st;
        if (!taken[v])
            fill_dist(v, make_pair(d.st + 1, d.nd + P.nd), layer, (anc == u) ? ++ktora_czesc : ktora_czesc, anc);
    }
    taken[u] = 0;
}

void decompose(int u, int p, int layer)
{
    update_sz(u);
    int n = sz[u];
    u = centroid(u, n).nd;
    depth[u] = layer;
    fill_dist(u, mp(0, 0), layer, 1, u);
    taken[u] = 1;
    for (auto P : G[u])
    {
        int v = P.st;
        if (!taken[v])
            decompose(v, u, layer + 1);
    }
}

void fill_queries()
{
    rep(i, LOG) rep(j, n) if (ancestor[i][j] != -1)
    {
        int x = ancestor[i][j];

        what(i);
        what(j);
        what(x);

        zapytania[x].emplace_back(dist[i][j].st, dist[i][j].nd, add, j);
        zapytania[x].emplace_back(l - dist[i][j].st, w - dist[i][j].nd, get, j);
    }
}

void solve(int x)
{
    int cnt = 0;
    sort(all(zapytania[x]), cmp);

    rep(i, MAXN) if (zbiory[i].empty()) break;
    else zbiory[i].clear();

    for (auto q : zapytania[x])
    {
        int t = typ[depth[x]][q.wierzcholek];
        if (q.typ == add)
        {
            zbiory[0].insert(make_pair(q.Y, cnt));
            zbiory[t].insert(make_pair(q.Y, cnt));
        }
        else
        {
            int a = zbiory[0].order_of_key(make_pair(q.Y, cnt));
            int b = zbiory[t].order_of_key(make_pair(q.Y, cnt));
            ans += (a - b);
        }
        cnt++;
    }
}

void solve()
{
    fill_queries();
    rep(i, n) solve(i);
    cout << ans / 2 << endl; //bo kazda pare policzymy 2razy
}

void clear()
{
    rep(i, LOG) rep(j, MAXN) ancestor[i][j] = -1;
}

void input()
{
    cin >> n >> l >> w;
    rep(i, n - 1)
    {
        int a, c;
        cin >> a >> c;
        G[--a].emplace_back(i + 1, c);
        G[i + 1].emplace_back(a, c);
        what(i + 1);
        what(a);
    }
}

main()
{
    _upgrade;
    clear();
    input();
    decompose(0, 0, 0);
    solve();
}