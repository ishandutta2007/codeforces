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

const int MAXN = 1e6 + 15;

map<int, int> M;
int n;

int odp[3];

void pre()
{
    cin >> n;
    M.clear();
    rep(i, n)
    {
        int a;
        cin >> a;
        M[-a]++;
    }
    rep(i, 3)
        odp[i] = 0;
}

void solve()
{

    int ile = 0;
    for (auto P : M)
    {
        // cerr << P.st << " " << P.nd << endl;
        if (P.nd + ile > (n / 2))
            return;
        ile += P.nd;
        if (odp[0] == 0)
        {
            odp[0] = P.nd;
            continue;
        }
        if (odp[1] > odp[0])
        {
            odp[2] += P.nd;
            continue;
        }
        if (odp[1] <= odp[0])
        {
            odp[1] += P.nd;
            continue;
        }
    }
}

main()
{
    _upgrade;
    int T;
    cin >> T;
    while (T--)
    {
        pre();
        solve();
        if (odp[0] < odp[1] && odp[0] < odp[2])
            cout << odp[0] << " " << odp[1] << " " << odp[2] << endl;
        else
            cout << "0 0 0" << endl;
    }
}