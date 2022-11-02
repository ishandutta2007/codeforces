#include <stdio.h>
#include <string.h>

char s[200001];

int main()
{
    int n, f = 0, i, j;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        int x;
        
        for (j = i; j < n; j++) {
            if (s[j] != s[i]) break;
        }
        
        x = j - i;
        
        if (x > 2) x = 2;
        
        if (x == 2 && f == 1) x = 1;
        
        if (x == 2) {
            f = 1;
        } else {
            f = 0;
        }
        
        while (x) {
            putchar(s[i]);
            
            x--;
        }
        
        i = j - 1;
    }
    
    puts("");
    
    return 0;
}