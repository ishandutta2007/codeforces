#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        vector<long long> p(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + a[i] - b[i];
        }
        vector<int> ql(m), qr(m), qc(m);
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; i++) {
            cin >> ql[i] >> qr[i];
            ql[i]--;
            g[ql[i]].push_back(i);
            g[qr[i]].push_back(i);
        }
        vector<int> tmp;
        set<int> st;
        for (int i = 0; i <= n; i++) {
            if (p[i] == 0) {
                tmp.push_back(i);
            } else {
                st.insert(i);
            }
        }
        for (int j = 0; j < (int) tmp.size(); j++) {
            int pos = tmp[j];
            for (auto i : g[pos]) {
                if (++qc[i] == 2) {
                    while (1) {
                        auto it = st.lower_bound(ql[i]);
                        if (it != st.end() && *it <= qr[i]) {
                            tmp.push_back(*it);
                            st.erase(it);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        cout << ((int) st.size() ? "NO\n" : "YES\n");
    }
}