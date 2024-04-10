#include <stdio.h>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char s[100][101];

int main()
{
    int n, i, j, k;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int c = 0;
            
            for (k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                
                if (s[x][y] == 'o') c ^= 1;
            }
            
            if (c == 1) {
                puts("NO");
                
                return 0;
            }
        }
    }
    
    puts("YES");
    
    return 0;
}