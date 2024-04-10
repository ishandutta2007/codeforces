#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)

void solve()
{
    int n;
    cin >> n;
    int neg = 0, pos = 0;
    int a;
    for (int i = 0; i < n; i++) cin >> a, neg |= a < 0, pos |= a > 0;
    if (neg)
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
    }
    if (neg)
    {
        cout << 101 << endl;
        for (int i = 0; i <= 100; i++) cout << -i << " "; cout << endl;
    }
    if (pos)
    {
        cout << 101 << endl;
        for (int i = 0; i <= 100; i++) cout << i << " "; cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}