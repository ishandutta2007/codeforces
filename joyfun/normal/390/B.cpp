#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 100005;
__int64 a[N], b[N];
int n, i;
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%I64d", &b[i]);
    __int64 ans = 0;
    for (i = 0; i < n; i++) {
        if (a[i] * 2 < b[i]) ans--;
        else if (b[i] == 1) ans--;
        else ans += (b[i] / 2) * (b[i] - b[i] / 2);
    }
    printf("%I64d\n", ans);
    return 0;
}