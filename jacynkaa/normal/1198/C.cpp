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

const int MAXN = 3e5 + 1e5;
vector<pii> G[MAXN];
bool X[MAXN];
vector<int> krawedz;
int n, m;

void solve()
{
    rep(i, 3 * n)
    {
        bool wrzucac = true;
        for (auto y : G[i])
            if (X[y.st])
            {
                wrzucac = false;
                X[y.st] = false;
                krawedz.pb(y.nd);
                break;
            }
        if (wrzucac)
            X[i] = true;
    }
    if (krawedz.size() >= n)
    {
        cout << "Matching" << endl;
        rep(i, n)
                cout
            << krawedz[i] + 1 << " ";
        cout << endl;
    }
    else
    {
        cout << "IndSet" << endl;
        int j = 0;
        rep(i, 3 * n) if (X[i])
        {
            cout << i + 1 << " ";
            j++;
            if (j == n)
                break;
        }
        cout << endl;
    }
}

void czyszczenie()
{
    krawedz.clear();
    rep(i, 3 * n)
    {
        G[i].clear();
        X[i] = false;
    }
}
void wczytywanie()
{
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(mp(b, i));
        G[b].pb(mp(a, i));
    }
}

main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {

        cin >> n >> m;
        czyszczenie();
        wczytywanie();
        solve();
    }
}