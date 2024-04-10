#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; i++) {
            b[i].first = a[i];
            cin >> b[i].second;
        }
        vector<pair<int, int>> ans;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i + 1 < n; i++) {
                if (b[i] > b[i + 1]) {
                    swap(b[i], b[i + 1]);
                    ans.push_back({i, i + 1});
                }
            }
        }
        int ok = 1;
        for (int i = 1; i < n; i++) {
            if (b[i].first < b[i - 1].first || b[i].second < b[i - 1].second) {
                ok = 0;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        } else {
            cout << (int) ans.size() << '\n';
            for (auto [i, j] : ans) {
                cout << i + 1 << " " << j + 1 << '\n';
            }
        }
    }
}