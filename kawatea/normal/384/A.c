#include <stdio.h>

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    printf("%d\n", (n * n + 1) / 2);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                putchar('C');
            } else {
                putchar('.');
            }
        }
        
        puts("");
    }
    
    return 0;
}