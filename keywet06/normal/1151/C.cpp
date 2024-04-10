#include <bits/stdc++.h>
using int64 = long long;
const int N = 61;
const int mod = 1e9 + 7;
int64 l, r;
int64 p[N], s[N], l1[N], l2[N];
int64 calc(int64 x) {
    for (int i = 60; i >= 0; i--) {
        if (p[i] <= x) {
            return (s[i] + (((i & 1 ? l2 : l1)[i] + x - p[i] - 1) % mod) *
                               ((x - p[i]) % mod)) %
                   mod;
        }
    }
    return 0;
}
void pre() {
    int64 lst1 = 1, lst2 = 2;
    l1[0] = 1, l2[0] = 2;
    for (int i = 1; i <= 60; i++) {
        p[i] = p[i - 1] + (1ll << (i - 1));
        if (i & 1) {
            s[i] = (s[i - 1] + ((lst1 + (1ll << i - 1) - 1) % mod) *
                                   ((1ll << i - 1) % mod)) %
                   mod;
            lst1 += 1ll << i;
        } else {
            s[i] = (s[i - 1] + ((lst2 + (1ll << i - 1) - 1) % mod) *
                                   ((1ll << i - 1) % mod)) %
                   mod;
            lst2 += 1ll << i;
        }
        l1[i] = lst1, l2[i] = lst2;
    }
}
int main() {
    pre();
    std::cin >> l >> r;
    std::cout << ((calc(r) - calc(l - 1)) % mod + mod) % mod << std::endl;
    return 0;
}