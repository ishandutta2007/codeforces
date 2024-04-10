#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int a[200000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", a + i);

    sort(a, a + 2 * n);

    long long ans = (long long) (a[n - 1] - a[0]) *
        (a[2 * n - 1] - a[n]);

    for (int i = 1; i < n; i++)
        ans = min(ans, (long long) (a[2 * n - 1] - a[0]) *
                (a[i + n - 1] - a[i]));

    printf("%lld\n", ans);
}