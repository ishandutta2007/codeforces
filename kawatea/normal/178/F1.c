#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, k, c, ans = 0, i, j, l;
    int a[20][20], b[20];
    char s[20][501];
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        scanf("%s", s[i]);
        
        b[i] = strlen(s[i]);
    }
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (l = 0; l < b[i] && l < b[j]; l++) {
                if (s[i][l] != s[j][l]) break;
            }
            
            a[i][j] = l;
        }
    }
    
    c = (1 << k) - 1;
    
    while (c < (1 << n)) {
        int x = c & -c;
        int y = c + x;
        int sum = 0;
        
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (((c >> i) & 1) && ((c >> j) & 1)) sum += a[i][j];
            }
        }
        
        ans = max(ans, sum);
        
        c = ((c & ~y) / x >> 1) | y;
    }
    
    printf("%d\n", ans);
    
    return 0;
}