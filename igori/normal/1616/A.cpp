#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(101);
    for (int i = 0; i < n; i++) cnt[abs(a[i])]++;

    int ans = 0;
    for (int i = 0; i <= 100; i++) ans += min(2 - (i == 0), cnt[i]);
    cout << ans << "\n";
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