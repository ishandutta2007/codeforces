#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {2, 2, -2, -2};
int dy[4] = {2, -2, 2, -2};

int main()
{
    int t;
    
    scanf("%d", &t);
    
    while (t--) {
        int x1 = -1, y1, x2, y2, f = 0, i, j;
        int a[8][8];
        int b[8][8];
        char s[8][9];
        queue <pair<int, int> > q1, q2;
        
        for (i = 0; i < 8; i++) scanf("%s", s[i]);
        
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (s[i][j] == 'K') {
                    if (x1 == -1) {
                        x1 = i;
                        y1 = j;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                a[i][j] = b[i][j] = -1;
            }
        }
        
        a[x1][y1] = 0;
        q1.push(make_pair(x1, y1));
        
        while (!q1.empty()) {
            int x = q1.front().first;
            int y = q1.front().second;
            
            q1.pop();
            
            for (i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || a[nx][ny] != -1) continue;
                
                a[nx][ny] = a[x][y] + 1;
                q1.push(make_pair(nx, ny));
            }
        }
        
        b[x2][y2] = 0;
        q2.push(make_pair(x2, y2));
        
        while (!q2.empty()) {
            int x = q2.front().first;
            int y = q2.front().second;
            
            q2.pop();
            
            for (i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || b[nx][ny] != -1) continue;
                
                b[nx][ny] = b[x][y] + 1;
                q2.push(make_pair(nx, ny));
            }
        }
        
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (a[i][j] == -1 || b[i][j] == -1 || s[i][j] == '#') continue;
                
                if (a[i][j] % 2 == b[i][j] % 2) f = 1;
            }
        }
        
        if (f == 1) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}