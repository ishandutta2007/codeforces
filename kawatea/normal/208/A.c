#include <stdio.h>
#include <string.h>

int main()
{
    int n, p = 0, i, j;
    char s[201];
    char c[4] = "WUB";
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (strncmp(&s[j], c, 3) == 0) break;
        }
        
        if (i != j) {
            if (p > 0) putchar(' ');
            
            for (; i < j; i++) putchar(s[i]);
            
            p++;
        }
        
        i = j + 2;
    }
    
    puts("");
    
    return 0;
}