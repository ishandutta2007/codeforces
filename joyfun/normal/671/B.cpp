#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500005;

int n, k, c[N];

long long cal(int x) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] >= x) ans += c[i] - x;
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    long long tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        tot += c[i];
    }
    sort(c + 1, c + 1 + n);
    long long sb = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= n - tot % n) {
            sb += max(c[i] - tot / n, tot / n - c[i]);
        } else {
            sb += max(c[i] - tot / n - 1, tot / n + 1 - c[i]);
        }
    }
    k = min(1LL * k, sb / 2);
   // printf("%d\n", k);
    int l = 0, r = 1000000000;
    while (l < r) {
        int mid = (l + r)>>1;
        if (cal(mid) > k) l = mid + 1;
        else r = mid;
    }
    long long sum = cal(l);
    int yu = k - sum;
    for (int i = 1; i <= n; i++) {
        if (c[i] >= l) c[i] = l;
    }
    for (int i = n; i > n - yu; i--) c[i]--;
    sort(c + 1, c + 1 + n);
    int Min = l;
   // printf("%d\n", l);
   // for (int i = 1; i <= n; i++) printf("%d ", c[i]); printf("\n");
    for (int i = 2; i <= n; i++) {
        if (c[i] != c[i - 1]) {
            long long nd = 1LL * (c[i] - c[i - 1]) * (i - 1);
            if (k < nd) {
                Min = c[i - 1] + k / (i - 1);
                break;
            } else k -= nd;
        }
    }
    printf("%d\n", l - Min);
    return 0;
}