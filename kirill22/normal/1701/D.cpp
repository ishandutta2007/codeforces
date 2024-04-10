#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n), a(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> l(n), r(n);
        vector<vector<pair<int, int>>> qu(n + 2);
        for (int i = 0; i < n; i++) {
            if (b[i]) {
                r[i] = (i + 1) / b[i];
                l[i] = (i + 1) / (b[i] + 1) + 1;
            } else {
                l[i] = i + 2;
                r[i] = n;
            }
            r[i] = min(r[i], n);
            qu[l[i]].push_back({i, 1});
            qu[r[i] + 1].push_back({i, -1});
            //cout << i << " " << l[i] << " " << r[i] << endl;
        }
        set<pair<int, int>> st;
        for (int x = 1; x <= n; x++) {
            for (auto [i, t] : qu[x]) {
                if (t == -1) {
                    st.erase({r[i], i});
                } else {
                    st.insert({r[i], i});
                }
            }
            auto el = *st.begin();
            st.erase(el);
            a[el.second] = x;
        }
        for (auto x : a) {
            cout << x << " ";
        }
        cout << '\n';
    }
}