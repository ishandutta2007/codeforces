#include <stdio.h>
#include <string.h>

int main()
{
    int n, f = 0, i;
    char s[101];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    if (n < 5) {
        puts("Too weak");
    } else {
        for (i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') f |= 1;
            if (s[i] >= 'a' && s[i] <= 'z') f |= 2;
            if (s[i] >= '0' && s[i] <= '9') f |= 4;
        }
        
        if (f == 7) {
            puts("Correct");
        } else {
            puts("Too weak");
        }
    }
    
    return 0;
}