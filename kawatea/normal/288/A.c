#include <stdio.h>

int main()
{
    int n, k, i;
    char s[1000001];
    
    scanf("%d %d", &n, &k);
    
    if (k > n || (k == 1 && n > 1)) {
        puts("-1");
        
        return 0;
    }
    
    for (i = 0; i < n - k + 2; i++) s[i] = 'a' + i % 2;
    
    for (; i < n; i++) s[i] = 'a' + k - n + i;
    
    s[n] = '\0';
    
    printf("%s\n", s);
    
    return 0;
}