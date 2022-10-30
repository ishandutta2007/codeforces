#include <stdio.h>

int par[48];

int find(int x)
{
    if (par[x] == x) return x;
    
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main()
{
    int n, m, x = 0, y = 0, z = 0, p = 0, r = 0, i, j;
    int a[48] = {0};
    int b[16][3];
    int c[48] = {0};
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        unite(x - 1, y - 1);
    }
    
    for (i = 0; i < n; i++) c[find(i)]++;
    
    for (i = 0; i < n; i++) {
        if (c[i] > 3) {
            puts("-1");
            
            return 0;
        }
        
        if (c[i] == 1) {
            x++;
        } else if (c[i] == 2) {
            y++;
        } else if (c[i] == 3) {
            z++;
        }
    }
    
    if (y + z > n / 3) {
        puts("-1");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (c[i] == 3) {
            int q = 0;
            
            for (j = 0; j < n; j++) {
                if (find(j) == i) {
                    a[j] = 1;
                    b[p][q++] = j + 1;
                }
            }
            
            p++;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (c[i] == 2) {
            int q = 0;
            
            for (j = 0; j < n; j++) {
                if (find(j) == i) {
                    a[j] = 1;
                    b[p][q++] = j + 1;
                }
            }
            
            for (j = 0; j < n; j++) {
                if (a[j] == 0 && c[find(j)] == 1) {
                    a[j] = 1;
                    b[p][q++] = j + 1;
                    
                    break;
                }
            }
            
            p++;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            b[p][r++] = i + 1;
            
            if (r == 3) {
                p++;
                r = 0;
            }
        }
    }
    
    for (i = 0; i < n / 3; i++) printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
    
    return 0;
}