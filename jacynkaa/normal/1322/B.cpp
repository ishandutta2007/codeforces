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
//#define int long long

main()
{
    _upgrade;
    long long n;
    cin >> n;
    vector<int> X(n);
    rep(i, n) cin >> X[i];
    int odp = 0;
    int cur = 0;

    rep(b, 25)
    {
        long long ile = n * (n - 1);
        cur += (1 << b);
        vector<int> tmp;
        rep(i, n)
            tmp.push_back(X[i] & cur);
        sort(all(tmp));

        for (int a : X)
        {
            a = a & cur;
            auto q1 = lower_bound(all(tmp), (1 << b) - a);
            ile -= (q1 - tmp.begin());
            // what(ile);
            auto q2 = lower_bound(all(tmp), 2 * (1 << b) - a);
            auto q3 = lower_bound(all(tmp), 3 * (1 << b) - a);

            ile -= (q3 - q2);

            if (((a + a) & (1 << b)) == 0)
                ile++;
            //  what(ile);
        }
        if ((ile / 2) % 2 == 1)
            odp += (1 << b);
    }
    cout << odp << endl;
}