#include <stdio.h>

int a[26];

int main()
{
    int ans = 0;
    
    getchar();
    
    while (1) {
        char c = getchar();
        
        if (c == '}') break;
        
        if (a[c - 'a'] == 0) ans++;
        
        a[c - 'a'] = 1;
        
        if (getchar() == '}') break;
        
        getchar();
    }
    
    printf("%d\n", ans);
    
    return 0;
}