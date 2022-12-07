#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef __int64 ll;
const int N = 100005;
ll x, k, frac[N], fn = 0;

void tra(ll x) {
    ll m = (ll)sqrt(x);
    for (ll i = 1; i <= m; i++) {
        if (x % i) continue;
        frac[fn++] = i;
        if (x / i != i) frac[fn++] = x / i;
    }
    sort(frac, frac + fn);
}

ll s = 0;

void dfs(ll x, ll k) {
    if (s >= 100000) return;
    if (k == 0 || x == 1) {
        printf("%I64d ", x);
        s++;
        return;
    }
    for (ll i = 0; i < fn && frac[i] <= x; i++) {
        if (x % frac[i]) continue;
        dfs(frac[i], k - 1);
        if (s >= 100000) return;
    }
}

int main() {
    scanf("%I64d%I64d", &x, &k);
    tra(x);
    dfs(x, k);
    return 0;
}