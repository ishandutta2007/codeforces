#include <stdio.h>

int main()
{
    int n, x = 0, y = 0, z = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int a, b;
        
        scanf("%d %d", &a, &b);
        
        if (a % 2 == 0 && b % 2 == 0) continue;
        
        if (a % 2 == 0) {
            x++;
        } else if (b % 2 == 0) {
            y++;
        } else {
            z++;
        }
    }
    
    if ((x + z) % 2 == 0 && (y + z) % 2 == 0) {
        puts("0");
    } else if ((x + z) % 2 + (y + z) % 2 == 1) {
        puts("-1");
    } else if (x > 0 || y > 0) {
        puts("1");
    } else {
        puts("-1");
    }
    
    return 0;
}