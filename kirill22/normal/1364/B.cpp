#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define ld long double
#define pb push_back

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while (ans.size() >= 2) {
            auto x = ans.back();
            ans.pop_back();
            int y = ans.back();
            if (y - x >= 0 && x - a[i] >= 0) {
                continue;
            }
            if (y - x <= 0 && x - a[i] <= 0) {
                continue;
            }
            ans.pb(x);
            break;
        }
        ans.pb(a[i]);
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}