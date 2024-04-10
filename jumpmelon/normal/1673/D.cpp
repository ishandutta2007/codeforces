#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int P = 1000000007;

big lcm(big x, big y) {
    return x / __gcd(x, y) * y;
}

int check(big p, big b, big q, big y, big c, big r, big z) {
    if (lcm(p, q) != r)
        return 0;
    return int((r / p) % P * (r / p) % P);
}

int solve(big b, big q, big y, big c, big r, big z) {
    if (r % q != 0 || (c - b) % q != 0)
        return 0;
    if (c < b || ((c + (z - 1) * r) - b) / q >= y)
        return 0;
    if (c - r < b || (c + z * r - b) / q >= y)
        return -1;
    int ans = 0;
    for (big t = 1; t * t <= r; t++)
        if (r % t == 0) {
            ans = (ans + check(t, b, q, y, c, r, z)) % P;
            if (r != t * t)
                ans = (ans + check(r / t, b, q, y, c, r, z)) % P;
        }
    return ans;
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int b, q, y;
        int c, r, z;
        scanf("%d%d%d", &b, &q, &y);
        scanf("%d%d%d", &c, &r, &z);
        printf("%d\n", solve(b, q, y, c, r, z));
    }
    return 0;
}