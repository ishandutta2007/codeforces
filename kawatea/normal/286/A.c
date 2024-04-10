#include <stdio.h>

int main()
{
    int n, i;
    int a[100000];
    
    scanf("%d", &n);
    
    if (n % 4 >= 2) {
        puts("-1");
    } else {
        for (i = 0; i < n / 2; i += 2) a[i] = i + 2;
        for (i = 0; n - i - 2 >= n / 2; i += 2) a[n - i - 2] = i + 1;
        for (i = 0; i + 1 < n / 2; i += 2) a[i + 1] = n - i;
        for (i = 0; n - i - 1 >= n / 2; i += 2) a[n - i - 1] = n - i - 1;
        
        if (n % 4 == 1) a[n / 2] = n / 2 + 1;
        
        for (i = 0; i < n; i++) {
            if (i > 0) putchar(' ');
            
            printf("%d", a[i]);
        }
        
        puts("");
    }
    
    return 0;
}