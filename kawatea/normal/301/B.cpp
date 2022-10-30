#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, d, i, j;
    int a[100] = {0};
    int b[201][201];
    int f[201][201] = {0};
    priority_queue <pair<int, pair<int, int> > > q;
    
    scanf("%d %d", &n, &d);
    
    for (i = 1; i < n - 1; i++) scanf("%d", &a[i]);
    
    for (i = 0; i <= 200; i++) {
        for (j = 0; j <= 200; j++) {
            b[i][j] = -1;
        }
    }
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        b[x + 100][y + 100] = i;
        
        if (i == 0) q.push(make_pair(0, make_pair(x + 100, y + 100)));
    }
    
    while (!q.empty()) {
        int c = -q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        
        q.pop();
        
        if (b[x][y] == n - 1) {
            printf("%d\n", c);
            
            break;
        }
        
        if (f[x][y] == 1) continue;
        
        f[x][y] = 1;
        
        for (i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > 200 || ny < 0 || ny > 200 || f[nx][ny] == 1) continue;
            
            if (b[x][y] != -1) {
                q.push(make_pair(-c - d + a[b[x][y]], make_pair(nx, ny)));
            } else {
                q.push(make_pair(-c - d, make_pair(nx, ny)));
            }
        }
    }
    
    return 0;
}