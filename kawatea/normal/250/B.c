#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, k, l;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int m, p = 0;
        char s[50];
        
        scanf("%s", s);
        
        m = strlen(s);
        
        for (j = 0; j < m; j++) {
            if (s[j] == ':') p++;
        }
        
        if (s[0] == ':') {
            m++;
            
            for (j = m; j > 0; j--) s[j] = s[j - 1];
            
            s[0] = '0';
        }
        
        if (s[m - 1] == ':') {
            s[m++] = '0';
            s[m] = '\0';
        }
        
        for (j = 0; j < m; j++) {
            if (s[j] == ':' && s[j + 1] == ':') {
                int c = (7 - p) * 2 + 1;
                
                if (c < 0) {
                    m--;
                    
                    for (k = j + 1; k < m; k++) s[k] = s[k + 1];
                    
                    break;
                }
                
                m += c;
                
                for (k = m; k - c > j; k--) s[k] = s[k - c];
                
                for (k = 0; k < c; k++) {
                    if (k % 2 == 0) {
                        s[j + k + 1] = '0';
                    } else {
                        s[j + k + 1] = ':';
                    }
                }
                
                break;
            }
        }
        
        for (j = 0; j < m; j++) {
            for (k = j; k < m; k++) {
                if (s[k] == ':') break;
            }
            
            for (l = 0; l < 4 - k + j; l++) putchar('0');
            
            for (; j < k; j++) putchar(s[j]);
            
            if (s[j] == ':') putchar(s[j]);
        }
        
        puts("");
    }
    
    return 0;
}