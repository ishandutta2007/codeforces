// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int q;
inline ll Get(ll n)
{
    ll pw = 1, res = 0;
    while (n >= 9)
        n -= 9, res += pw * 9, pw *= 10LL;
    res += n * pw;
    return (res);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        ll n, k;
        cin >> n >> k;
        k ++;
        ll Mn = (ll)2e18 + 10;
        {
            // type 1 :
            ll targ = n - k * (k - 1) / 2;
            if (targ >= 0 && targ % k == 0)
            {
                targ /= k;
                for (int d = 0; d + k <= 10; d ++)
                    if (targ - d >= 0)
                        Mn = min(Mn, Get(targ - d) * 10 + d);
            }
        }
        {
            // type 2 :
            for (int i = 1; i <= k; i ++)
                for (int len = 1; len < 18; len ++)
                    for (int d = 0; d < 9; d ++)
                    {
                        ll base = d * k + (k - i) + len * 9 * i - i * (i - 1) / 2 + (k - i) * (k - i - 1) / 2;
                        ll targ = n - base;
                        if (targ % k != 0 || targ < 0)
                            continue;
                        targ /= k;
                        ll m = Get(targ);
                        m = m * 10 + d;
                        for (int j = 1; j <= len; j ++)
                            m = m * 10 + 9;
                        m -= i - 1;
                        Mn = min(Mn, m);
                    }
        }
        if (Mn >= (ll)(2e18))
            Mn = -1;
        printf("%lld\n", Mn);
    }
    return 0;
}