#include <stdio.h>

int n, m;
char s[50][51];
int a[50][50];

void dfs(int x, int y)
{
    a[x][y] = 1;
    
    if (x > 0 && s[x - 1][y] == '#' && a[x - 1][y] == 0) dfs(x - 1, y);
    if (x < n - 1 && s[x + 1][y] == '#' && a[x + 1][y] == 0) dfs(x + 1, y);
    if (y > 0 && s[x][y - 1] == '#' && a[x][y - 1] == 0) dfs(x, y - 1);
    if (y < m - 1 && s[x][y + 1] == '#' && a[x][y + 1] == 0) dfs(x, y + 1);
}

int ok(int x, int y)
{
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
    
    s[x][y] = '.';
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                dfs(i, j);
                
                i = n;
                
                break;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '#' && a[i][j] == 0) return 0;
        }
    }
    
    s[x][y] = '#';
    
    return 1;
}

int main()
{
    int sum = 0, f = 0, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                int c = 0;
                
                if (i > 0 && s[i - 1][j] == '#') c++;
                if (i < n - 1 && s[i + 1][j] == '#') c++;
                if (j > 0 && s[i][j - 1] == '#') c++;
                if (j < m - 1 && s[i][j + 1] == '#') c++;
                
                if (c == 1) f = 1;

                sum++;
            }
        }
    }
    
    if (sum <= 2) {
        puts("-1");
        
        return 0;
    } else if (f == 1) {
        puts("1");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (ok(i, j) == 0) {
                    puts("1");
                    
                    return 0;
                }
            }
        }
    }
    
    puts("2");

    return 0;
}