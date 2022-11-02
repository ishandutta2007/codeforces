#include <stdio.h>

int a[100];
int b[100];

int main()
{
    int n, x, y, i;
    
    scanf("%d %d %d", &n, &x, &y);
    
    for (i = 0; i < x; i++) {
        int p;
        
        scanf("%d", &p);
        
        a[p - 1]++;
    }
    
    for (i = 0; i < y; i++) {
        int p;
        
        scanf("%d", &p);
        
        b[p - 1]++;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        if (a[i] > 0) {
            putchar('1');
        } else {
            putchar('2');
        }
    }
    
    puts("");
    
    return 0;
}