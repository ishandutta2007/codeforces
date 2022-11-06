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

int n;
llong B[200001];
vector<llong> V[70];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> B[i];
        int cnt = 0;
        for (llong x = B[i]; (x & 1) == 0; x >>= 1) ++cnt;
        V[cnt].push_back(B[i]);
    }
    pii mx = pii(V[0].size(), 0);
    for (int i = 0; i < 70; ++i) {
        mx = max(mx, pii(V[i].size(), i));
    }
    printf("%d\n", n - mx.fs);
    for (int i = 0; i < 70; ++i) {
        if (i == mx.se) continue;
        for (llong j : V[i]) printf("%lld ", j);
    }
    return 0;
}