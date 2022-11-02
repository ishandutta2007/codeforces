#include <stdio.h>

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, sum = 0, i, j;
    int a[100];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int x = 0;
        
        for (j = i; j < n; j++) {
            x ^= a[j];
            
            sum = max(sum, x);
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}