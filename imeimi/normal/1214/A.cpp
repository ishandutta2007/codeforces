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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d, e;
    cin >> n >> d >> e;
    int ans = n;
    for (int i = 0; i <= n; ++i) {
        int dd = i / d;
        int ee = (n - i) / e / 5;
        ans = min(ans, n - dd * d - ee * e * 5);
    }
    printf("%d\n", ans);
    return 0;
}