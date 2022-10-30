#include <stdio.h>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int x, y, p = 0, q = 0, i, j;
    
    scanf("%d %d", &x, &y);
    
    if (x == 0 && y == 0) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; ; i++) {
        for (j = 0; j < i / 2 + 1; j++) {
            p += dx[i % 4];
            q += dy[i % 4];
            
            if (x == p && y == q) {
                printf("%d\n", i);
                
                return 0;
            }
        }
    }
    
    return 0;
}