#include <cstdio>

using namespace std;

char s[3][103];
int f[103][3];

int check(int x, int y) {
    if (s[x][y] >= 'A' && s[x][y] <= 'Z') return 0;
    
    return 1;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, k, ans = 0, j, l;
        
        scanf("%d %d", &n, &k);
        
        for (j = 0; j < 3; j++) {
            for (l = 0; l <= n + 2; l++) {
                s[j][l] = 0;
            }
        }
        
        for (j = 0; j < 3; j++) scanf("%s", s[j]);
        
        for (j = 0; j <= n + 2; j++) {
            for (l = 0; l < 3; l++) {
                f[j][l] = 0;
            }
        }
        
        for (j = 0; j < 3; j++) {
            if (s[j][0] == 's') f[0][j] = 1;
        }
        
        for (j = 0; j < n; j++) {
            for (l = 0; l < 3; l++) {
                if (f[j][l] == 0) continue;
                
                if (check(l, j + 1) == 0) continue;
                
                if (l > 0) {
                    if (check(l - 1, j + 1) == 1 && check(l - 1, j + 2) == 1 && check(l - 1, j + 3) == 1) f[j + 3][l - 1] = 1;
                }
                
                if (check(l, j + 2) == 1 && check(l, j + 3) == 1) f[j + 3][l] = 1;
                
                if (l < 2) {
                    if (check(l + 1, j + 1) == 1 && check(l + 1, j + 2) == 1 && check(l + 1, j + 3) == 1) f[j + 3][l + 1] = 1;
                }
            }
        }
        
        for (j = n; j <= n + 2; j++) {
            for (l = 0; l < 3; l++) {
                if (f[j][l] == 1) ans = 1;
            }
        }
        
        if (ans == 1) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}