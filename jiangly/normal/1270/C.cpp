#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
        x ^= a;
    }
    cout << 2 << "\n";
    cout << x << " " << sum + x << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}