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

ostream &operator<<(ostream &out, string str)
{
    for (char c : str)
        out << c;
    return out;
}
template <class L, class R>
ostream &operator<<(ostream &out, pair<L, R> p)
{
    return out << "(" << p.st << ", " << p.nd << ")";
}
template <class T>
auto operator<<(ostream &out, T a) -> decltype(a.begin(), out)
{
    out << '{';
    for (auto it = a.begin(); it != a.end(); it = next(it))
        out << (it != a.begin() ? ", " : "") << *it;
    return out << '}';
}

void dump()
{
    cerr << "\n";
}
template <class T, class... Ts>
void dump(T a, Ts... x)
{
    cerr << a << ", ";
    dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#define int long long

const int MAXN = (int)2e6;

vector<vector<int>> G(MAXN);
vector<vector<int>> Gp(MAXN);
vector<int> Kp(MAXN);
vector<int> K(MAXN);
int grupa[MAXN];
bool NIE[MAXN];
map<pii, vector<pii>> E;

bool zle = false;

int n, m, k;

void dfs1(int x)
{
    for (int y : G[x])
    {
        if (K[y] == 0)
        {
            K[y] = K[x] ^ 1;
            dfs1(y);
            continue;
        }
        else
        {
            if (K[x] == K[y])
                NIE[grupa[x]] = true;
        }
    }
}

void dfs2(int x)
{
    for (auto v : Gp[x])
    {
        if (Kp[v] == 0)
        {
            Kp[v] = Kp[x] ^ 1;
            dfs2(v);
        }
        else
        {
            if (Kp[x] == Kp[v])
                zle = true;
        }
    }
}

pii par(int a, int b)
{
    return {max(a, b), min(a, b)};
}

void pre()
{
    cin >> n >> m >> k;
    rep(i, n)
    {
        cin >> grupa[i];
        grupa[i]--;
    }
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (grupa[a] == grupa[b])
        {
            G[a].push_back(b);
            G[b].push_back(a);
        }
        else
            E[par(grupa[a], grupa[b])].emplace_back(a, b);
    }
}

int32_t main()
{
    _upgrade;
    pre();
    int licznik = 4;
    rep(i, n)
    {
        if (K[i] == 0)
        {
            K[i] = licznik;
            licznik += 2;
            dfs1(i);
        }
    }
    int res = 0;
    rep(i, k) if (!NIE[i]) res += 1;
    res = (res * (res - 1) / 2);

    debug(res);

    for (auto &V : E)
    {
        if (NIE[V.st.st] || NIE[V.st.nd])
            continue;
        zle = false;
        for (auto &e : V.nd)
        {
            Gp[K[e.st]].push_back(K[e.nd]);
            Gp[K[e.nd]].push_back(K[e.st]);
            Gp[K[e.st]].push_back(K[e.st] ^ 1);
            Gp[K[e.nd]].push_back(K[e.nd] ^ 1);
        }

        for (auto &e : V.nd)
            if (Kp[K[e.st]] == 0)
            {
                Kp[K[e.st]] = 2;
                dfs2(K[e.st]);
            }
        for (auto &e : V.nd)
        {
            Kp[K[e.st]] = Kp[K[e.nd]] = Kp[K[e.st] ^ 1] = Kp[K[e.nd] ^ 1] = 0;
            Gp[K[e.st]].clear();
            Gp[K[e.nd]].clear();
        }

        //debug(V, zla);

        if (zle)
            res--;
    }
    cout << res << endl;
}