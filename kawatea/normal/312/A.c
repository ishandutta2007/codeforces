#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i;
    
    scanf("%d%*c", &n);
    
    for (i = 0; i < n; i++) {
        int m, f = 0;
        char s[105];
        
        fgets(s, 105, stdin);
        
        m = strlen(s) - 1;
        
        if (m >= 5 && strncmp(s, "miao.", 5) == 0) f |= 1;
        if (m >= 5 && strncmp(s + m - 5, "lala.", 5) == 0) f |= 2;
        
        if (f == 1) {
            puts("Rainbow's");
        } else if (f == 2) {
            puts("Freda's");
        } else {
            puts("OMG>.< I don't know!");
        }
    }
    
    return 0;
}