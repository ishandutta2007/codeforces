#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll c, hr, hb, wr, wb;

int main() {
    scanf("%lld%lld%lld%lld%lld", &c, &hr, &hb, &wr, &wb);
    ll ans = 0;
    for (int i = 0; i <= 100000; i++) {
        if (wr * i <= c) {
            ans = max(ans, i * hr + (c - wr * i) / wb * hb);
        }
        if (wb * i <= c) {
            ans = max(ans, i * hb + (c - wb * i) / wr * hr);
        }
    }
    printf("%lld\n", ans);
    return 0;
}