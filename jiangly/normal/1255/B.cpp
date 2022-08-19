#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1000;
int n, m;
void solve() {
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }
    if (n == 2 || m < n) {
        cout << -1 << "\n";
        return;
    }
    cout << 2 * sum << "\n";
    for (int i = 0; i < n; ++i)
        cout << i + 1 << " " << (i + 1) % n + 1 << "\n";
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