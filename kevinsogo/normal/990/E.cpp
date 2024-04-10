#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1001111;
const ll INF = 1LL<<60;


int bak[N];
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++) bak[i] = i;
    for (int v; m--;) {
        scanf("%d", &v);
        bak[v] = -1;
    }
    int fd = -(1 << 30);
    for (int i = 0; i < n; i++) {
        bak[i] = fd = max(bak[i], fd);
    }

    ll ans = INF;
    if (bak[0] >= 0) for (int i = 1; i <= k; i++) {
        ll cost;
        scanf("%lld", &cost);
        int t = 0, pos = 0;
        while (true) {
            assert(0 <= pos && pos < n);
            assert(bak[pos] == pos);
            t++;
            int npos = pos + i;
            if (npos >= n) break;
            if (pos == bak[npos]) {
                t = -1;
                break;
            }
            pos = bak[npos];
        }
        if (t != -1) ans = min(ans, cost * t);
    }

    printf("%lld\n", ans < INF ? ans : -1LL);
}