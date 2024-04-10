#include <bits/stdc++.h>

using namespace std;

map<int, int> ans;

void solve()
{
    int n;
    cin >> n;
    int x = 2;
    while (x <= n)
    {
        x *= 2;
    }
    if (n + 1 != x)
    {
        cout << x - 1 << "\n";
    }
    else
    {
        if (ans.find(n) != ans.end())
        {
            cout << ans[n] << "\n";
        }
        else
        {
            int res = 1;
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                    res = max(res, n / i);
            }
            ans[n] = res;
            cout << ans[n] << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}