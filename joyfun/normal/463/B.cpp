#include <cstdio>
#include <cstring>

const int N = 100005;
typedef long long ll;

int n;
ll h[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &h[i]);
    ll now = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] > h[i - 1]) {
            ll need = h[i] - h[i - 1];
            if (now >= need) {
                now -= need;
            } else {
                ans += need - now;
                now = 0;
            }
        } else {
            now += h[i - 1] - h[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}