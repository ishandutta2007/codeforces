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

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> V(n);
    rep(i, n) cin >> V[i];
    sort(all(V));
    rep(i, n) if (V[i] == x)
    {
        cout << 1 << endl;
        return;
    }
    cout << max(((x + V.back() - 1) / V.back()), 2ll) << endl;
}
main()
{
    _upgrade;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}