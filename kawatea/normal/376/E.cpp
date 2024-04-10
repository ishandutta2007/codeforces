#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int d[20][20][1 << 16];

int main()
{
    int n, m, sx, sy, c = 0, ans = 0, i, j, k;
    int a[8];
    int b[8][2];
    char s[20][21];
    vector <pair<int, int> > v;
    queue <pair<int, pair<int, int> > > q;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                sx = i;
                sy = j;
                s[i][j] = '.';
            } else if (s[i][j] == 'B') {
                v.push_back(make_pair(i, j));
            } else if (s[i][j] >= '1' && s[i][j] <= '8') {
                b[s[i][j] - '1'][0] = i;
                b[s[i][j] - '1'][1] = j;
                
                c++;
            }
        }
    }
    
    for (i = 0; i < c; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < v.size(); i++) {
        s[v[i].first][v[i].second] = c + '1';
        b[c][0] = v[i].first;
        b[c][1] = v[i].second;
        a[c++] = -1e8;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < (1 << (c * 2)); k++) {
                d[i][j][k] = 1e9;
            }
        }
    }
    
    d[sx][sy][0] = 0;
    q.push(make_pair(sx, make_pair(sy, 0)));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        
        q.pop();
        
        if (x == sx && y == sy) {
            int sum = 0;
            
            for (i = 0; i < c; i++) {
                if ((z >> (i * 2)) & 1) sum += a[i];
            }
            
            ans = max(ans, sum - d[x][y][z]);
        }
        
        for (i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] != '.') continue;
            
            for (j = 0; j < c; j++) {
                if (ny < b[j][1]) {
                    if ((x == b[j][0] && nx == b[j][0] - 1) || (x == b[j][0] - 1 && nx == b[j][0])) {
                        nz ^= (1 << (j * 2));
                    } else if ((x == b[j][0] && nx == b[j][0] + 1) || (x == b[j][0] + 1 && nx == b[j][0])) {
                        nz ^= (1 << (j * 2 + 1));
                    }
                }
            }
            
            if (d[nx][ny][nz] > d[x][y][z] + 1) {
                d[nx][ny][nz] = d[x][y][z] + 1;
                q.push(make_pair(nx, make_pair(ny, nz)));
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}