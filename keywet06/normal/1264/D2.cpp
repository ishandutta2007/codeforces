#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int power(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) ret = 1LL * ret * a % P;
        a = 1LL * a * a % P, b >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> fac(n + 1), invFac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % P;
    invFac[n] = power(fac[n], P - 2);
    for (int i = n; i >= 1; --i) invFac[i - 1] = 1LL * invFac[i] * i % P;
    auto binom = [&](int n, int m) {
        return 1LL * fac[n] * invFac[m] % P * invFac[n - m] % P;
    };
    int q = count(s.begin(), s.end(), '?');
    vector<int> s1(q + 1), s2(q);
    for (int i = 0; i <= q; ++i) s1[i] = binom(q, i);
    for (int i = q - 1; i >= 0; --i) s1[i] = (s1[i] + s1[i + 1]) % P;
    for (int i = 0; i < q; ++i) s2[i] = binom(q - 1, i);
    for (int i = q - 2; i >= 0; --i) s2[i] = (s2[i] + s2[i + 1]) % P;
    int ans = 0;
    int l = -count(s.begin() + 1, s.end(), ')');
    for (int i = 1; i < n; ++i) {
        l += s[i - 1] != ')';
        if (s[i - 1] == '(' && l <= q) ans = (ans + s1[max(0, l)]) % P;
        if (s[i - 1] == '?' && l < q) ans = (ans + s2[max(0, l)]) % P;
        l += s[i] == ')';
    }
    cout << ans << endl;
    return 0;
}