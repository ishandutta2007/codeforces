#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    int minc = 0;
    int x = n, y = m;
    while (x > 1 && y > 1)
    {
        minc += x + y - 1;
        x--, y--;
    }
    minc += x - 1 + y - 1;
    int maxc = n * m - 1;
    if (minc <= k && k <= maxc)
        cout << "YES\n";
    else cout << "NO\n";
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