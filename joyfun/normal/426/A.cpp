#include <stdio.h>
#include <string.h>

int n, s, a, sum = 0, Max = 0;

int main() {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        sum += a;
        if (Max < a) Max = a;
    }
    if (s >= sum - Max) printf("YES\n");
    else printf("NO\n");
    return 0;
}