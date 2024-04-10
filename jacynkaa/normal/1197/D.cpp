#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl '\n'
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
#define int long long
#define double long double

double eps = 1e-3;

set<double> S[20];

double ulamek(int a, int b)
{
    return ((double)(a)) / (double)(b);
}

main()
{

    _upgrade;
    int n, m, k;
    cin >> n >> m >> k;
    double ans = 0.0;

    vector<double> X(n + 1, 0);
    rep(i, n)
    {
        cin >> X[i + 1];
        X[i + 1] -= ulamek(k, m);
    }
    rep(i, n)
    {
        X[i + 1] = X[i + 1] + X[i];
    }

    // rep(i, n + 1)
    //       cerr
    //   << i << " wartosc " << X[i] << endl;

    rep(i, n + 1)
    {
        rep(j, m) if (!S[j].empty())
        {
            int q = ((j - i + 2 * m * n) % m);
            ans = max(ans, X[i] - *S[j].begin() - ulamek(q * k, m));
        }

        S[i % m].insert(X[i]);
        //cerr << i << ": " << ans << endl;
    }
    //cerr << ans << endl;
    cout << (int)floor(ans + eps) << endl;
    return 0;
}