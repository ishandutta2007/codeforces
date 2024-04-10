#include<bits/stdc++.h>

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
    while (1) {
        vector<int> b, c;
        for (int i = 0; i < n; i++) {
            if (abs(a[i].first) % 2 == abs(a[i].second) % 2) {
                b.push_back(i);
            } else {
                c.push_back(i);
            }
        }
        if ((int) b.size() && (int) c.size()) {
            cout << (int) b.size() << '\n';
            for (auto i : b) {
                cout << i + 1 << " ";
            }
            return 0;
        }
        b.clear(), c.clear();
        for (int i = 0; i < n; i++) {
            if (abs(a[i].first) % 2 == 1) {
                b.push_back(i);
            } else {
                c.push_back(i);
            }
        }
        if ((int) b.size() && (int) c.size()) {
            cout << (int) b.size() << '\n';
            for (auto i : b) {
                cout << i + 1 << " ";
            }
            return 0;
        }
        int x = abs(a[0].first) % 2, y = abs(a[0].second) % 2;
        for (auto& [x2, y2] : a) {
            x2 = (x2 - x) / 2;
            y2 = (y2 - y) / 2;
        }
    }
}