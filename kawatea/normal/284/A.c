#include <stdio.h>

int main()
{
    int sum = 0, p, i, j;
    
    scanf("%d", &p);
    
    for (i = 1; i < p; i++) {
        int x = i;
        
        for (j = 0; j < p - 2; j++) {
            if (x == 1) break;
            
            x = x * i % p;
        }
        
        if (j == p - 2) sum++;
    }
    
    printf("%d\n", sum);
    
    return 0;
}