#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<int, int>> ans;
    auto upd = [&] (int l, int r) {
        ans.push_back({l, r});
        reverse(a.begin() + l, a.begin() + r + 1);
    };
    for (int j = 0; j < n; j++) {
        if (a[j] == b[j]) {
            continue;
        }
        if (j == 0 || j == n - 1) {
            cout << "NO\n";
            return;
        }
        for (int i = j + 1; i + 1 < n; i++) {
            if (a[i] == b[j] && a[i + 1] == b[j - 1]) {
                upd(j - 1, i + 1);
                break;
            }
        }
        if (a[j] == b[j]) {
            continue;
        }
        int was = 0;
        for (int i = j + 1; i < n && !was; i++) {
            if (a[i] == b[j] && a[i - 1] == b[j - 1]) {
                map<int, int> pos;
                for (int k = j; k < i; k++) {
                    pos[a[k]] = k;
                }
                for (int k = i; k < n && !was; k++) {
                    if (pos.find(a[k]) != pos.end()) {
                        upd(pos[a[k]], k);
                        was = 1;
                    }
                }
            }
        }
        for (int i = j + 1; i + 1 < n; i++) {
            if (a[i] == b[j] && a[i + 1] == b[j - 1]) {
                upd(j - 1, i + 1);
                break;
            }
        }
        if (a[j] == b[j]) {
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n" << (int) ans.size() << '\n';
    for (auto [l, r] : ans) {
        cout << l + 1 << " " << r + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}