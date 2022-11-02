#include <stdio.h>

int main()
{
    int n, i;
    int a[100000], b[100000], p[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    
    for (i = 0; i < n; i++) p[a[i] - 1] = b[i];
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", p[i]);
    }
    
    puts("");
    
    return 0;
}