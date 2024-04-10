#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    long long res = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i + 1 < n; i++)
        res += abs(a[i] - a[i + 1]);
    long long ans = res;
    for (int i = 0; i + 2 < n; i++)
        ans = min(ans, res + abs(a[i] - a[i + 2]) - abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i + 2]));
    ans = min(ans, res - abs(a[0] - a[1]));
    ans = min(ans, res - abs(a[n - 2] - a[n - 1]));
    cout << ans << "\n";
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