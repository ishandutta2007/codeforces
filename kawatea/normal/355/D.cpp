#include <cstdio>
#include <algorithm>

using namespace std;

int n;
char s[20][21];
int a[40][26];
int dp[40][1 << 20];

int dfs(int x, int y)
{
    int z = 0, i, j;
    
    if (dp[x][y] != 1e9) return dp[x][y];
    
    for (i = 0; i < n; i++) {
        if ((y >> i) & 1) {
            if (s[i][x - i] == 'a') {
                z++;
            } else if (s[i][x - i] == 'b') {
                z--;
            }
            
            break;
        }
    }
    
    if (x == 2 * n - 2) return dp[x][y] = z;
    
    if (x % 2 == 1) {
        dp[x][y] = -1e9;
        
        for (i = 0; i < 26; i++) {
            int ny = a[x + 1][i] & (y | (y << 1));
            
            if (ny == 0) continue;
            
            dp[x][y] = max(dp[x][y], dfs(x + 1, ny) + z);
        }
    } else {
        for (i = 0; i < 26; i++) {
            int ny = a[x + 1][i] & (y | (y << 1));
            
            if (ny == 0) continue;
            
            dp[x][y] = min(dp[x][y], dfs(x + 1, ny) + z);
        }
    }
    
    return dp[x][y];
}

int main()
{
    int ans, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n * 2 - 1; i++) {
        for (j = 0; j < n; j++) {
            if (i - j < 0 || i - j >= n) continue;
            
            a[i][s[j][i - j] - 'a'] |= (1 << j);
        }
    }
    
    for (i = 0; i < n * 2; i++) {
        for (j = 0; j < (1 << n); j++) {
            dp[i][j] = 1e9;
        }
    }
    
    ans = dfs(0, 1);
    
    if (ans > 0) {
        puts("FIRST");
    } else if (ans == 0) {
        puts("DRAW");
    } else {
        puts("SECOND");
    }
    
    return 0;
}