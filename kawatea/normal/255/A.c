#include <stdio.h>

int main()
{
    int n, i;
    int a[3] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[i % 3] += x;
    }
    
    if (a[0] > a[1] && a[0] > a[2]) {
        puts("chest");
    } else if (a[1] > a[0] && a[1] > a[2]) {
        puts("biceps");
    } else {
        puts("back");
    }
    
    return 0;
}