#include <stdio.h>

int main()
{
    int n, m = 0, i;
    int a[1000] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        x--;
        
        a[x]++;
        
        if (a[x] > m) m = a[x];
    }
    
    if (m <= (n + 1) / 2) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}