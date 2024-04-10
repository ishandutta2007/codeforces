#include <stdio.h>
#include <string.h>

#define A int
#define B int

typedef struct {
    A first;
    B second;
} pair;

pair make_pair(A first, B second)
{
    pair p;
    
    p.first = first;
    p.second = second;
    
    return p;
}

int n, m;
char s1[101];
char s2[101];
pair dp[100][100];
pair dp2[100];

pair dfs(int x, int y)
{
    if (x == n) {
        pair p = dfs(0, y);
        
        p.first++;
        
        return p;
    } else if (y == m) {
        pair p = make_pair(0, x);
        
        return p;
    } else {
        if (dp[x][y].first != -1) return dp[x][y];
        
        if (s1[x] == s2[y]) {
            return dp[x][y] = dfs(x + 1, y + 1);
        } else {
            return dp[x][y] = dfs(x + 1, y);
        }
    }
}

int main()
{
    int b, d, x = 0, y = 0, c = 0, i, j;
    int p[26] = {0};
    int q[26] = {0};
    
    scanf("%d %d", &b, &d);
    scanf("%s", s1);
    scanf("%s", s2);
    
    n = strlen(s1);
    m = strlen(s2);
    
    for (i = 0; i < n; i++) p[s1[i] - 'a']++;
    for (i = 0; i < m; i++) q[s2[i] - 'a']++;
    
    for (i = 0; i < 26; i++) {
        if (p[i] == 0 && q[i] > 0) {
            puts("0");
            
            return 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dp[i][j] = make_pair(-1, -1);
        }
    }
    
    for (i = 0; i < n; i++) {
        if (dp[i][0].first == -1) dfs(i, 0);
    }
    
    for (i = 0; i < n; i++) dp2[i] = make_pair(-1, -1);
    
    while (1) {
        x += dp[y][0].first;
        y = dp[y][0].second;
        
        if (x >= b) {
            if (x == b && y == 0) c++;
            
            break;
        }
        
        c++;
        
        if (dp2[y].first == -1) {
            dp2[y] = make_pair(x, c);
        } else {
            int z = x - dp2[y].first;
            
            if (x + z < b) {
                int w = (b - x - 1) / z;
                
                x += w * z;
                c += (c - dp2[y].second) * w;
            }
        }
    }
    
    printf("%d\n", c / d);
    
    return 0;
}