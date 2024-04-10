const long long INFLL = 1e18;
const long long MOD = 998244353;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define uniq(x) sort(all(x)); x.resize(unique(all(x)) - (x).begin())

void solve()
{
    int len, n;
    cin >> len >> n;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];

    ll each_can_get = 0;
    {
        int L = 1, R = len + 1;
        while (L + 1 < R)
        {
            int M = (L + R) / 2;
            int lst = 0;
            int ok = 1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] - M >= lst)
                    lst = a[i];
                else
                {
                    lst = lst + M;
                    if (i + 1 < n && lst > a[i + 1])
                        ok = 0;
                    if (i + 1 == n && lst > len)
                        ok = 0;
                }
            }
            if (ok)
                L = M;
            else
                R = M;
        }
        each_can_get = L;
    }
    cerr << each_can_get << "\n";

    vector<int> when_gets(n);
    int lst = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - each_can_get >= lst)
        {
            lst = a[i];
            when_gets[i] = a[i];
        }
        else
        {
            lst = lst + each_can_get;
            when_gets[i] = lst;
        }
    }

    int L = each_can_get - 1, R = len;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        int pnt = len;
        int ok = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (pnt < a[i]) ok = 0;
            int give = pnt - a[i];
            pnt = a[i];
            if (give > M) ok = 0;
            int additional = M - give;
            if (i > 0) additional = min(additional, pnt - when_gets[i - 1]);
            else additional = min(additional, pnt);
            pnt -= additional;
        }
        if (ok && pnt == 0)
            R = M;
        else
            L = M;
    }

    cerr << R << "\n";

    vector<int> f(n), t(n);
    int pnt = len;
    for (int i = n - 1; i >= 0; i--)
    {
        t[i] = pnt;

        if (pnt < a[i]) exit(1);
        int give = pnt - a[i];
        pnt = a[i];
        if (give > R) exit(1);
        int additional = R - give;
        if (i > 0) additional = min(additional, pnt - when_gets[i - 1]);
        else additional = min(additional, pnt);
        pnt -= additional;

        f[i] = pnt;
    }
    for (int i = 0; i < n; i++)
        cout << f[i] << " " << t[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}