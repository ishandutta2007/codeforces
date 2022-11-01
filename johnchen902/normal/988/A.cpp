#include <cstdio>
#include <algorithm>
using namespace std;
int a[100], b[100];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int m = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (find(a, a + m, x) == a + m)
            a[m] = x, b[m] = i, m++;
    }

    if (m >= k) {
        puts("YES");
        for (int i = 0; i < k; i++)
            printf("%d%c", b[i], i == k - 1 ? '\n' : ' ');
    } else {
        puts("NO");
    }
}