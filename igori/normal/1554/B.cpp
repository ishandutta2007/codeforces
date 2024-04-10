#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long ans = -1e18;
        for (int i = n - 1; i >= 0 && i >= n - 2 * k; i--)
            for (int j = i - 1; j >= 0 && j >= n - 2 * k; j--)
                ans = max(ans, 1ll * (i + 1) * (j + 1) - k * (a[i] | a[j]));
        cout << ans << "\n";
    }
}