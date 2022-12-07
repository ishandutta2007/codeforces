#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, f[N];

int main() {
    scanf("%d", &n);
    int v;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v);
        f[v] = i;
    }
    long long ans = 0;
    for (int i = 2; i <= n; i++) ans += max(f[i - 1] - f[i], f[i] - f[i - 1]);
    printf("%lld\n", ans);
    return 0;
}