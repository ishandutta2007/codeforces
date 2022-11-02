#include <stdio.h>

int a[100000][2];
int b[100001];

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        
        b[a[i][0]]++;
    }
    
    for (i = 0; i < n; i++) {
        int x = b[a[i][1]];
        
        printf("%d %d\n", n - 1 + x, n - 1 - x);
    }
    
    return 0;
}