#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

llong solve() {
    llong n, m;
    cin >> n >> m;
    n /= m;
    llong ret = 0;
    for (int i = 1; i <= 10 && i <= n; ++i) {
        llong cnt = (n - i) / 10 + 1;
        ret += (i * m % 10) * cnt;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) printf("%lld\n", solve());
    return 0;
}