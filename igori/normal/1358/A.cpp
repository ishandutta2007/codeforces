#include <bits/stdc++.h>

const int N = 100005;

using namespace std;
typedef long long ll;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, m;
    cin >> n >> m;
    if (n % 2 == 0 || m % 2 == 0)
    {
        cout << n * m / 2 << "\n";
    }
    else
    {
        cout << n * m / 2 + 1 << "\n";
    }
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