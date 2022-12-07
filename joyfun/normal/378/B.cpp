#include <stdio.h>
#include <string.h>
const int N = 100005;
int n, a[N], b[N];
int an[N], bn[N];

void init() {
    scanf("%d", &n);
    memset(an, 0, sizeof(an));
    memset(bn, 0, sizeof(bn));
    for (int i = 0; i < n; i ++)
        scanf("%d%d", &a[i], &b[i]);
}

void solve() {
    int l = 0, r = 0, i;
    for (i = 0; i < n / 2; i ++)
        an[i] = bn[i] = 1;
    for (i = 0; i < n; i ++) {
        if (a[l] < b[r]) {
            an[l++] = 1;
        }
        else {
            bn[r++] = 1;
        }
    }
    for (i = 0; i < n; i ++)
        printf("%d", an[i]);
    printf("\n");
    for (i = 0; i < n; i ++)
        printf("%d", bn[i]);
    printf("\n");
}

int main() {
    init();
    solve();
    return 0;
}