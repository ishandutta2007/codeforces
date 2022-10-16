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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

struct BlackBox
{
    map<int32_t, int> M;

    bool operator<(BlackBox &b)
    {
        return M.size() < b.M.size();
    }

    void merge(BlackBox &B)
    {
        for (auto a : B.M)
            M[a.st] = M[a.st] + a.nd;
    }

    void operate(pii q)
    {
        int x = q.nd;
        auto z = M.upper_bound(q.st);
        auto hel = z;
        while (z != M.end())
        {
            if (z->nd <= x)
            {
                x -= z->nd;
                z++;
            }
            else
            {
                z->nd -= x;
                break;
            }
        }
        M.erase(hel, z);
        M[q.st] = M[q.st] + q.nd;
    }
    int get()
    {
        int x = 0;
        for (auto a : M)
            x += a.nd;
        return x;
    }
    void wypisz()
    {
        for (auto a : M)
        {
            what(a.st);
            what(a.nd);
        }
    }
};

const int MAXN = (1 << 17);
int indeks[MAXN];
pii owoc[MAXN];
BlackBox B[MAXN];
vector<int> G[MAXN];
int n, m, k;

void pre()
{
    rep(i, MAXN)
    {
        indeks[i] = i;
        owoc[i] = mp(2, -1);
    }
}

void wczytywanie()
{
    cin >> n >> m >> k;
    rep(i, n - 1)
    {
        int a;
        cin >> a;
        G[a].pb(i + 2);
    }
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        owoc[a] = mp(b, c);
    }
}

void dfs(int x)
{
    for (int y : G[x])
        dfs(y);
    for (int y : G[x])
        indeks[x] = (B[indeks[y]] < B[indeks[x]]) ? indeks[x] : indeks[y];
    for (int y : G[x])
        if (indeks[y] != indeks[x])
            B[indeks[x]].merge(B[indeks[y]]);

    if (owoc[x].nd != -1)
        B[indeks[x]].operate(owoc[x]);

    //cerr << "moj indeks: " << x << endl;
    //  B[indeks[x]].wypisz();
}

main()
{
    _upgrade;
    pre();
    wczytywanie();
    dfs(1);
    cout << B[indeks[1]].get() << endl;
}