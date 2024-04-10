#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, k, w, i, sum[15][N], s[N];//sum1
char str[N];

int main() {
    scanf("%d%d%d", &n, &k, &w);
    scanf("%s", str + 1);
    for (i = 1; i <= n; i++) {
        s[i] = s[i - 1] + str[i] - '0';
    }
    for (i = 1; i <= k; i++) {
        for (int j = i - 1 + k; j <= n; j += k) {
            if (str[j] == '1') {
                sum[i][j] = sum[i][j - k] + 1;
            }
            else sum[i][j] = sum[i][j - k];
        }
    }
    int l,r;
    while (w--) {
        scanf("%d%d", &l, &r);
        int ll = l;
        l %= k; if (l == 0) l = k;
        int ss = sum[l][r] - sum[l][ll - 1];
        int sss = s[r] - s[ll - 1];
        int h = (r - ll + 1) / k;
        int ans = h - ss + (sss - ss);
        printf("%d\n", ans);
    }
    return 0;
}