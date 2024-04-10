#include <stdio.h>

int main()
{
    int i, j;
    char s[4][5];
    
    for (i = 0; i < 4; i++) scanf("%s", s[i]);
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int x = 0, y = 0;
            
            if (s[i][j] == '#') {
                x++;
            } else {
                y++;
            }
            
            if (s[i + 1][j] == '#') {
                x++;
            } else {
                y++;
            }
            
            if (s[i][j + 1] == '#') {
                x++;
            } else {
                y++;
            }
            
            if (s[i + 1][j + 1] == '#') {
                x++;
            } else {
                y++;
            }
            
            if (x == 2 && y == 2) continue;
            
            puts("YES");
            
            return 0;
        }
    }
    
    puts("NO");
    
    return 0;
}