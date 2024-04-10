#include <stdio.h>

int main()
{
    int n, sum = 0, i, j;
    char s[51];
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i] != s[j]) break;
        }
        
        sum += j - i - 1;
        
        i = j - 1;
    }
    
    printf("%d\n", sum);
    
    return 0;
}