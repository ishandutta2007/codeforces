#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 300005;
int n, k, a[N], sum[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1];
        if (a[i] == 0) sum[i]++;
    }
    int l = 1;
    int ans = 0, ll, rr;
    for (int r = 1; r <= n; r++) {
        while (sum[r] - sum[l - 1] > k) l++;
        if (ans < r - l + 1) {
            ans = r - l + 1;
            ll = l, rr = r;
        }
    }
    printf("%d\n", ans);
    for (int i = ll; i <= rr; i++) a[i] = 1;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
    return 0;
}