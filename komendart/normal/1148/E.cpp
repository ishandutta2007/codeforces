#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first;
        s[i].second = i + 1;
    }
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    
    sort(begin(s), end(s));
    sort(begin(t), end(t));
    
    vector<int> can;
    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i].first == t[i]) continue;
        if (s[i].first < t[i]) {
            can.push_back(i);
        } else {
            while (!can.empty() && s[i].first > t[i]) {
                int id = can.back();
                int d1 = t[id] - s[id].first;
                int d2 = s[i].first - t[i];
                int d = min(d1, d2);
                ans.emplace_back(s[id].second, s[i].second, d);
                s[id].first += d;
                s[i].first -= d;
                if (d1 <= d) {
                    can.pop_back();
                }
            }
            if (can.empty() && s[i].first > t[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (!can.empty()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << sz(ans) << '\n';
    for (auto [i, j, d]: ans) {
        cout << i << ' ' << j << ' ' << d << '\n';
    }
}