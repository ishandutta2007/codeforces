#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> ans(30);
    for (int j = 0; j < 30; j++) {
        vector<pair<int, int>> tmp;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].second - a[i].first + 1 >= (1 << j)) {
                sum++;
                continue;
            }
            int l = a[i].first % (1 << j);
            int r = a[i].second % (1 << j);
            if (l <= r) {
                tmp.push_back({l, 1});
                tmp.push_back({r + 1, -1});
            } else {
                tmp.push_back({0, 1});
                tmp.push_back({r + 1, -1});
                tmp.push_back({l, 1});
                tmp.push_back({(1 << j), -1});
            }
        }
        ans[j] = sum;
        sort(tmp.begin(), tmp.end());
        int cur = 0;
        for (auto [x, val] : tmp) {
            cur += val;
            ans[j] = max(ans[j], cur + sum);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int w;
        cin >> w;
        int j = 0;
        while (!(w >> j & 1)) {
            j++;
        }
        cout << ans[j] << '\n';
    }
}