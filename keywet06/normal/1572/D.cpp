#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(1 << n);
    for (int i = 0; i < 1 << n; i++) cin >> a[i];
    vector<int> R_match(1 << n), L_match(1 << n);
    set<pair<int, int>> st;
    set<int> L;
    vector<vector<int>> g(1 << n);
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) g[i].push_back(i ^ (1 << j));
    }
    vector<int> belong(1 << n);
    for (int i = 0; i < 1 << n; i++) belong[i] = __builtin_popcount(i) % 2;
    vector<int> c(1 << n);
    for (int i = 0; i < 1 << n; i++) {
        if (belong[i]) {
            int mx = 0;
            for (int v : g[i]) mx = max(mx, a[v]);
            st.insert({mx + a[i], i});
            c[i] = mx + a[i];
        }
    }

    int64 res = 0;
    vector<int> vis(1 << n);
    k = min(k, 1 << (n - 1));
    while (k--) {
        int mx1 = -1, i1;
        if (st.size()) {
            mx1 = (*st.rbegin()).first, i1 = (*st.rbegin()).second;
        }
        int mx2 = -1, i2 = 0, j2 = 0;
        int tmpj2 = -1;
        vector<int> clear_dfs;
        function<void(int)> dfs = [&](int i) {
            if (vis[i]) return;
            vis[i] = 1;
            clear_dfs.push_back(i);
            for (int v : g[i]) {
                if (!R_match[v]) {
                    if (tmpj2 == -1 || a[tmpj2] < a[v]) {
                        tmpj2 = v;
                    }
                } else {
                    if (R_match[v] != i) dfs(R_match[v]);
                }
            }
        };

        for (auto I : L)
            if (!L_match[I]) {
                tmpj2 = -1;
                clear_dfs.clear();
                dfs(I);
                for (auto I : clear_dfs) vis[I] = 0;

                if (tmpj2 != -1) {
                    int tmp = a[tmpj2] + a[I];
                    if (tmp > mx2) {
                        mx2 = tmp;
                        i2 = I;
                        j2 = tmpj2;
                    }
                }
            }
        if (mx1 > mx2) {
            int j, tmp = -1;
            for (int v : g[i1]) {
                if (a[v] > tmp) {
                    tmp = a[v];
                    j = v;
                }
            }

            res += mx1;
            R_match[j] = i1;
            for (int v : g[j]) {
                L.insert(v);
                st.erase({c[v], v});
            }
            st.erase({mx1, i1});
            L_match[i1] = 1;
        } else {
            vector<int> clear_dfs;
            function<bool(int)> dfs2 = [&](int i) {
                if (vis[i]) return false;
                vis[i] = 1;
                clear_dfs.push_back(i);
                for (int v : g[i]) {
                    if (v == j2) {
                        R_match[v] = i;
                        return true;
                    } else if (R_match[v]) {
                        if (dfs2(R_match[v])) {
                            R_match[v] = i;
                            return true;
                        }
                    }
                }
                return false;
            };
            clear_dfs.clear();
            dfs2(i2);
            for (auto I : clear_dfs) vis[I] = 0;

            res += mx2;
            for (int v : g[j2]) {
                L.insert(v);
                st.erase({c[v], v});
            }
            L_match[i2] = 1;
        }
    }

    cout << res;
}