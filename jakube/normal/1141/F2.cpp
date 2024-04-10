#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    map<int, vector<pair<int, int>>> sums;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            sums[sum].push_back({i+1, j+1});
        }
    }

    vector<pair<int, int>> best;
    for (auto& [_, pairs] : sums) {
        sort(pairs.begin(), pairs.end(), [](auto u, auto v) {
            swap(u.first, u.second);
            swap(v.first, v.second);
            return u < v;
        });
        vector<pair<int, int>> cur;
        for (auto [u, v] : pairs) {
            if (cur.empty() || cur.back().second < u) {
                cur.push_back({u, v});
            }
        }
        if (cur.size() > best.size()) {
            best = cur;
        }
    }
    cout << best.size() << '\n';
    for (auto [a, b] : best) {
        cout << a << " " << b << '\n';

    }
}