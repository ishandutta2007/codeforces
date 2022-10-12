#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    long long k;
    cin >> k;
    if (k % 2 == 1)
    {
        cout << -1 << "\n";
        return;
    }
    k /= 2;
    vector<int> s;
    int ans = 0;
    for (int d = 60; d >= 1; d--)
    {
        long long c = (1ll << d) - 1;
        while (k >= c)
        {
            s.push_back(d);
            ans += d;
            k -= c;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < s.size(); i++)
    {
        cout << "1 ";
        for (int j = 0; j < s[i] - 1; j++)
            cout << "0 ";
    }
    cout << "\n";
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