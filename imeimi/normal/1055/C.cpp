#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

llong gcd(llong x, llong y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    llong la, ra, ta;
    llong lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    if (la > lb) {
        swap(la, lb);
        swap(ra, rb);
        swap(ta, tb);
    }
    ra -= la;
    lb -= la;
    rb -= la;
    la = 0;
    llong g = gcd(ta, tb);
    llong ans = 0;
    for (int i = -500000; i < 500000; ++i) {
        llong x = lb / g + i;
        ans = max(ans, min(ra, rb - x * g) - max(la, lb - x * g) + 1);
    }
    for (int i = -500000; i < 500000; ++i) {
        llong x = (rb - ra) / g + i;
        ans = max(ans, min(ra, rb - x * g) - max(la, lb - x * g) + 1);
    }
    printf("%lld\n", ans);
    return 0;

}