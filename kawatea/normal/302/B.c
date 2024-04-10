#include <stdio.h>

int main()
{
    int n, m, sum = 0, i, j;
    int a[100000];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        a[i] = x * y;
    }
    
    for (i = 0, j = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        while (sum < x) sum += a[j++];
        
        printf("%d\n", j);
    }
    
    return 0;
}