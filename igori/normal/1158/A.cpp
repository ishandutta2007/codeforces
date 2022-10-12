#include <bits/stdc++.h>
using namespace std;
 
long long n, m;
long long b[500000];
long long g[500000];
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> g[i];
    sort(b, b + n);
    sort(g, g + m);
    if (b[n - 1] > g[0])
    {
        cout << -1;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += g[i];
    }
    for (int i = 0; i + 1 < n; i++)
    {
        ans += b[i] * m;
    }
    if (g[0] != b[n - 1])
    {
        ans += b[n - 1] - b[n - 2];
    }
    cout << ans;
}