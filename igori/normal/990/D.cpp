#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if (a > 1 && b > 1)
    {
        cout << "NO\n";
        return;
    }
    if (a == 1 && b == 1 && (n == 2 || n == 3))
    {
        cout << "NO\n";
        return;
    }
    int x = max(a, b);
    int m = n - x;
    vector<string> s(n, string(n, '0'));
    for (int i = 1; i <= m; i++)
        s[i - 1][i] = s[i][i - 1] = '1';
    if (b == 1)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << s[i] << "\n";
    }
    else
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) cout << '0';
                else if (s[i][j] == '1') cout << '0';
                else cout << '1';
            }
            cout << "\n";
        }
    }
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