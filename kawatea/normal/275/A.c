#include <stdio.h>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int i, j, k;
    int a[3][3];
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int c = a[i][j];
            
            for (k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                
                if (x < 0 || x >= 3 || y < 0 || y >= 3) continue;
                
                c += a[x][y];
            }
            
            if (c % 2 == 0) {
                putchar('1');
            } else {
                putchar('0');
            }
        }
        
        puts("");
    }
    
    return 0;
}