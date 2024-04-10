#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mn, mnc, mx, mxc;
        map<pii, int> st;
        for (int i = 0; i < n; ++i) {
            int l, r, c;
            cin >> l >> r >> c;
            pii x = {l, r};
            if (st.count(x)) {
                st[x] = min(st[x], c);
            } else {
                st[x] = c;
            }
            if (i == 0) {
                mn = l;
                mx = r;
                mnc = c;
                mxc = c;
            } else {
                if (l < mn) {
                    mn = l;
                    mnc = c;
                } else if (l == mn) {
                    mnc = min(mnc, c);
                }
                if (r > mx) {
                    mx = r;
                    mxc = c;
                } else if (r == mx) {
                    mxc = min(mxc, c);
                }
            }
            int ans = mxc + mnc;
            auto it = st.find({mn, mx});
            if (it != st.end()) {
                ans = min(ans, it->second);
            }
            cout << ans << "\n";
        }
    }


}