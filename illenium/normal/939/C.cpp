#include <stdio.h>
#define MAX_N 100005

int a[MAX_N];

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i % n]);
    int s, f;
    scanf("%d%d", &s, &f);
    int cur = 0;
    for (int i = s; i <= f; i++)
        cur += a[i % n];
    int argmax = -1, max = 0;
    for (int i = 0; i < n; i++) {
        int l = (s - i + n) % n;
        int r = (f - i + n) % n;
        cur -= a[r];
        cur += a[l];
        if (cur > max) {
            max = cur;
            argmax = i;
        }
    }
    printf("%d\n", argmax + 1);
    return 0;
}