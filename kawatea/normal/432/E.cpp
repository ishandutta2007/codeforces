#include <cstdio>

using namespace std;

int a[100][100];

int main()
{
    int n, m, i, j, k, l;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = -1;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] != -1) continue;
            
            for (k = 0; k < 26; k++) {
                int x = i, y = j, z = 0;
                
                if (i > 0 && a[i - 1][j] == k) continue;
                if (j < m - 1 && a[i][j + 1] == k) continue;
                
                if (j > 0 && a[i][j - 1] == k) {
                    while (y > 0 && a[x][y - 1] == k) y--, z++;
                    while (x > 0 && a[x - 1][y] == k) x--;
                    
                    if (x != i) continue;
                    
                    if (x + z + 1 > n) continue;
                    
                    if (y > 0 && a[x + z][y - 1] == k) continue;
                    
                    for (l = i; l < x + z + 1; l++) {
                        if (a[l][j] != -1) break;
                        
                        if (j < m - 1 && a[l][j + 1] == k) break;
                    }
                    
                    if (l < x + z + 1) continue;
                    
                    for (l = y; l < y + z + 1; l++) {
                        if (a[x + z][l] != -1) break;
                        
                        if (x + z < n - 1 && a[x + z + 1][l] == k) break;
                    }
                    
                    if (l < y + z + 1) continue;
                    
                    for (l = i; l < x + z + 1; l++) a[l][j] = k;
                    for (l = y; l < y + z + 1; l++) a[x + z][l] = k;
                    
                    break;
                } else {
                    a[i][j] = k;
                    
                    break;
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            putchar('A' + a[i][j]);
        }
        
        puts("");
    }
    
    return 0;
}