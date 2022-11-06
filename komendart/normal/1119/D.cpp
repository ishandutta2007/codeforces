#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    sort(s.begin(), s.end());
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = s[i + 1] - s[i];
    }
    sort(d.begin(), d.end());
    vector<int> pref(n);
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + d[i - 1];
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int dist = r - l;
        int less = upper_bound(d.begin(), d.end(), dist) - d.begin();
        int ans = pref[less] + (n - less) * (dist + 1);
        cout << ans << '\n';
    }
}