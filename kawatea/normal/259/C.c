#include <stdio.h>
#include <string.h>

int main()
{
    int n, p = -1, i;
    char s[100001];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    if (n == 1) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            p = i;
            
            break;
        }
    }
    
    if (p == -1) {
        for (i = 0; i < n - 1; i++) putchar('1');
        
        puts("");
    } else {
        for (i = 0; i < p; i++) putchar(s[i]);
        for (i = p + 1; i < n; i++) putchar(s[i]);
        
        puts("");
    }
    
    return 0;
}