#include <cstdio>
#include <cstring>

const int N = 500005;

typedef long long ll;

int n;
ll a[N], pres[N], prec[N], sufs[N], sufc[N];

int main() {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (sum % 3) printf("0\n");
    else {
        sum /= 3;
        for (int i = 1; i <= n; i++) {
            pres[i] = pres[i - 1] + a[i];
            if (pres[i] == sum)
                prec[i] = 1;
        }
        for (int i = n; i >= 1; i--) {
            sufs[i] = sufs[i + 1] + a[i];
            sufc[i] = sufc[i + 1];
            if (sufs[i] == sum) sufc[i]++;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans += prec[i] * sufc[i + 2];
        printf("%lld\n", ans);
    }
    return 0;
}