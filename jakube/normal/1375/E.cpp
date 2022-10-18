#include "bits/stdc++.h"
using namespace std;

// using ModInt = Modular<1'000'000'007>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;

    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i] = {v[i], i};
    }
    vector<vector<int>> swaps(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vp[i] > vp[j]) {
                swaps[i].push_back(j);
                cnt++;
            }
        }
    }

    vector<pair<int, int>> result;
    for (int i = 0; i < n; i++) {
        if (swaps[i].empty())
            continue;

        vector<pair<pair<int, int>, int>> tmp;
        for (auto j : swaps[i]) {
            tmp.push_back({vp[j], j});
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        for (auto [x, j] : tmp) {
            swap(vp[i], vp[j]);
            result.push_back({i, j});
        }
    }

    cout << cnt << '\n';
    for (auto [a, b] : result)
        cout << a + 1 << " " << b + 1 << '\n';

    for (int i = 0; i < n - 1; i++) {
        assert(vp[i].first <= vp[i+1].first);
    }
}