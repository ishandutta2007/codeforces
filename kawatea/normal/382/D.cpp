#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char s[2000][2001];
int dp[2000][2000][3];

void dfs(int x, int y)
{
    int dx, dy;
    
    if (dp[x][y][0] != -1) return;
    
    if (s[x][y] == '#') {
        dp[x][y][0] = 0;
        
        return;
    }
    
    dp[x][y][0] = 1e9;
    
    if (s[x][y] == '<') {
        dx = 0;
        dy = -1;
    } else if (s[x][y] == '>') {
        dx = 0;
        dy = 1;
    } else if (s[x][y] == '^') {
        dx = -1;
        dy = 0;
    } else {
        dx = 1;
        dy = 0;
    }
    
    dfs(x + dx, y + dy);
    
    dp[x][y][0] = dp[x + dx][y + dy][0] + 1;
    
    if (dp[x][y][0] == 1) {
        dp[x][y][1] = x;
        dp[x][y][2] = y;
    } else {
        dp[x][y][1] = dp[x + dx][y + dy][1];
        dp[x][y][2] = dp[x + dx][y + dy][2];
    }
}

int main()
{
    int n, m, i, j;
    pair <int, pair<int, int> > p1, p2;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dp[i][j][0] = -1;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (dp[i][j][0] == -1) {
                dfs(i, j);
                
                if (dp[i][j][0] >= 1e9) {
                    puts("-1");
                    
                    return 0;
                }
            }
        }
    }
    
    p1 = p2 = make_pair(0, make_pair(0, 0));
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (dp[i][j][0] > 0) {
                pair <int, pair<int, int> > p = make_pair(dp[i][j][0], make_pair(dp[i][j][1], dp[i][j][2]));
                
                if (p > p1) {
                    p2 = p1;
                    p1 = p;
                } else if (p != p1 && p > p2) {
                    p2 = p;
                }
            }
        }
    }
    
    printf("%d\n", p1.first + p2.first);
    
    return 0;
}