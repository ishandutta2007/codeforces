#include <stdio.h>

int main()
{
    int n, m, m1, m2, c1 = 0, c2 = 0, i;
    
    scanf("%d %d %d %d", &n, &m, &m1, &m2);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x < m1 || x > m2) {
            puts("Incorrect");
            
            return 0;
        }
        
        if (x == m1) c1 = 1;
        if (x == m2) c2 = 1;
    }
    
    if (n - m >= 2 - c1 - c2) {
        puts("Correct");
    } else {
        puts("Incorrect");
    }
    
    return 0;
}