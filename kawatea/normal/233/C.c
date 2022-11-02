#include <stdio.h>

int main()
{
    int k, c = 0, i, j;
    int a[100][100] = {0};
    
    scanf("%d", &k);
    
    for (i = 0; i < 100; i++) {
        for (j = 0; j < i; j++) {
            if (k < j) break;
            
            a[i][j] = a[j][i] = 1;
            
            k -= j;
        }
        
        c++;
        
        if (k == 0) break;
    }
    
    printf("%d\n", c);
    
    for (i = 0; i < c; i++) {
        for (j = 0; j < c; j++) {
            printf("%d", a[i][j]);
        }
        
        puts("");
    }
    
    return 0;
}