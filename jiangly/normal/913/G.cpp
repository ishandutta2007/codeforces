#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 P = 762939453125;

i64 pw[18], p[18];

i64 mul(i64 a, i64 b) {
    return __int128(a) * b % P;
}

void solve() {
    i64 a;
    std::cin >> a;
    a *= 1000000;
    a += 131072 - a % 131072;
    if (a % 5 == 0) {
        a += 131072;
    }
    a %= P;
    
    i64 v = 1;
    i64 ans = 0;
    while (v % 5 != a % 5) {
        v *= 2;
        ans++;
    }
    for (int i = 2; i <= 17; i++) {
        while (v % p[i] != a % p[i]) {
            v = mul(v, pw[i - 2]);
            ans += p[i - 2] * 4;
        }
    }
    
    ans += p[16] * 4;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    pw[0] = 16;
    p[0] = 1;
    for (int i = 1; i <= 17; i++) {
        p[i] = p[i - 1] * 5;
        pw[i] = 1;
        for (int j = 0; j < 5; j++) {
            pw[i] = mul(pw[i], pw[i - 1]);
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}