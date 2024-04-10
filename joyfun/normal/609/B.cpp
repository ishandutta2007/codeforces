#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 15;

int n, m, cnt[N];

int main() {
    scanf("%d%d", &n, &m);
    int x;
    while (n--) {
        scanf("%d", &x);
        cnt[x]++;
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++)
            ans += 1LL * cnt[i] * cnt[j];
    }
    printf("%lld\n", ans);
    return 0;
}