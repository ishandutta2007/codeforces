#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int M = 3 * 1e5 + 1;
const int BIG = 2 * 1e9 + 1;
const ll INF = 2 * 1e18;
const ll MOD = 1e9 + 7;
const int two = 2;
const int four = 4;
const ld pi = acos(-1.0);
const ld eps = 1e-5;

ll power(ll x, int k)
{
    if (k == 0) return 1LL;
    ll t = power(x, k >> 1);
    t = (t * t) % MOD;
    if (k & 1) t = (t * x) % MOD;
    return t;
}

ll func(int y)
{
    return (power(2, y - 1));
}

int main()
{
    #ifndef ONLINE_JUDGE
    //*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/
    #endif // ONLINE_JUDGE
    int x, y;
    cin >> x >> y;
    if (y % x != 0)
    {
        cout << 0;
        return 0;
    }
    y /= x;
    ll ans = 0;
    vector<int> d;
    for (int i = 1; i * i <= y; i++)
        if (y % i == 0)
        {
            d.push_back(i);
            if (i * i != y)
                d.push_back(y / i);
        }
    sort(d.begin(), d.end());
    vector<int> dp(d.size());
    dp[(int)d.size() - 1] = 1;
    for (int i = (int)d.size() - 2; i >= 0; i--)
    {
        ll now = 0;
        now = func(y / d[i]);
        for (int j = i + 1; j < d.size(); j++)
            if (d[j] % d[i] == 0)
                now = (now - dp[j] + MOD) % MOD;
        dp[i] = now;
    }
    cout << dp[0];
    return 0;
}