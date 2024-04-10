#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

int f[100][100000];

int main()
{
    int n, x1, y1, x2, y2, i;
    int a[100000];
    FILE *fp;
    queue <pair<int, pair<int, int> > > q;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d", &n);
    
    for (i = 0; i < n; i++) fscanf(fp, "%d", &a[i]);
    
    fscanf(fp, "%d %d %d %d", &x1, &y1, &x2, &y2);
    
    x1--;
    y1--;
    x2--;
    y2--;
    
    fclose(fp);
    
    f[x1][y1] = 1;
    q.push(make_pair(0, make_pair(x1, y1)));
    
    while (!q.empty()) {
        int c = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        
        q.pop();
        
        if (x == x2 && y == y2) {
            fp = fopen("output.txt", "w");
            
            fprintf(fp, "%d\n", c);
            
            fclose(fp);
            
            return 0;
        }
        
        if (x > 0) {
            int nx = x - 1;
            int ny = min(y, a[nx]);
            
            if (f[nx][ny] == 0) {
                f[nx][ny] = 1;
                q.push(make_pair(c + 1, make_pair(nx, ny)));
            }
        }
        
        if (x < n - 1) {
            int nx = x + 1;
            int ny = min(y, a[nx]);
            
            if (f[nx][ny] == 0) {
                f[nx][ny] = 1;
                q.push(make_pair(c + 1, make_pair(nx, ny)));
            }
        }
        
        if (y < a[x]) {
            int nx = x;
            int ny = y + 1;
            
            if (f[nx][ny] == 0) {
                f[nx][ny] = 1;
                q.push(make_pair(c + 1, make_pair(nx, ny)));
            }
        }
        
        if (y > 0) {
            int nx = x;
            int ny = y - 1;
            
            if (f[nx][ny] == 0) {
                f[nx][ny] = 1;
                q.push(make_pair(c + 1, make_pair(nx, ny)));
            }
        }
    }
    
    return 0;
}