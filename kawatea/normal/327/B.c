#include <stdio.h>

int a[2000000];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 4; i < 2000000; i += 2) a[i] = 1;
    
    printf("2");
    
    n--;
    
    for (i = 3; n > 0; i += 2) {
        if (a[i] == 0) {
            printf(" %d", i);
            
            n--;
            
            for (j = i * 2; j < 2000000; j += i) a[j] = 1;
        }
    }
    
    puts("");
    
    return 0;
}