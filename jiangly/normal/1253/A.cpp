#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout << "NO" << "\n";
            return;
        }
        if (a[i] < b[i]) {
            if (x == 0)
                x = b[i] - a[i];
            if (b[i] - a[i] != x) {
                cout << "NO" << "\n";
                return;
            }
        } else if (x != 0) {
            x = -1;
        }
    }
    cout << "YES" << "\n";
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