#include <cstdio>

const int N = 105;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = n;
    while (l <= n && a[l] == 0) l++;
    while (r >= 1 && a[r] == 0) r--;
    if (l > r) {
        printf("0\n");
        return 0;
    }
    int cnt = 0;
    long long  ans = 1;
    for (int i = l; i <= r; i++) {
        if (a[i] == 0) cnt++;
        else {
            ans *= (cnt + 1);
            cnt = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}