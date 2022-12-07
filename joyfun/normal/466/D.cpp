#include <cstdio>
#include <cstring>

typedef long long ll;
const int MOD = 1000000007;

const int N = 2005;
int n, h, a[N], b[N];

int main() {
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] = h - a[i];
    for (int i = 1; i <= n + 1; i++) b[i] = a[i] - a[i -1];
    int ans = 1, cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (b[i] == 0) ans = (ll)ans * (cnt + 1) % MOD;
        else if (b[i] == 1) cnt++;
        else if (b[i] == -1) ans = (ll)ans * cnt % MOD, cnt--;
        else ans = 0;
    }
    printf("%d\n", ans);
    return 0;
}