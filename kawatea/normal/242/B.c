#include <stdio.h>

int l[100000], r[100000];

int main()
{
    int n, m1 = 1e9, m2 = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        
        if (l[i] < m1) m1 = l[i];
        if (r[i] > m2) m2 = r[i];
    }
    
    for (i = 0; i < n; i++) {
        if (l[i] == m1 && r[i] == m2) {
            printf("%d\n", i + 1);
            
            return 0;
        }
    }
    
    puts("-1");
    
    return 0;
}