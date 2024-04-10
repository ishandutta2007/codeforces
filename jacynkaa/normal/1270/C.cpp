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

int cr(vector<int> &V)
{
    int a = 0;
    for (int b : V)
        a = a ^ b;
    return 2 * a;
}
int sm(vector<int> &V)
{
    int a = 0;
    for (int b : V)
        a = a + b;
    return a;
}

main()
{
    _upgrade;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> X(n);
        rep(i, n) cin >> X[i];

        int a = (1ll << 59) + (sm(X) % 2);
        X.push_back(a);

        int roznica = (cr(X) - sm(X)) / 2;
        int b = 0;
        what(roznica);

        rep(i, 60)
        {
            if (roznica & (1ll << i))
                b += (1ll << i);
        }
        X.push_back(b);
        X.push_back(b);
        cerr << cr(X) << " " << sm(X) << " " << cr(X) - sm(X) << endl;

        cout << 3 << endl;
        cout << a << " " << b << " " << b << endl;
    }
}