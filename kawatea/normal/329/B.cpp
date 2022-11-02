#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char s[1000][1001];
int a[1000][1000];

int main()
{
    int r, c, xs, ys, xe, ye, ans = 0, i, j;
    queue <pair<int, int> > q;
    
    scanf("%d %d", &r, &c);
    
    for (i = 0; i < r; i++) scanf("%s", s[i]);
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (s[i][j] == 'S') {
                xs = i;
                ys = j;
            } else if (s[i][j] == 'E') {
                xe = i;
                ye = j;
            }
        }
    }
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            a[i][j] = 1e9;
        }
    }
    
    a[xe][ye] = 0;
    q.push(make_pair(xe, ye));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for (i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || s[nx][ny] == 'T' || a[nx][ny] <= a[x][y] + 1) continue;
            
            a[nx][ny] = a[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] <= a[xs][ys] && s[i][j] >= '0' && s[i][j] <= '9') ans += s[i][j] - '0';
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}