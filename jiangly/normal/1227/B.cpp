#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; ++i)
        cin >> q[i];
    for (int i = 0; i < n; ++i) {
        if (q[i] <= i || i > 0 && q[i] < q[i - 1]) {
            cout << -1 << "\n";
            return;
        }
    }
    vector<int> p(n);
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0 || q[i] != q[i - 1]) {
            p[i] = q[i];
            used[p[i] - 1] = true;
        }
    }
    for (int i = 0, j = 0; i < n; ++i) {
        if (p[i] == 0) {
            while (used[j])
                ++j;
            p[i] = ++j;
        }
    }
    for (int i : p)
        cout << i << " \n"[i == p.back()];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}