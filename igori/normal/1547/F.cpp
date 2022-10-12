#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) a.push_back(a[i]);

    int g = a[0];
    for (int i = 1; i < n; i++) g = __gcd(a[i], g);

    vector<vector<int> > G(20, vector<int>(2 * n));
    G[0] = a;
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i + (1 << j) <= 2 * n; i++)
        {
            G[j][i] = __gcd(G[j - 1][i], G[j - 1][i + (1 << j) / 2]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int r = i;
        int gg = a[i];
        for (int j = 19; j >= 0; j--)
        {
            if (r + (1 << j) < 2 * n && __gcd(gg, G[j][r + 1]) > g)
            {
                gg = __gcd(gg, G[j][r + 1]);
                r += (1 << j);
            }
        }
        ans = max(ans, r - i + 1);
    }
    if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end()))
        ans = 0;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}