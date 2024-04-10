#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    n += m;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << n - s.size() << "\n";
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