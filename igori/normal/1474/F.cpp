#include <bits/stdc++.h>

const long long MOD = 998244353;

using namespace std;

typedef long long ll;

vector<ll> binpow(int len, ll deg)
{
    if (deg == 1) return vector<ll>(len, 1);
    vector<ll> part = binpow(len, deg / 2);
    vector<ll> whole(len);

    auto D = [&](int i, int j){
        assert(i <= j);
        if (i % 2 == 0) return part[j - i];
        return j - i - 1 >= 0 ? part[j - i - 1] : 0;
    };

    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i <= j; i++)
        {
            whole[j] = (whole[j] + D(0, i) * D(i, j)) % MOD;
        }
    }

    if (deg % 2 == 1)
    {
        vector<ll> whole2(len);
        for (int j = 0; j < len; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                whole2[j] = (whole2[j] + (i != j || j % 2 == 0 ? whole[i] : 0)) % MOD;
            }
        }
        return whole2;
    }

    return whole;
}

void simple_transition(vector<ll> &dp, vector<long long> &L, vector<long long> &R, vector<long long> &fl, long long z)
{
    vector<ll> dp2(dp.size());
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < i + (fl[i] == 1); j++)
        {
            if (L[i] <= z && z <= R[i] && L[j] <= z - 1 && z - 1 <= R[j])
            {
                dp2[i] = (dp2[i] + dp[j]) % MOD;
            }
        }
    }
    dp = dp2;
}

long long calls = 0;

long long solve(vector<long long> b)
{
    calls += b.size() - 1;
    vector<long long> c = b;
    sort(c.begin(), c.end());
    int sz = b.size() - 1;
    vector<long long> L(sz);
    vector<long long> R(sz);
    vector<long long> fl(sz, 1);
    for (int i = 0; i + 1 < b.size(); i++)
    {
        L[i] = b[i];
        R[i] = b[i + 1];

        if (i != 0)
        {
            if (L[i] < R[i]) L[i]++;
            else L[i]--;
        }

        if (L[i] > R[i]) swap(L[i], R[i]), fl[i] = -1;
    }
    vector<ll> dp(sz);
    long long fr = c[0], to = c.back();
    for (int i = 0; i < sz; i++)
    {
        if (L[i] <= fr && fr <= R[i])
        {
            dp[i] = 1;
        }
    }
    long long lst = fr;
    for (auto p : c)
    {
        long long z = p - 2;
        if (lst < z)
        {
            long long d = z - lst;
            vector<int> act(sz);
            for (int i = 0; i < sz; i++)
            {
                for (int j = 0; j < i + (fl[i] == 1); j++)
                {
                    if (L[i] <= z && z <= R[i] && L[j] <= z && z <= R[j])
                    {
                        act[i] = 1;
                        act[j] = 1;
                    }
                }
            }
            int cnt = 0;
            vector<int> link(sz);
            for (int i = 0; i < sz; i++)
                if (act[i])
                    link[i] = cnt++;
            vector<ll> fast = binpow(cnt, d);
            vector<ll> dp2(sz);
            auto D = [&](int i, int j){
                if (i % 2 == 0) return fast[j - i];
                return (j - i - 1 >= 0 ? fast[j - i - 1] : 0);
            };
            for (int i = 0; i < sz; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    dp2[i] = (dp2[i] + dp[j] * D(link[j], link[i])) % MOD;
                }
            }
            dp = dp2;
            lst = z;
        }
        z = p - 1;
        if (lst < z)
        {
            simple_transition(dp, L, R, fl, z);
            lst = z;
        }
        z = p;
        if (lst < z)
        {
            simple_transition(dp, L, R, fl, z);
            lst = z;
        }
        z = p + 1;
        if (z <= to && lst < z)
        {
            simple_transition(dp, L, R, fl, z);
            lst = z;
        }
    }
    long long res = 0;
    for (int i = 0; i < sz; i++)
    {
        if (L[i] <= to && to <= R[i])
        {
            res = (res + dp[i]) % MOD;
        }
    }
    return res;
}

int sign(long long x)
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    long long x = 0;
    cin >> x;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x != 0)
        {
            if (a.size() && sign(a.back()) == sign(x))
            {
                a[a.size() - 1] += x;
            }
            else
            {
                a.push_back(x);
            }
        }
    }
    vector<long long> peaks;
    peaks.push_back(1);
    n = a.size();
    for (int i = 0; i < n; i++)
    {
        peaks.push_back(a[i] + peaks.back());
    }
    n++;
    long long max_len = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (peaks[i] < peaks[j])
                max_len = max(max_len, peaks[j] - peaks[i] + 1);
        }
    }

    if (max_len == 1)
    {
        long long ans = 1;
        cout << 1 << " ";
        for (int i = 0; i < a.size(); i++)
        {
            ans = (ans + abs(a[i])) % MOD;
        }
        cout << ans << endl;
        return 0;
    }

    cout << max_len << " ";
    long long ans = 0;
    int i = 0;
    while (i < n)
    {
        int id = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (peaks[j] - peaks[i] + 1 == max_len)
            {
                id = j;
            }
        }
        if (id == -1)
        {
            i++;
            continue;
        }
        vector<long long> b;
        for (int k = i; k <= id; k++)
        {
            b.push_back(peaks[k]);
        }
        i = id;
        ans = (ans + solve(b)) % MOD;
    }
    cout << ans << endl;
}