#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char c[100][101];
int b[100][100];
int d[26][100][100];
int p[26][100][100][2];

int main()
{
    int m, n, k, r1, c1, r2, c2, l, i, j;
    int a[26][2];
    int e[1000];
    char s[1001];
    
    scanf("%d %d %d", &m, &n, &k);
    
    for (i = 0; i < m; i++) scanf("%s", c[i]);
    
    scanf("%d %d %s %d %d", &r1, &c1, s, &r2, &c2);
    
    r1--;
    c1--;
    r2--;
    c2--;
    
    for (i = 0; i < 26; i++) a[i][0] = a[i][1] = -1;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (c[i][j] >= 'a' && c[i][j] <= 'z') {
                a[c[i][j] - 'a'][0] = i;
                a[c[i][j] - 'a'][1] = j;
                
                b[i][j] = 1;
            } else if (c[i][j] >= '0' && c[i][j] <= '9') {
                b[i][j] = c[i][j] - '0';
            }
        }
    }
    
    for (i = 0; i < 26; i++) {
        int f[100][100] = {0};
        queue <pair<int, pair<int, int> > > q;
        
        if (a[i][0] == -1) continue;
        
        f[a[i][0]][a[i][1]] = 1;
        q.push(make_pair(0, make_pair(a[i][0] * 100 + a[i][1], 0)));
        
        while (!q.empty()) {
            int t = q.front().first;
            int x = q.front().second.first / 100;
            int y = q.front().second.first % 100;
            int z1 = q.front().second.second / 100;
            int z2 = q.front().second.second % 100;
            
            q.pop();
            
            d[i][x][y] = t;
            p[i][x][y][0] = z1;
            p[i][x][y][1] = z2;
            
            t += b[x][y];
            
            for (j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || c[nx][ny] == '#' || f[nx][ny] == 1) continue;
                
                f[nx][ny] = 1;
                q.push(make_pair(t, make_pair(nx * 100 + ny, x * 100 + y)));
            }
        }
    }
    
    l = strlen(s);
    
    for (i = 0; i < l; i++) e[i] = s[i] - 'a';
    
    if (d[e[0]][r1][c1] + b[r1][c1] - 1 <= k) {
        k -= d[e[0]][r1][c1] + b[r1][c1] - 1;
    } else {
        int x = r1, y = c1;
        
        while (1) {
            int x1 = x, y1 = y;
            
            k -= b[x][y];
            
            if (k < 0) {
                printf("%d %d\n", x + 1, y + 1);
                
                return 0;
            }
            
            x = p[e[0]][x1][y1][0];
            y = p[e[0]][x1][y1][1];
        }
    }
    
    r1 = a[e[0]][0];
    c1 = a[e[0]][1];
    
    for (i = 1; i < l; i++) {
        if (d[e[i]][r1][c1] <= k) {
            k -= d[e[i]][r1][c1];
        } else {
            int x = a[e[i]][0], y = a[e[i]][1];
            
            while (1) {
                int x1 = x, y1 = y;
                
                x = p[e[i - 1]][x1][y1][0];
                y = p[e[i - 1]][x1][y1][1];
                
                if (d[e[i - 1]][x][y] <= k) {
                    printf("%d %d\n", x + 1, y + 1);
                    
                    return 0;
                }
            }
        }
        
        r1 = a[e[i]][0];
        c1 = a[e[i]][1];
    }
    
    if (d[e[l - 1]][r2][c2] <= k) {
        printf("%d %d\n", r2 + 1, c2 + 1);
    } else {
        int x = r2, y = c2;
        
        while (1) {
            int x1 = x, y1 = y;
            
            x = p[e[l - 1]][x1][y1][0];
            y = p[e[l - 1]][x1][y1][1];
            
            if (d[e[l - 1]][x][y] <= k) {
                printf("%d %d\n", x + 1, y + 1);
                
                return 0;
            }
        }
    }
    
    return 0;
}