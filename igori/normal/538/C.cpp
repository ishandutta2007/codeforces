#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

long long n, m;
ll d[500000];
ll h[500000];
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> d[i] >> h[i];
    }
    ans = max(ans, h[0] + d[0] - 1);
    ans = max(ans, h[m - 1] + n - d[m - 1]);
    for (int i = 0; i + 1 < m; i++)
    {
        ll h1 = min(h[i], h[i + 1]);
        ll h2 = max(h[i], h[i + 1]);
        ll gap = d[i + 1] - d[i];
        if (h2 - h1 > gap)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        gap -= h2 - h1;
        if (gap % 2 == 0)
        {
            int d = gap / 2;
            ans = max(ans, h2 + d);
        }
        else
        {
            int d = gap / 2;
            ans = max(ans, d + h2);
        }
    }
    cout << ans;
}