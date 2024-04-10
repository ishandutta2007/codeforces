#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

const int N = 1e6;

ll dp[N];

struct st{
    vector<pair<ll, ll> > st;
    void push(ll x)
    {
        st.push_back({x, x});
        if (st.size() >= 2) st[st.size() - 1].second = max(st[st.size() - 1].second, st[st.size() - 2].second);
    }
    ll mx()
    {
        if (st.size()) return st.back().second;
        return -INF;
    }
    ll back()
    {
        if (st.size()) return st.back().first;
        return -INF;
    }
    void pop()
    {
        if (st.size()) st.pop_back();
    }
    ll sz()
    {
        return st.size();
    }
};

struct q{
    st A, B;
    void push(ll x)
    {
        B.push(x);
    }
    ll mx()
    {
        return max(A.mx(), B.mx());
    }
    void pop()
    {
        if (!A.sz())
        {
            while (B.sz())
            {
                A.push(B.back());
                B.pop();
            }
        }
        A.pop();
    }
    int sz()
    {
        return A.sz() + B.sz();
    }
};

int main()
{
    int k;
    vector<ll> f(6);
    cin >> k;
    for (int i = 0; i < 6; i++) cin >> f[i];
    ll SZ = 3;
    ll obj = 3 * (k - 1);
    for (int i = 1; i < N; i++) dp[i] = -INF;
    for (int j = 0; j < 6; j++)
    {
        vector<q> Q(SZ);
        //cout << "Start j = " << j << endl;
        for (int i = N - 1; i >= 0; i--)
        {
            int p = i % SZ;
            if (Q[p].sz() == obj + 1) break;
            Q[p].push(dp[i] - f[j] * (i / SZ));
            //cout << "Pushed " << dp[i] - f[j] * (i / SZ) << " " << p << endl;
        }
        //cout << "Calculation" << endl;
        for (int i = N - 1; i >= 0; i--)
        {
            int p = i % SZ;
            //cout << "i mx " << Q[p].mx() << endl;
            dp[i] = max(dp[i], Q[p].mx() + f[j] * (i / SZ));
            Q[p].pop();
            if (i - (obj + 1) * SZ >= 0)
            {
                Q[p].push(dp[i - (obj + 1) * SZ] - f[j] * ((i - (obj + 1) * SZ) / SZ));
            }
        }
        //for (int i = 0; i < N; i++) cout << dp[i] << " ";
        //cout << endl;
        SZ *= 10;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        for (int j = 0; j <= n; j++)
        {
            ll res = 0;
            ll x = n - j;
            for (int i = 0; i < 6; i++)
            {
                int d = x % 10;
                if (d % 3 == 0)
                {
                    res += f[i] * d / 3;
                }
                x /= 10;
            }
            //cout << j << " " << dp[j] << " " << res << endl;
            ans = max(ans, dp[j] + res);
        }
        cout << ans << "\n";
    }
}