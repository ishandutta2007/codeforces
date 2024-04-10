#include <stdio.h>

int main()
{
    int n, l, r, i;
    int a[1000];
    int b[2] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    l = 0, r = n - 1;
    
    for (i = 0; i < n; i++) {
        if (a[l] > a[r]) {
            b[i % 2] += a[l++];
        } else {
            b[i % 2] += a[r--];
        }
    }
    
    printf("%d %d\n", b[0], b[1]);
    
    return 0;
}