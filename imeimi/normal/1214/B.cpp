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

const int inf = 1e8;
int b, g, n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> b >> g >> n;
    int ans = 0;
    for (int i = 0; i <= n && i <= b; ++i) {
        if (g < n - i) continue;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}