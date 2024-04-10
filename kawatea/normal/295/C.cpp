#include <cstdio>
#include <queue>

using namespace std;

int f[2][51][51];
long long d[2][51][51];
long long c[51][51];

int main()
{
    int n, k, m = 1000000007, a = 0, b = 0, t = -1, i, j;
    long long sum = 0;
    queue <pair<int, pair<int, int> > > q;
    
    c[0][0] = 1;
    
    for (i = 1; i <= 50; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
    }
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 50) {
            a++;
        } else {
            b++;
        }
    }
    
    for (i = 0; i <= 50; i++) {
        for (j = 0; j <= 50; j++) {
            f[0][i][j] = f[1][i][j] = -1;
        }
    }
    
    d[0][0][0] = 1;
    f[0][0][0] = 0;
    q.push(make_pair(0, make_pair(0, 0)));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        
        q.pop();
        
        if (x % 2 == 0) {
            if ((a - y) * 50 + (b - z) * 100 <= k) {
                if (t == -1 || x + 1 == t) {
                    t = x + 1;
                    sum = (sum + d[0][y][z]) % m;
                }
            } else if (t == -1) {
                for (i = 0; i <= a - y; i++) {
                    for (j = 0; j <= b - z; j++) {
                        int ny, nz;
                        
                        if (i * 50 + j * 100 > k) continue;
                        
                        if (i + j == 0) continue;
                        
                        ny = y + i;
                        nz = z + j;
                        
                        if (f[1][ny][nz] == -1 || f[1][ny][nz] == x + 1) {
                            if (f[1][ny][nz] == -1) q.push(make_pair(x + 1, make_pair(ny, nz)));
                            
                            f[1][ny][nz] = x + 1;
                            d[1][ny][nz] = (d[1][ny][nz] + d[0][y][z] * c[a - y][i] % m * c[b - z][j] % m) % m;
                        }
                    }
                }
            }
        } else {
            for (i = 0; i <= y; i++) {
                for (j = 0; j <= z; j++) {
                    int ny, nz;
                    
                    if (i * 50 + j * 100 > k) continue;
                    
                    if (i + j == 0) continue;
                    
                    ny = y - i;
                    nz = z - j;
                    
                    if (f[0][ny][nz] == -1 || f[0][ny][nz] == x + 1) {
                        if (f[0][ny][nz] == -1) q.push(make_pair(x + 1, make_pair(ny, nz)));
                        
                        f[0][ny][nz] = x + 1;
                        d[0][ny][nz] = (d[0][ny][nz] + d[1][y][z] * c[y][i] % m * c[z][j] % m) % m;
                    }
                    
                }
            }
        }
    }
    
    printf("%d\n", t);
    printf("%I64d\n", sum);
    
    return 0;
}