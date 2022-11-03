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
//t = 1;
    while (t--) {
        int n;
        cin >> n;
//n = 200000;
        vector<vector<int>> pos(n + 1);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int x;
//            mt19937 mt(564);
//            x = mt() % 100;
            cin >> x;
            a[i] = x;
            if (x <= n) {
                pos[x].push_back(i);
            }
        }
        for (int i = 0; i <= n; ++i) {
            reverse(pos[i].begin(), pos[i].end());
        }
        set<int> q;
        for (int i = 0; i <= n; ++i) {
            if (pos[i].size() == 0) {
                q.insert(i);
            }
        }
        int sz = -1;
        vector<int> ans;
        while (sz < n - 1) {
            int mex = *q.begin();
            ans.push_back(mex);
            int idx = -1;
            for (int i = 0; i < mex; ++i) {
                idx = max(idx, pos[i].back());
            }
            idx = max(idx, sz + 1);
            for (int j = sz + 1; j <= idx; ++j) {
                int i = a[j];
                while (!pos[i].empty() && pos[i].back() <= idx) {
                    pos[i].pop_back();
                    if (pos[i].empty()) {
                        q.insert(i);
                    }
                }
            }
            sz = idx;
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++i) {
            if (i) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << "\n";
    }
}