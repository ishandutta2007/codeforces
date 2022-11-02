#include <stdio.h>

int main()
{
    int i, j;
    
    for (i = 0; i < 8; i++) {
        char s[9];
        
        scanf("%s", s);
        
        if (s[0] == 'W') {
            for (j = 0; j < 8; j++) {
                if (j % 2 == 0 && s[j] == 'B') break;
                if (j % 2 == 1 && s[j] == 'W') break;
            }
            
            if (j < 8) {
                puts("NO");
                
                return 0;
            }
        } else {
            for (j = 0; j < 8; j++) {
                if (j % 2 == 0 && s[j] == 'W') break;
                if (j % 2 == 1 && s[j] == 'B') break;
            }
            
            if (j < 8) {
                puts("NO");
                
                return 0;
            }
        }
    }
    
    puts("YES");
    
    return 0;
}