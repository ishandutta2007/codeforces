#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve()
{
    int r, b, d;
    cin >> r >> b >> d;
    if (r > b) swap(r, b);
    if (1ll * r * (d + 1) >= b) cout << "YES\n";
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