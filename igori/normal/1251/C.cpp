#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    vector<int> a, b;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - '0';
        if (x % 2) a.push_back(x);
        else b.push_back(x);
    }
    a.push_back(10);
    b.push_back(10);
    for (int i = 0, j = 0; i + j < n; )
    {
        if (a[i] < b[j]) cout << a[i], i++;
        else cout << b[j], j++;
    }
    cout << "\n";
}

signed main()
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