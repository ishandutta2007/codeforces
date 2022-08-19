#include <bits/stdc++.h>
using namespace std;
void solve() {
    int c, sum;
    cin >> c >> sum;
    int x = sum / c;
    int c1 = sum - x * c;
    cout << c1 * (x + 1) * (x + 1) + (c - c1) * x * x << "\n";
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