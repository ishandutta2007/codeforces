#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n;
int k;
LL f(LL n) {
    if (n == 0)
        return 1LL * k * (k + 1) / 2;
    LL i = n / k;
    LL x = f(i);
    int t = n % k;
    LL r = i * (1LL * k * k + 1) + 1LL * (t + 1) * k;
    return (1LL * k * i + t) * (1LL * k * k + 1) + 1LL * k * (k + 1) / 2 - t + max(0LL, min(1LL * k, r - x + 1));
}
void solve() {
    cin >> n >> k;
    LL bl = (n - 1) / (1LL * k * k + 1);
    LL x = f(bl);
    if (x == n) {
        cout << (k + 1) * (bl + 1) << "\n";
    } else {
        LL m = n - bl - (x < n) - 1;
        cout << m / k * (k + 1) + m % k + 1 << "\n";
    }
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