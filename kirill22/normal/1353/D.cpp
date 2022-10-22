#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    vector<int> l(n, -1);
    l[0] = n - 1;
    set<pair<int, int>> st;
    int tmp = 1;
    st.insert({-n, 0});
    while (st.size() != 0) {
        auto p = *st.begin();
        st.erase(st.begin());
        int L = abs(-p.second), R = l[L];
        int x = R - L + 1;
        if (x % 2 == 1) {
            ans[(L + R) / 2] = tmp++;
            int m = (L + R) / 2;
            l[L] = m - 1;
            if (m + 1 < n) l[m + 1] = R;
            if (l[L] - L + 1 > 0) {
                st.insert({-(l[L] - L + 1), L});
            }
            if (m + 1 < n && l[m + 1] - (m + 1) + 1 > 0) {
                st.insert({-(l[(m + 1)] - (m + 1) + 1), (m + 1)});
            }
        }
        else {
            ans[(L + R - 1) / 2] = tmp++;
            int m = (L + R - 1) / 2;
            l[L] = m - 1;
            if (m + 1 < n) l[m + 1] = R;
            if (l[L] - L + 1 > 0) {
                st.insert({-(l[L] - L + 1), L});
            }
            if (m + 1 < n && l[m + 1] - (m + 1) + 1 > 0) {
                st.insert({-(l[(m + 1)] - (m + 1) + 1), (m + 1)});
            }
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
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