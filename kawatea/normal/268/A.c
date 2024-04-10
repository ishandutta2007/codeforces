#include <stdio.h>

int main()
{
    int n, sum = 0, i, j;
    int a[30][2];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (a[i][0] == a[j][1]) sum++;
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}