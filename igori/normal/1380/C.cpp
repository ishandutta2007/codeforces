#include<bits/stdc++.h>

using namespace std;
#define fi first
#define se second

const int N = 1000005;
const int INF = 1e9;
const int MOD = 998244353;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = (x + a[i] - 1) / a[i];
        if (i + cnt <= n)
        {
            n = i;
            ans++;
        }
    }
    cout << ans << "\n";
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