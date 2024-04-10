#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, i, j, k;
    int a[26] = {0};
    char s[5001], t[5001];
    
    scanf("%s", s);
    scanf("%s", t);
    
    n = strlen(s);
    m = strlen(t);
    
    for (i = 0; i < n; i++) a[s[i] - 'a']++;

    for (i = 0; i < n && i < m; i++) {
        if (a[t[i] - 'a'] == 0) break;
        
        a[t[i] - 'a']--;
    }
    
    if (i == n) {
        for (i--; i >= 0; i--) {
            a[t[i] - 'a']++;
            
            for (j = t[i] - 'a' + 1; j < 26; j++) {
                if (a[j] > 0) break;
            }
            
            if (j < 26) {
                for (k = 0; k < i; k++) s[k] = t[k];
                
                s[k++] = j + 'a';
                
                a[j]--;
                
                for (; k < n; k++) {
                    for (j = 0; j < 26; j++) {
                        if (a[j] > 0) {
                            s[k] = j + 'a';
                            
                            a[j]--;
                            
                            break;
                        }
                    }
                }
                
                break;
            }
        }
        
        if (i < 0) {
            puts("-1");
            
            return 0;
        }
    } else if (i == m) {
        for (i = 0; i < m; i++) s[i] = t[i];
        
        for (; i < n; i++) {
            for (j = 0; j < 26; j++) {
                if (a[j] > 0) {
                    s[i] = j + 'a';
                    
                    a[j]--;
                    
                    break;
                }
            }
        }
    } else {
        a[t[i] - 'a']--;
        
        for (; i >= 0; i--) {
            a[t[i] - 'a']++;
            
            for (j = t[i] - 'a' + 1; j < 26; j++) {
                if (a[j] > 0) break;
            }
            
            if (j < 26) {
                for (k = 0; k < i; k++) s[k] = t[k];
                
                s[k++] = j + 'a';
                
                a[j]--;
                
                for (; k < n; k++) {
                    for (j = 0; j < 26; j++) {
                        if (a[j] > 0) {
                            s[k] = j + 'a';
                            
                            a[j]--;
                            
                            break;
                        }
                    }
                }
                
                break;
            }
        }
        
        if (i < 0) {
            puts("-1");
            
            return 0;
        }
    }
    
    printf("%s\n", s);
    
    return 0;
}