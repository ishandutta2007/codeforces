// write in C...
#include <stdio.h>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

int n, s[1005];

int main() {
    scanf("%d", &n);
    int i = 0, j;
    for (j = 0; j < 1000010; j++) {
        s[i] = 1;
        i = (i+j) % n;
    }
    for (i = 0; i < n; i++) if (!s[i]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
}