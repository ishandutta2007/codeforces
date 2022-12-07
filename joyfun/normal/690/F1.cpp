#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10005;
int n;
int cnt[N];

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        cnt[u]++; cnt[v]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}