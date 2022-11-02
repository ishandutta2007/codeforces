#include <stdio.h>

int main()
{
    int a, b, n, p, i, j;
    int c[100000];
    
    scanf("%d %d %d", &a, &b, &n);
    
    p = a % b;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 10; j++) {
            int x = p * 10 + j;
            
            if (x % b == 0) break;
        }
        
        if (j < 10) {
            c[i] = j;
            
            p = 0;
        } else {
            puts("-1");
            
            return 0;
        }
    }
    
    printf("%d", a);
    
    for (i = 0; i < n; i++) printf("%d", c[i]);
    
    puts("");
    
    return 0;
}