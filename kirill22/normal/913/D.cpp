#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> a(n);
    map<pair<int, int>, vector<int>> id;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        id[a[i]].push_back(i);
    }
    sort(a.rbegin(), a.rend());
    pair<int, int> ans = {0, 0};
    multiset<int> res;
    int sum = 0;
    for (auto [x, y] : a) {
        res.insert(y);
        sum += y;
        while ((int) res.size() > x || sum > t) {
            y = *res.rbegin();
            res.erase(res.find(y));
            sum -= y;
        }
        ans = max(ans, {(int) res.size(), x});
    }
    cout << ans.first << '\n' << ans.first << '\n';
    res.clear();
    while ((int) a.size() > 0 && a.back().first < ans.second) {
        a.pop_back();
    }
    sort(a.begin(), a.end(), [&] (pair<int, int> x, pair<int, int> y) {
        return x.second < y.second;
    });
    a.resize(ans.first);
    for (auto [x, y] : a) {
        cout << id[{x, y}].back() + 1 << " ";
        id[{x, y}].pop_back();
    }
}