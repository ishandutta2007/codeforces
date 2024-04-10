#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int p = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            p = i;
            break;
        }
    }
    cout << min(min(n - 1, p), 3) << "\n";
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