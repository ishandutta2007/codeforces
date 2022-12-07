#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, h[N], l[N], r[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = 1; i <= n; i++)
        l[i] = min(h[i], l[i - 1] + 1);
    for (int i = n; i >= 1; i--)
        r[i] = min(h[i], r[i + 1] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = min(l[i], r[i]);
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}