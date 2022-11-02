#include <stdio.h>

int main()
{
    int n, m, i, j, k, l;
    int a[50][2];
    int b[50][2];
    char s[50][51];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) a[i][0] = -1;
    for (i = 0; i < m; i++) b[i][0] = -1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'B') {
                if (a[i][0] != -1) {
                    puts("NO");
                    
                    return 0;
                }
                
                a[i][0] = j;
                
                while (j < m && s[i][j] == 'B') j++;
                
                a[i][1] = j - 1;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i][0] == -1) continue;
        
        for (; i < n; i++) {
            if (a[i][0] == -1) break;
        }
        
        for (; i < n; i++) {
            if (a[i][0] != -1) {
                puts("NO");
                
                return 0;
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        if (b[i][0] == -1) continue;
        
        for (; i < m; i++) {
            if (b[i][0] == -1) break;
        }
        
        for (; i < m; i++) {
            if (b[i][0] != -1) {
                puts("NO");
                
                return 0;
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (s[j][i] == 'B') {
                if (b[i][0] != -1) {
                    puts("NO");
                    
                    return 0;
                }
                
                b[i][0] = j;
                
                while (j < n && s[j][i] == 'B') j++;
                
                b[i][1] = j - 1;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i][0] == -1) continue;
        
        for (j = a[i][0]; j <= a[i][1]; j++) {
            for (k = i + 1; k < n; k++) {
                if (a[k][0] == -1) break;
                
                for (l = a[k][0]; l <= a[k][1]; l++) {
                    if (j == l) continue;
                    
                    if (l >= a[i][0] && l <= a[i][1] && i >= b[l][0] && i <= b[l][1]) continue;
                    if (j >= a[k][0] && j <= a[k][1] && k >= b[j][0] && k <= b[j][1]) continue;
                    
                    puts("NO");
                    
                    return 0;
                }
            }
        }
    }
    
    puts("YES");
    
    return 0;
}