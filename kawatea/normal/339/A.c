#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    int a[3] = {0};
    char s[101];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i += 2) a[s[i] - '1']++;
    
    n /= 2;
    
    for (i = 0; i < 3; i++) {
        while (a[i]) {
            printf("%d", i + 1);
            
            a[i]--;
            
            if (n > 0) printf("+");
            
            n--;
        }
    }
    
    puts("");
    
    return 0;
}