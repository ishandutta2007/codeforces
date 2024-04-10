#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int n;
long long a[N], k;
long long need[N];
bool vis[N];

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i <= n; i++) {
        scanf("%lld", &a[i]);
        vis[i] = 0;
    }
    vis[0] = 1;
    long long pre = a[0];
    for (int i = 1; i <= n; i++) {
        if (pre % 2) break;
        need[i] = pre / 2;
        pre = pre / 2 + a[i];
        vis[i] = 1;
    }
    pre = 0;
    int ans = 0;
    for (int i = n; i >= 0; i--) {
        pre *= 2;
        if (max(pre, -pre) > k * n) break;
        if (vis[i]) {
            long long sb = -(pre + need[i]);
            if (max(sb, -sb) <= k && (i != n || sb != 0)) ans++;
        }
        pre += a[i];
    }
    printf("%d\n", ans);
    return 0;
}