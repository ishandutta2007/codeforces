#include "bits/stdc++.h"

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        a[i + 1] = (a[i] + (s[i] - '0')) % 9;
    }
    auto get = [&] (int l, int r) {
        return (a[r] - a[l] + 9) % 9;
    };
    vector<vector<int>> d(9);
    int w, m;
    cin >> w >> m;
    vector<int> cost(n);
    for (int i = 0; i + w - 1 < n; i++) {
        d[get(i, i + w)].push_back(i);
        cost[i] = get(i, i + w);
    }
    vector<int> elems;
    for (auto& x : d) {
        if ((int) x.size() >= 2) {
            x.resize(2);
        }
        for (auto y : x) {
            elems.push_back(y);
        }
    }
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        pair<int, int> ans = {-2, -2};
        for (auto i : elems) {
            for (auto j : elems) {
                if (i != j && (cost[i] * get(l, r + 1) + cost[j]) % 9 == k) {
                    if (ans.first == -2) {
                        ans = {i, j};
                    } else {
                        ans = min(ans, {i, j});
                    }
                }
            }
        }
        cout << ans.first + 1 << " " << ans.second + 1 << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}