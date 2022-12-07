#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int N = 100005;
int n;
long long k, a[N], b[N];

bool judge(long long mid) {
    long long sb = k;
    for (int i = 1; i <= n; i++) {
        if (a[i] * mid - b[i] <= 0) continue;
        sb -= a[i] * mid - b[i];
        if (sb < 0) return false;
    }
    return true;
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    long long l = 0, r = 2000000001LL;
    while (l < r) {
        long long mid = (l + r)>>1;
        if (judge(mid)) l = mid + 1;
        else r = mid;
    }
    printf("%d\n", l - 1);
    return 0;
}