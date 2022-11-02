#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char s[2000][2001];
int a[2000][2000];

int main()
{
    int n, m, sum = 0, i, j, k;
    queue <pair<int, int> > q;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                for (k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] != '.') continue;
                    
                    a[i][j]++;
                }
                
                if (a[i][j] == 1) q.push(make_pair(i, j));
                
                sum++;
            }
        }
    }
    
    while (sum > 0) {
        int x, y;
        
        if (q.empty()) {
            puts("Not unique");
            
            return 0;
        }
        
        x = q.front().first;
        y = q.front().second;
        
        q.pop();
        
        if (a[x][y] != 1) continue;
        
        for (i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] != '.') continue;
            
            a[x][y] = a[nx][ny] = 0;
            
            break;
        }
        
        if (i == 0) {
            s[x][y] = '<';
            s[x][y + 1] = '>';
        } else if (i == 1) {
            s[x][y] = '^';
            s[x + 1][y] = 'v';
        } else if (i == 2) {
            s[x][y] = '>';
            s[x][y - 1] = '<';
        } else {
            s[x][y] = 'v';
            s[x - 1][y] = '^';
        }
        
        for (j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] != '.') continue;
            
            a[nx][ny]--;
            
            if (a[nx][ny] == 1) q.push(make_pair(nx, ny));
        }
        
        for (j = 0; j < 4; j++) {
            int nx = x + dx[i] + dx[j];
            int ny = y + dy[i] + dy[j];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] != '.') continue;
            
            a[nx][ny]--;
            
            if (a[nx][ny] == 1) q.push(make_pair(nx, ny));
        }
        
        sum -= 2;
    }
    
    if (sum > 0) {
        puts("Not unique");
    } else {
        for (i = 0; i < n; i++) printf("%s\n", s[i]);
    }
    
    return 0;
}