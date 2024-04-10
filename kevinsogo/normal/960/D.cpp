#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int D = 66;

ll depth(ll x) {
    // assert(x >= 1);
    // return 0 if x == 1 else depth(x >> 1) + 1;
    return x == 1 ? 0 : depth(x >> 1) + 1;
}

ll cyc[D];
ll get(int d, ll x) {
    ll mn = 1LL << d;
    // assert(0 <= x && x < mn);
    return mn + (x - cyc[d] & mn - 1);
}
ll pos(int d, ll x) {
    ll mn = 1LL << d;
    return x + cyc[d] & mn - 1;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int typ;
        scanf("%d", &typ);
        if (typ == 1) {
            ll x, k;
            scanf("%lld%lld", &x, &k);
            x = depth(x);
            cyc[x] += k;
        } else if (typ == 2) {
            ll x, k;
            scanf("%lld%lld", &x, &k);
            x = depth(x);
            for (; x < D; x++, k <<= 1) {
                cyc[x] += k;
            }
        } else {
            ll x;
            scanf("%lld", &x);
            int d = depth(x);
            x = pos(d, x);
            while (d > 0) {
                printf("%lld ", get(d, x));
                d--;
                x >>= 1;
            }
            printf("1\n");
        }
    }
}