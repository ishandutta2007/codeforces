#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<ll> a(n), s(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s[i + 1] = s[i] + a[i];
    }
    ll extra = 0;
    int pos = 0;
    while (q--) {
        ll k;
        scanf("%lld", &k);
        k += extra;
        int L = pos, R = n + 1;
        while (R - L > 1) {
            assert(s[L] - s[pos] <= k && (R == n + 1 || k < s[R] - s[pos]));
            int M = L + R >> 1;
            (s[M] - s[pos] <= k ? L : R) = M;
        }
        extra = k - (s[L] - s[pos]);
        if ((pos = L) == n) {
            extra = 0;
            pos = 0;
        }
        printf("%d\n", n - pos);
    }
}