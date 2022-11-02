#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int a[500][500];
char s[500][501];

int main()
{
    int n, m, k, sum = 0, i, j, l;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '.') sum++;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int p = sum - k;
            queue <pair<int, int> > q;
            
            if (s[i][j] == '#' || a[i][j] == 1) continue;
            
            a[i][j] = 1;
            q.push(make_pair(i, j));
            
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                p--;
                
                for (l = 0; l < 4; l++) {
                    int nx = x + dx[l];
                    int ny = y + dy[l];
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#' || a[nx][ny] == 1) continue;
                    
                    a[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
            
            if (p > 0) continue;
            
            p = sum - k;
            a[i][j] = 2;
            q.push(make_pair(i, j));
            
            while (p) {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                p--;
                a[x][y] = 3;
                
                for (l = 0; l < 4; l++) {
                    int nx = x + dx[l];
                    int ny = y + dy[l];
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#' || a[nx][ny] >= 2) continue;
                    
                    a[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
            
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if (a[i][j] != 3 && s[i][j] == '.') s[i][j] = 'X';
                }
            }
            
            for (i = 0; i < n; i++) printf("%s\n", s[i]);
            
            return 0;
        }
    }
    
    return 0;
}