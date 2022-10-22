#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 500005;

int l, r, m;

int32_t main() {
    boost();

    int t;
    cin >> t;
    outer: while (t--) {
    cin >> l >> r >> m;
    for (int i = l; i <= r; i++) {
        int a = i;
        int rem = m % a, div = m / a;
        if (!div) rem -= a, div++;
        //printf("%lld\n", rem);
        if (rem >= 0 && rem <= r - l) {
            int b = l + rem, c = l;
            assert(a * div + b - c == m);
            printf("%lld %lld %lld\n", a, b, c);
            goto outer;
        } else if (rem <= 0 && rem >= l - r) {
            //printf("here");
            int b = l, c = l - rem;
            assert(a * div + b - c == m);
            printf("%lld %lld %lld\n", a, b, c);
            goto outer;
        }

        rem -= a; div++;
        if (rem >= 0 && rem <= r - l) {
            int b = l + rem, c = l;
            assert(a * div + b - c == m);
            printf("%lld %lld %lld\n", a, b, c);
            goto outer;
        } else if (rem <= 0 && rem >= l - r) {
            //printf("here");
            int b = l, c = l - rem;
            assert(a * div + b - c == m);
            printf("%lld %lld %lld\n", a, b, c);
            goto outer;
        }

        rem -= a; div++;
        if (rem >= 0 && rem <= r - l) {
            int b = l + rem, c = l;
            assert(a * div + b - c == m);
            printf("%lld %lld %lld\n", a, b, c);
            goto outer;
        } else if (rem <= 0 && rem >= l - r) {
            //printf("here");
            int b = l, c = l - rem;
            assert(a * div + b - c == m);
            printf("%lld %lld %lld\n", a, b, c);
            goto outer;
        }

        rem -= a; div++;
        if (rem >= 0 && rem <= r - l) {
            int b = l + rem, c = l;
            assert(a * div + b - c == m);
            printf("%lld %lld %lld\n", a, b, c);
            goto outer;
        } else if (rem <= 0 && rem >= l - r) {
            //printf("here");
            int b = l, c = l - rem;
            assert(a * div + b - c == m);
            printf("%lld %lld %lld\n", a, b, c);
            goto outer;
        }
    }
    assert(0);
}

    return 0;
}