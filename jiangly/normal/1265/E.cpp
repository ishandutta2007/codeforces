#include <bits/stdc++.h>
using namespace std;
constexpr int P = 998244353;
int power(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1)
            result = 1LL * result * a % P;
        a = 1LL * a * a % P;
        b >>= 1;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n), suf(n + 1), invSuf(n + 1), sumSuf(n + 1);
    int inv = power(100, P - 2);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] = 1LL * p[i] * inv % P;
    }
    suf[n] = 1;
    for (int i = n - 1; i >= 0; --i)
        suf[i] = 1LL * suf[i + 1] * p[i] % P;
    for (int i = 0; i <= n; ++i)
        invSuf[i] = power(suf[i], P - 2);
    for (int i = n - 1; i >= 0; --i)
        sumSuf[i] = (sumSuf[i + 1] + invSuf[i]) % P;
    int ans = sumSuf[0];
    cout << ans << "\n";
    return 0;
}