#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
typedef long long ll;

int n;
ll k, x, a[N], pre[N], suf[N];

int main() {
    scanf("%d%lld%lld", &n, &k, &x);
    ll mul = 1;
    for (int i = 0; i < k; i++)
        mul *= x;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] | a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pre[i - 1] | a[i] * mul | suf[i + 1]);
    }
    printf("%lld\n", ans);
    return 0;
}