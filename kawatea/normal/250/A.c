#include <stdio.h>

int main()
{
    int n, p = 0, q = 0, i;
    int a[100];
    int b[100] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i] < 0) q++;
        
        if (q == 3) {
            p++;
            q = 1;
        }
        
        b[p]++;
    }
    
    printf("%d\n", p + 1);
    
    for (i = 0; i < p + 1; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", b[i]);
    }
    
    puts("");
    
    return 0;
}