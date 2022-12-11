#include <algorithm>
#include <cstdio>
using namespace std;

const int mo = 1e9 + 7;
const int N = 1e6 + 10;

int pl[N], pr[N], fac[N];

int qpow(int a, int b) {
    int ans = 1;
    for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
        if(b & 1) ans = 1ll * ans * a % mo;
    return ans;
}

int main() {
    int n, k, y = 0, ans = 0;
    scanf("%d%d", &n, &k);
    pl[0] = pr[k + 3] = fac[0] = 1;
    for(int i = 1; i <= k + 2; i ++)
        pl[i] = 1ll * pl[i - 1] * (n - i) % mo;
    for(int i = k + 2; i >= 1; i --)
        pr[i] = 1ll * pr[i + 1] * (n - i) % mo;
    for(int i = 1; i <= k + 2; i ++)
        fac[i] = 1ll * fac[i - 1] * i % mo;
    for(int i = 1; i <= k + 2; i ++) {
        y = (y + qpow(i, k)) % mo;
        int a = pl[i - 1] * 1ll * pr[i + 1] % mo;
        int b = fac[i - 1] * ((k - i) & 1 ? -1ll : 1ll) * fac[k + 2 - i] % mo;
        ans = (ans + 1ll * y * a % mo * qpow(b, mo - 2) % mo) % mo;
    }
    printf("%d\n", (ans + mo) % mo);
    return 0;
}