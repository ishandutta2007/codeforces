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
        rep(i, n)
        {
            cin >> X[i];
        }
        sort(all(X));
        cout << min(X[n - 2] - 1, n - 2) << endl;
    }
}