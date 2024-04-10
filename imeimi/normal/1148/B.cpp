#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n, m, k, ta, tb;
int A[200001];
int B[200001];

bool check(llong x) {
    if (min(n, m) <= k) return 1;
    int Bmx = 0;
    for (int i = 1; i <= m; ++i) {
        if (B[i] + tb < x) Bmx = i;
    }
    for (int i = 1; i <= n; ++i) {
        int Ad = A[i] + ta;
        int j = lower_bound(B + 1, B + m + 1, Ad) - B;
        int er = (i - 1) + max(Bmx - j + 1, 0);
        if (er <= k) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= m; ++i) cin >> B[i];
    llong s = 0, e = 1e10;
    while (s < e) {
        llong m = (s + e + 1) / 2;
        if (check(m)) s = m;
        else e = m - 1;
    }
    printf("%lld\n", s > 9e9 ? -1ll : s);
    return 0;
}