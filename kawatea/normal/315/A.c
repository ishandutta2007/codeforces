#include <stdio.h>

int main()
{
    int n, sum = 0, i, j;
    int a[100];
    int b[100];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (a[i] == b[j]) {
                sum++;
                
                break;
            }
        }
    }
    
    printf("%d\n", n - sum);
    
    return 0;
}