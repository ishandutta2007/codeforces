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

int n, k;
int par[100001];

int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int ans = 0;
    while (k--) {
        int x, y;
        cin >> x >> y;
        x = find(x);
        y = find(y);
        if (x == y) {
            ++ans;
            continue;
        }
        par[y] = x;
    }
    printf("%d\n", ans);
    return 0;
}