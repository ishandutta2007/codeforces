#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].first >> b[i].second;
    }
    for (int j = 0; j < n; j++) {
        pair<int, int> ans = {a[0].first + b[j].first, a[0].second + b[j].second};
        multiset<pair<int, int>> have;
        for (auto [x, y] : b) {
            have.insert({x, y});
        }
        for (auto [x, y] : a) {
            x = ans.first - x;
            y = ans.second - y;
            if (have.find({x, y}) == have.end()) {
                break;
            } else {
                have.erase(have.find({x, y}));
            }
        }
        if ((int) have.size() == 0) {
            cout << ans.first << " " << ans.second;
            return 0;
        }
    }
}