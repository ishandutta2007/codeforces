#include <stdio.h>

int main()
{
    int n, x = -1, sum = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        char s[3];
        
        scanf("%s", s);
        
        if (s[0] - '0' + x != 1) sum++;
        
        x = s[1] - '0';
    }
    
    printf("%d\n", sum);
    
    return 0;
}