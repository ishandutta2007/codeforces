#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define bitcount(x) __builtin_popcountll(x)

ll sign(ll x)
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << "\n";

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<unsigned long long> mask(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> mask[i];
    }
    unsigned long long ans = 1;
    for (int i = 1; i < 62; i++)
    {
        ll s1 = 0, s2 = 0;
        ll f1 = 0, f2 = 0;
        unsigned long long p = (1ll << i);
        for (int j = 0; j < n; j++)
        {
            unsigned long long x = ans & mask[j];
            if (mask[j] < p)
            {
                s2 += a[j];
                if (bitcount(x) % 2 == 0) f2 += a[j];
                else f2 -= a[j];
            }
            else if (mask[j] < 2 * p)
            {
                s1 += a[j];
                if (bitcount(x) % 2 == 0) f1 += a[j];
                else f1 -= a[j];
            }
        }
//        cout << i << "\n";
//        cout << s1 << " " << s2 << "\n";
//        cout << f1 << " " << f2 << "\n";
        if (s1 + s2 > 0)
        {
            if (s2 - s1 < 0)
            {
                ans = p;
            }
            else if (f2 - f1 < 0)
            {
                ans += p;
            }
        }
        if (s1 + s2 < 0)
        {
            if (s2 - s1 > 0)
            {
                ans = p;
            }
            else if (f2 - f1 > 0)
            {
                ans += p;
            }
        }
    }
    assert(ans < (1ll << 63));
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s1 += a[i];
        s2 += a[i];
        if (bitcount(mask[i] & ans) % 2 == 1) s2 -= 2 * a[i];
    }
    cerr << s1 << " " << s2 << "\n";
    cout << ans;
}