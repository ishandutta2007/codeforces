#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long x = accumulate(a.begin(), a.end(), 0LL);
    if (x % n == 0) cout << 0 << "\n";
    else cout << 1 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}