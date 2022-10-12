const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define uniq(x) sort(all(x)); x.resize(unique(all(x)) - (x).begin())

void rec(int l, int r, int p, vector<int> &ans, vector<vector<ll> > &restore)
{
    if (l <= r)
    {
        ans[restore[l][r]] = p;
        rec(l, restore[l][r] - 1, restore[l][r], ans, restore);
        rec(restore[l][r] + 1, r, restore[l][r], ans, restore);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll> > c(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }

    vector<vector<ll> > Pref = c, Suff = c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++) Pref[i][j] += Pref[i][j - 1];
        for (int j = n - 2; j >= 0; j--) Suff[i][j] += Suff[i][j + 1];
    }

    auto pref = [&](int i, int j)
    {
        if (j >= 0) return Pref[i][j];
        else return 0LL;
    };

    auto suff = [&](int i, int j)
    {
        if (j < n) return Suff[i][j];
        else return 0LL;
    };

    vector<vector<ll> > dp(n, vector<ll>(n, INFLL));
    vector<vector<ll> > restore(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
        restore[i][i] = i;
    }

    auto getdp = [&](int l, int r)
    {
        if (l > r) return 0ll;
        return dp[l][r];
    };

    vector<vector<ll> > table(n, vector<ll>(n, 0));

    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            for (int j = l; j <= r; j++)
            {
                table[l][r] += pref(j, l - 1) + suff(j, r + 1);
            }
        }
    }

    auto goout = [&](int l, int r)
    {
        if (l > r) return 0ll;
        return table[l][r];
    };

    for (int len = 2; len <= n; len++)
    {
        for (int L = 0; L + len <= n; L++)
        {
            int R = L + len - 1;
            for (int root = L; root <= R; root++)
            {
                ll res = getdp(L, root - 1) + getdp(root + 1, R);
                res += goout(L, root - 1) + goout(root + 1, R);
                if (res < dp[L][R])
                {
                    dp[L][R] = res;
                    restore[L][R] = root;
                }
            }
            //cout << L << " " << R << " : " << dp[L][R] << "\n";
        }
    }
    cerr << dp[0][n - 1] << "\n";
    vector<int> ans(n);
    rec(0, n - 1, -1, ans, restore);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
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