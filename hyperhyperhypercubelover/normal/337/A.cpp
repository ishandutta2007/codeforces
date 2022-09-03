#include <cstdio>
#include <algorithm>

using namespace std;

int a[50];

int main() {
    int i, j, n, m, r;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) scanf("%d", &a[i]);
    sort(a, a + m);
    r = a[n - 1] - a[0];
    for (i = n; i < m; i++) r = min(r, a[i] -a[i - n + 1]);
    printf("%d", r);
}