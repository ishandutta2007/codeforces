#include <stdio.h>

int main()
{
    int a = 0, b = 0, n, i;
    
    for (i = 0; i < 3; i++) {
        int x;
        
        scanf("%d", &x);
        
        a += x;
    }
    
    for (i = 0; i < 3; i++) {
        int x;
        
        scanf("%d", &x);
        
        b += x;
    }
    
    scanf("%d", &n);
    
    if ((a + 4) / 5 + (b + 9) / 10 <= n) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}