#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

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
    int n, q;
    cin >> n >> q;
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
    set<int> s{0, n};
    int ans = sumSuf[0];
    auto calc = [&](int l, int r) {
        return 1LL * (sumSuf[l] - sumSuf[r] + P) * suf[r] % P;
    };
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        --x;
        if (s.count(x)) {
            auto t = s.find(x);
            int l = *prev(t), r = *next(t);
            ans = (1LL * ans - calc(l, x) - calc(x, r) + calc(l, r) + 2 * P) % P;
            s.erase(t);
        } else {
            auto t = s.insert(x).first;
            int l = *prev(t), r = *next(t);
            ans = (1LL * ans - calc(l, r) + calc(l, x) + calc(x, r) + P) % P;
        }
        cout << ans << "\n";
    }
    return 0;
}