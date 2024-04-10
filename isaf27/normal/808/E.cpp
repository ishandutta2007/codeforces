#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const int BIG = 1e9;
const ll INF = 1e18;
const int M = 100001;
const int S = 500001;
const int L = 18;
const int th = 3;

int n, m;
vector<vector<int> > v(th);
ll pref1[M],  pref2[M];
ll dp[S];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int w, c;
        cin >> w >> c;
        --w;
        v[w].push_back(c);
    }
    for (int i = 0; i < S; i++)
        dp[i] = -INF;
    vector<int> a;
    sort(v[0].rbegin(), v[0].rend());
    for (int i = 0; i < v[0].size(); i += 2)
    {
        if (i + 1 < v[0].size())
            a.push_back(v[0][i] + v[0][i + 1]);
    }
    for (int i : v[1])
        a.push_back(i);
    sort(a.rbegin(), a.rend());
    dp[0] = 0;
    for (int i = 0; i < a.size(); i++)
        dp[2 * i + 2] = dp[2 * i] + a[i];
    a.clear();
    if (!v[0].empty())
    {
        ll u = v[0][0];
        for (int i = 1; i < v[0].size(); i += 2)
        {
            if (i + 1 < v[0].size())
                a.push_back(v[0][i] + v[0][i + 1]);
        }
        for (int i : v[1])
            a.push_back(i);
        sort(a.rbegin(), a.rend());
        dp[1] = u;
        for (int i = 0; i < a.size(); i++)
            dp[2 * i + 3] = dp[2 * i + 1] + a[i];
    }
    sort(v[2].rbegin(), v[2].rend());
    ll ans = 0;
    ll s = 0;
    for (int i = 1; i < S; i++)
        dp[i] = max(dp[i], dp[i - 1]);
    for (int i = 0; i <= min((int)v[2].size(), m / 3); i++)
    {
        if (i > 0)
            s += v[2][i - 1];
        ans = max(ans, dp[m - 3 * i] + s);
    }
    cout << ans;
    return 0;
}