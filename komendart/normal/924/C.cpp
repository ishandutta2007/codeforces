#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define int long long

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = max(pref[i - 1], a[i]);
    }
    int cur = pref[n];
    vector<int> cnt(n + 1);
    for (int i = n; i >= 1; --i) {
        if (pref[i] < cur) --cur;
        cnt[i] = cur + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        //cout << a[i] << ' ' << cnt[i] << endl;
        ans += cnt[i] - a[i] - 1;
    }
    cout << ans << '\n';
    
}