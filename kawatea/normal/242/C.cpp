#include <cstdio>
#include <queue>
#include <set>

using namespace std;

set <pair<int, int> > s, s2;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main()
{
    int n, x1, y1, x2, y2, i, j;
    queue <pair<int, pair<int, int> > > q;
    
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        for (j = y; j <= z; j++) s.insert(make_pair(x, j));
    }
    
    s2.insert(make_pair(x1, y1));
    q.push(make_pair(0, make_pair(x1, y1)));
    
    while (!q.empty()) {
        int c = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        
        q.pop();
        
        if (x == x2 && y == y2) {
            printf("%d\n", c);
            
            return 0;
        }
        
        for (i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (s.count(make_pair(nx, ny)) && !s2.count(make_pair(nx, ny))) {
                s2.insert(make_pair(nx, ny));
                q.push(make_pair(c + 1, make_pair(nx, ny)));
            }
        }
    }
    
    puts("-1");
    
    return 0;
}