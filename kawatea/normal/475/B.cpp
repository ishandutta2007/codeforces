#include <cstdio>
#include <queue>

using namespace std;

int a[20][20];
char s[21];
char t[21];

int main()
{
    int n, m, i, j, k, l;
    
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    scanf("%s", t);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            queue <pair<int, int> > q;
            
            for (k = 0; k < n; k++) {
                for (l = 0; l < m; l++) {
                    a[k][l] = 0;
                }
            }
            
            a[i][j] = 1;
            q.push(make_pair(i, j));
            
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                if (s[x] == '<') {
                    if (y > 0 && a[x][y - 1] == 0) {
                        a[x][y - 1] = 1;
                        q.push(make_pair(x, y - 1));
                    }
                } else {
                    if (y < m - 1 && a[x][y + 1] == 0) {
                        a[x][y + 1] = 1;
                        q.push(make_pair(x, y + 1));
                    }
                }
                
                if (t[y] == '^') {
                    if (x > 0 && a[x - 1][y] == 0) {
                        a[x - 1][y] = 1;
                        q.push(make_pair(x - 1, y));
                    }
                } else {
                    if (x < n - 1 && a[x + 1][y] == 0) {
                        a[x + 1][y] = 1;
                        q.push(make_pair(x + 1, y));
                    }
                }
            }
            
            for (k = 0; k < n; k++) {
                for (l = 0; l < m; l++) {
                    if (a[k][l] == 0) {
                        puts("NO");
                        
                        return 0;
                    }
                }
            }
        }
    }
    
    puts("YES");
    
    return 0;
}