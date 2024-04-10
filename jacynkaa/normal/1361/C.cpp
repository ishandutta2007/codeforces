#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
#define PII pair<int, int>

const int MAXN = (1 << 20) + 100;

vector<PII> edges[MAXN];
vector<int> path;

int m, ind[MAXN], vis[MAXN];
void add_edge(int u, int v)
{
    edges[u].push_back(PII(v, m));
    edges[v].push_back(PII(u, m));
    vis[m++] = 0;
}

void dfs(int u)
{
    while (ind[u] < sz(edges[u]))
    {
        if (vis[edges[u][ind[u]].nd])
            ++ind[u]; // [U]
        else
        {
            vis[edges[u][ind[u]].nd] = 1;
            dfs(edges[u][ind[u]].st);
            path.push_back(u);
        }
    }
    if (path.empty() || path.back() != u)
        path.push_back(u);
}

void clear(int zakres = MAXN)
{
    rep(i, MAXN)
    {
        ind[i] = vis[i] = 0;
        edges[i].clear();
    }
    m = 0;
    path.clear();
}

int get(vector<pii> &X)
{
    int p = 0;
    int q = 20;
    while (p != q)
    {
        int k = (p + q + 1) / 2;
        bool qq = false;

        clear();

        int pot = ((1 << k) - 1);
        for (auto &e : X)
            add_edge(e.st & pot, e.nd & pot);

        rep(i, (1 << k)) if (sz(edges[i]) % 2)
        {
            qq = true;
            q = k - 1;
            break;
        }
        if (qq)
            continue;

        dfs(X[0].st & pot);

        //what(sz(path));
        //what(sz(X));
        if (sz(path) - 1 != sz(X))
        {
            q = k - 1;
            continue;
        }
        p = k;
    }
    return p;
}

map<pii, vector<pii>> M;
bool visited[MAXN];

void addM(pii p, pii idx, int pot)
{
    M[{p.st & pot, p.nd & pot}].push_back(idx);
    swap(p.st, p.nd);
    swap(idx.st, idx.nd);
    M[{p.st & pot, p.nd & pot}].push_back(idx);
}

pii getM(pii e)
{
    while (true)
    {
        auto res = M[e].back();
        M[e].pop_back();
        if (visited[res.st])
            continue;
        else
        {
            visited[res.st] = visited[res.nd] = true;
            return res;
        }
    }
}

int32_t main()
{
    _upgrade;
    int n;
    cin >> n;
    vector<pii> X(n);
    rep(i, n) cin >> X[i].st >> X[i].nd;
    int k = get(X);

    clear();

    int pot = ((1 << k) - 1);
    rep(i, n)
    {
        auto p = X[i];
        addM(p, {2 * i + 1, 2 * i + 2}, pot);
        add_edge(p.st & pot, p.nd & pot);
    }

    dfs(X[0].st & pot);

    cout << k << endl;
    rep(i, n)
    {
        auto p = getM({path[i], path[(i + 1) % n]});
        cout << p.st << " " << p.nd << " ";
    }
    cout << endl;
}