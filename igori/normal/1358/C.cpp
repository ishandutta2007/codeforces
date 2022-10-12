#include <bits/stdc++.h>

const int N = 100005;

using namespace std;
typedef long long ll;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll c = 1 + (x2 - x1) * (y2 - y1);
    cout << c << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}