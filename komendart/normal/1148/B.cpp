#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    
    if (n <= k || m <= k) {
        cout << -1 << '\n';
        return 0;
    }
    
    int ans = 0;
    for (int i = 0; i < n && i <= k; ++i) {
        int tmp = a[i] + ta;
        int id = lower_bound(begin(b), end(b), tmp) - begin(b);
        if (id + k - i >= m) {
            cout << -1 << '\n';
            return 0;
        }
        ans = max(ans, b[id + k - i] + tb);
    }
    
    cout << ans << '\n';
}