#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j;
    int a[26] = {0};
    int b[26][26] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        char s[21];
        
        scanf("%s", s);
        
        for (j = 0; j < strlen(s); j++) {
            a[s[j] - 'a']++;
            
            if (j + 1 < strlen(s)) b[s[j] - 'a'][s[j + 1] - 'a']++;
        }
    }
    
    for (i = 0; i < 26; i++) {
        if (a[i] == 0) {
            printf("%c\n", 'a' + i);
            
            return 0;
        }
    }
    
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (b[i][j] == 0) {
                printf("%c%c\n", 'a' + i, 'a' + j);
                
                return 0;
            }
        }
    }
    
    return 0;
}