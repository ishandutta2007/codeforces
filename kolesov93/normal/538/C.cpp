#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);
const int N = 100111;
ll d[N], h[N];

inline ll myabs(ll x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        int D, H;
        scanf("%d%d", &D, &H);
        d[i] = D; h[i] = H;
        ans = max(ans, h[i]);

        if (i) {
            ll len = d[i] - d[i - 1];
            ll diff = myabs(h[i] - h[i - 1]);
            if (diff > len) {
                puts("IMPOSSIBLE");
                return 0;
            }

            ll cur = h[i - 1];
            ll left = len;
            if (cur < h[i]) {
                cur = h[i];
                left -= diff;
                diff = 0;
            }

            ans = max(ans, cur + (left - diff) / 2);
        }
    }
    ans = max(ans, h[m - 1] + n - d[m - 1]);
    ans = max(ans, h[0] + d[0] - 1);
    cout << ans << endl;

    return 0;
}