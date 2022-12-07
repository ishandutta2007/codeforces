#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
int a, b, c, d, e;

int main() {
    int ans = 999999999;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    ans = min(ans, a/1);
    ans = min(ans, b/1);
    ans = min(ans, c/2);
    ans = min(ans, d/7);
    ans = min(ans, e/4);
    printf("%d\n", ans);
    return 0;
}