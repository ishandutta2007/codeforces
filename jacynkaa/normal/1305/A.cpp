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

main()
{
    _upgrade;
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> X(n);
        vector<int> Y = X;
        rep(i, n) cin >> X[i];
        rep(i, n) cin >> Y[i];
        sort(all(X));
        sort(all(Y));
        rep(i, n) cout << X[i] << " ";
        cout << endl;
        rep(i, n) cout << Y[i] << " ";
        cout << endl;
    }
}