#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define bitcount(x) __builtin_popcountll(x)

const int N = 2e7 + 2;
ll calc[N];

void solve()
{
    ll c, d, x;
    cin >> c >> d >> x;
    ll ans = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i != 0) continue;
        ll res = 0;
        {
            ll g = i;
            ll A = d + x / g;
            if (A % c == 0)
            {
                A /= c;
                res += calc[A];
            }
        }
        {
            ll g = x / i;
            ll A = d + x / g;
            if (A % c == 0)
            {
                A /= c;
                res += calc[A];
            }
        }
        if (i * i == x) res /= 2;
        ans += res;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << "\n";

    for (int i = 1; i < N; i++) calc[i] = 1;
    for (int i = 2; i < N; i++)
    {
        if (calc[i] == 1)
        {
            for (int j = i; j < N; j += i) calc[j] <<= 1;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}