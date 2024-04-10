#include <stdio.h>
#include <math.h>

int a[1000001];

int main()
{
    int n, i, j;
    
    a[0] = a[1] = 1;
    
    for (i = 4; i <= 1000000; i += 2) a[i] = 1;
    
    for (i = 3; i <= 1000000; i += 2) {
        if (a[i] == 0) {
            for (j = i * 2; j <= 1000000; j += i) a[j] = 1;
        }
    }
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        long long x, y;
        
        scanf("%I64d", &x);
        
        y = sqrt(x);
        
        if (a[y] == 0 && y * y == x) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}