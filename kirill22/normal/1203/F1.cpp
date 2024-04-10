#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first + a.second == b.first + b.second) {
        return a.first < b.first;
    }
    return a.first + a.second < b.first + b.second;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y >= 0) {
            a.push_back({x, y});
        }
        else {
            b.push_back({x, y});
        }
    }
    sort(a.begin(), a.end());
    for (auto c : a) {
        if (r < c.first) {
            cout << "NO";
            return 0;
        }
        r += c.second;
    }
    sort(b.begin(), b.end(), cmp);
    for (int i = b.size() - 1; i >= 0; i--) {
        if (r < b[i].first) {
            cout << "NO";
            return 0;
        }
        r += b[i].second;
    }
    if (r < 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}