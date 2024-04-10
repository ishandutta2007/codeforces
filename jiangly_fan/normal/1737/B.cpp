#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL l, r;
        cin >> l >> r;
        auto f = [&](LL n) {
            if (n == 0) return 0LL;
            LL L = 1, R = n;
            while (L < R) {
                LL M = (L + R + 1) / 2;
                auto sq = __int128_t(M) * M;
                if (sq <= n) L = M;
                else R = M - 1;
            }
            LL res = (L - 1) * 3;
            if (__int128_t(L) * L <= n) res += 1;
            if (__int128_t(L) * (L + 1) <= n) res += 1;
            if (__int128_t(L) * (L + 2) <= n) res += 1;
            return res;
        };
        cout << f(r) - f(l - 1) << "\n";
    }
}