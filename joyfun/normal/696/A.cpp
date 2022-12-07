#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int q;
long long tp, u, v, w;
map<long long, long long> cnt;
const long long INF = 100000000000000000LL;

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%lld%lld%lld", &tp, &u, &v);
        if (tp == 1) {
            scanf("%lld", &w);
            while (u != v) {
                if (u > v) {
                    cnt[u] += w;
                    u /= 2;
                } else {
                    cnt[v] += w;
                    v /= 2;
                }
            }
        } else {
            long long ans = 0;
            while (u != v) {
                if (u > v) {
                    ans += cnt[u];
                    u /= 2;
                } else {
                    ans += cnt[v];
                    v /= 2;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}