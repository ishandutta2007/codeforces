#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[500][500];
int b[250000][2];
int c[250000][2];
char s[500][501];
int ans[250000][2];
int ans2[250000][2];

int main()
{
    int n, m, p = 0, c1 = 0, c2 = 0, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                ans[c1][0] = i + 1;
                ans[c1++][1] = j + 1;
                
                a[i][j] = 1;
                
                b[p][0] = i;
                b[p++][1] = j;
            }
        }
    }
    
    for (i = 0; i < p; i++) {
        int x = b[i][0];
        int y = b[i][1];
        int t = 0;
        
        if (a[x][y] == 0) continue;
        
        queue <pair<int, int> > q;
        
        a[x][y] = 0;
        q.push(make_pair(x, y));
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            c[t][0] = x;
            c[t++][1] = y;
            
            for (i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#' || a[nx][ny] == 0) continue;
                
                a[nx][ny] = 0;
                q.push(make_pair(nx, ny));
            }
        }
        
        for (i = t - 1; i > 0; i--) {
            int x = c[i][0];
            int y = c[i][1];
            
            ans2[c2][0] = x + 1;
            ans2[c2++][1] = y + 1;
        }
    }
    
    printf("%d\n", c1 + c2 * 2);
    
    for (i = 0; i < c1; i++) printf("B %d %d\n", ans[i][0], ans[i][1]);
    
    for (i = 0; i < c2; i++) {
        printf("D %d %d\n", ans2[i][0], ans2[i][1]);
        printf("R %d %d\n", ans2[i][0], ans2[i][1]);
    }
    
    return 0;
}