#include <cstdio>
#include <algorithm>
using namespace std;
int a[5000];
int f[5000][5000];
int ans[5000][5000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        f[i][i] = ans[i][i] = a[i];

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++) {
            f[i][j] = f[i + 1][j] ^ f[i][j - 1];
            ans[i][j] = max(f[i][j], max(ans[i + 1][j], ans[i][j - 1]));
        }

    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        printf("%d\n", ans[l][r]);
    }
}