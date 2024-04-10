#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}