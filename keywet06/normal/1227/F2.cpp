#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = 1LL * result * base % P;
        base = 1LL * base * base % P;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    vector<int> factorial(n + 1), inv_factorial(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) factorial[i] = 1LL * factorial[i - 1] * i % P;
    inv_factorial[n] = power(factorial[n], P - 2);
    for (int i = n; i >= 1; --i)
        inv_factorial[i - 1] = 1LL * inv_factorial[i] * i % P;
    int cnt = n, total = power(k, n), tmp = 1;
    for (int i = 0; i < n; ++i) {
        if (h[i] == h[(i + 1) % n]) {
            --cnt;
            tmp = 1LL * tmp * k % P;
        }
    }
    auto binom = [&](int n, int m) {
        return 1LL * factorial[n] * inv_factorial[m] % P *
               inv_factorial[n - m] % P;
    };
    int res = 0;
    for (int i = 0; i <= cnt; i += 2) {
        res = (res + 1LL * binom(cnt, i / 2) * binom(cnt - i / 2, i / 2) % P *
                         power(k - 2, cnt - i)) %
              P;
    }
    int ans = (total - 1LL * tmp * res) % P;
    ans = 1LL * (ans + P) * power(2, P - 2) % P;
    cout << ans << endl;
    return 0;
}