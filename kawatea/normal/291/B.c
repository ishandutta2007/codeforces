#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j;
    char s[100010];
    
    fgets(s, 100010, stdin);
    
    n = strlen(s) - 1;
    
    for (i = 0; i < n; i++) {
        if (s[i] == ' ') continue;
        
        if (s[i] == '"') {
            putchar('<');
            
            for (j = i + 1; j < n; j++) {
                if (s[j] == '"') break;
                
                putchar(s[j]);
            }
            
            puts(">");
            
            i = j;
        } else {
            putchar('<');
            
            for (j = i; j < n; j++) {
                if (s[j] == ' ') break;
                
                putchar(s[j]);
            }
            
            puts(">");
            
            i = j;
        }
    }
    
    return 0;
}