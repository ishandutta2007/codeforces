#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll inq(ll x, ll y)
{
    if (y == 0) return 1;
    ll l = inq(x, y / 2);
    l = l * l % MOD;
    if (y % 2) return l * x % MOD;
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    m = accumulate(a.begin(), a.end(), 0);
    if (*max_element(a.begin(), a.end()) == m)
    {
        cout << 0;
        return 0;
    }
    vector<int> tm(m);
    tm[0] = n - 1;
    for (int i = 1; i < m; i++)
    {
        int avg_time = (1ll * (m - i) * inq(m, MOD - 2) % MOD + (1ll + tm[i - 1]) * i % MOD * inq(m, MOD - 2)) % MOD;
        int avg_cnt = 1ll * m * inq(m - i, MOD - 2) % MOD * (n - 1) % MOD;
        tm[i] = 1ll * avg_cnt * avg_time % MOD;
        //cout << avg_cnt << " " << avg_time << endl;
    }
    for (int i = m - 2; i >= 0; i--)
    {
        tm[i] = (tm[i] + tm[i + 1]) % MOD;
    }
    int si = 0;
    for (int i = 0; i < n; i++)
    {
        si = (si + tm[a[i]]) % MOD;
    }
    //cout << tm[0] << " " << tm[1] << endl;
    si = (si - 1ll * tm[0] * (n - 1)) % MOD;
    si = (si + MOD) % MOD;
    cout << 1ll * si * inq(n, MOD - 2) % MOD;
}