#include <stdio.h>

int main()
{
    int n, c = 0, ans = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == -1) {
            if (c > 0) {
                c--;
            } else {
                ans++;
            }
        } else {
            c += x;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}