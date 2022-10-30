#include <stdio.h>

int main()
{
    int n, s, t, i;
    int a[100000];
    int b[100000] = {0};
    
    scanf("%d %d %d", &n, &s, &t);
    
    s--;
    t--;
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        a[i]--;
    }
    
    for (i = 0; ; i++) {
        if (s == t) break;
        
        b[s] = 1;
        s = a[s];
        
        if (b[s] == 1) {
            i = -1;
            
            break;
        }
    }
    
    printf("%d\n", i);
    
    return 0;
}