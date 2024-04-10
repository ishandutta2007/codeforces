#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
typedef long long ll;

int n, k, a, b, q;

#define lowbit(x) (x&(-x))

struct BIT {
    ll bit[N];

    void add(int x, int v) {
        while (x <= n) {
            bit[x] += v;
            x += lowbit(x);
        }
    }

    ll get(int x) {
        ll ans = 0;
        while (x) {
            ans += bit[x];
            x -= lowbit(x);
        }
        return ans;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
} A, B;

int main() {
    scanf("%d%d%d%d%d", &n, &k, &b, &a, &q);
    int tp, d, p;
    while (q--) {
        scanf("%d%d", &tp, &d);
        if (tp == 1) {
            scanf("%d", &p);
            ll ta = A.get(d, d), tb = B.get(d, d);
            A.add(d, min(a, (int)ta + p) - ta);
            B.add(d, min(b, (int)tb + p) - tb);
        } else {
            printf("%lld\n", A.get(d - 1) + B.get(d + k, n));
        }
    }
    return 0;
}