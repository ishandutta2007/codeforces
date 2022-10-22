#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    map<int, pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    vector<int> ans;
    for (int r = 1; r <= 200; r++) {
        vector<pair<int, int>> z;
        for (auto c : a) {
            if (c.second.first <= r && c.second.second >= r) {
                z.push_back({c.second.second, c.first});
            }
        }
        sort(z.begin(), z.end());
        for (int i = k; i < z.size(); i++) {
            ans.push_back(z[i].second);
            a.erase(a.find(z[i].second));
        }
    }
    cout << ans.size() << endl;
    for (auto c : ans) {
        cout << c + 1 << " ";
    }
}