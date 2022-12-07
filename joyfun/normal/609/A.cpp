#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;

int n, m, a[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int ans = 0, sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans++;
        sum += a[i];
        if (sum >= m) break;
    }
    printf("%d\n", ans);
    return 0;
}