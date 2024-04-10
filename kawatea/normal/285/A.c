#include <stdio.h>

int main()
{
    int n, k, p = 0, i;
    int a[100000];
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < k; i++) a[p++] = n - i;
    for (i = 0; i < n - k; i++) a[p++] = i + 1;
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}