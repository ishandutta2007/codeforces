#include <stdio.h>

int main()
{
    int n, i;
    int a[7] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x - 1]++;
    }
    
    if (a[0] != n / 3 || a[4] > 0 || a[6] > 0 || a[1] < a[3] || a[1] + a[2] != a[3] + a[5]) {
        puts("-1");
        
        return 0;
    }
    
    while (a[3] > 0) {
        puts("1 2 4");
        
        a[0]--;
        a[1]--;
        a[3]--;
    }
    
    while (a[1] > 0) {
        puts("1 2 6");
        
        a[0]--;
        a[1]--;
        a[5]--;
    }
    
    while (a[2] > 0) {
        puts("1 3 6");
        
        a[0]--;
        a[2]--;
        a[5]--;
    }
    
    return 0;
}