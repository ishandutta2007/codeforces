#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j;
    char s[11];
    char s2[11] = "a";
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 1; i < (1 << n); i++) {
        int p = 0;
        char c[11];
        
        for (j = 0; j < n; j++) {
            if ((i >> j) & 1) c[p++] = s[j];
        }
        
        c[p] = '\0';
        
        for (j = 0; j < p / 2; j++) {
            if (c[j] != c[p - j - 1]) break;
        }
        
        if (j == p / 2 && strcmp(s2, c) < 0) strcpy(s2, c);
    }
    
    printf("%s\n", s2);
    
    return 0;
}