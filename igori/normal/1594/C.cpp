#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    int tr = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c) tr = 0;
    }
    if (tr)
    {
        cout << 0 << "\n\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        int tr = 1;
        for (int j = i; j <= n; j += i)
        {
            if (s[j - 1] != c) tr = 0;
        }
        if (tr)
        {
            cout << 1 << "\n";
            cout << i << "\n";
            return;
        }
    }
    cout << 2 << "\n";
    cout << n - 1 << " " << n << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}