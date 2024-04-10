#include <stdio.h>
#include <string.h>

int main()
{
    int n, x = 0, y = 0, i;
    char s[1000001];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'x') {
            x++;
        } else {
            y++;
        }
    }
    
    if (x == y) {
        puts("");
    } else if (x > y) {
        for (i = 0; i < x - y; i++) putchar('x');
        
        puts("");
    } else {
        for (i = 0; i < y - x; i++) putchar('y');
        
        puts("");
    }
    
    return 0;
}