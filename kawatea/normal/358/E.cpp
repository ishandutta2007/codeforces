#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a[1000][1000];
int b[1000][1000];
int f[1000][1000];
int sum[4][1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int gcd(int a, int b)
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    int n, m, x = -1, y = -1, g = -1, i, j, k;
    vector <int> v;
    vector <int> w;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                if (j == 0) {
                    sum[0][i][j] = 1;
                } else {
                    sum[0][i][j] = sum[0][i][j - 1] + 1;
                }
            } else {
                sum[0][i][j] = 0;
            }
        }
        
        for (j = m - 1; j >= 0; j--) {
            if (a[i][j] == 1) {
                sum[1][i][j] = sum[1][i][j + 1] + 1;
            } else {
                sum[1][i][j] = 0;
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[j][i] == 1) {
                if (j == 0) {
                    sum[2][j][i] = 1;
                } else {
                    sum[2][j][i] = sum[2][j - 1][i] + 1;
                }
            } else {
                sum[2][j][i] = 0;
            }
        }
        
        for (j = n - 1; j >= 0; j--) {
            if (a[j][i] == 1) {
                sum[3][j][i] = sum[3][j + 1][i] + 1;
            } else {
                sum[3][j][i] = 0;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 1 && x == -1) {
                x = i;
                y = j;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        int x = 0;
        
        for (j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                if (x > 1) {
                    if (g == -1) {
                        g = x - 1;
                    } else {
                        g = gcd(g, x - 1);
                    }
                }
                
                x = 0;
            } else {
                x++;
            }
        }
        
        if (x > 1) {
            if (g == -1) {
                g = x - 1;
            } else {
                g = gcd(g, x - 1);
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        int x = 0;
        
        for (j = 0; j < n; j++) {
            if (a[j][i] == 0) {
                if (x > 1) {
                    if (g == -1) {
                        g = x - 1;
                    } else {
                        g = gcd(g, x - 1);
                    }
                }
                
                x = 0;
            } else {
                x++;
            }
        }
        
        if (x > 1) {
            if (g == -1) {
                g = x - 1;
            } else {
                g = gcd(g, x - 1);
            }
        }
    }
    
    for (i = 2; i <= g; i++) {
        if (g % i == 0) v.push_back(i);
    }
    
    for (i = 0; i < v.size(); i++) {
        int c1 = 0;
        queue <pair<int, int> > q;
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                b[j][k] = f[j][k] = 0;
            }
        }
        
        f[x][y] = 1;
        q.push(make_pair(x, y));
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            int c = 0;
            
            q.pop();
            
            b[x][y] = 1;
            
            for (j = 0; j < 4; j++) {
                if (sum[j][x][y] <= v[i]) continue;
                
                c++;
                
                for (k = 1; k <= v[i]; k++) b[x + dx[j] * k][y + dy[j] * k] = 1;
                
                if (f[x + dx[j] * v[i]][y + dy[j] * v[i]] == 1) continue;
                
                f[x + dx[j] * v[i]][y + dy[j] * v[i]] = 1;
                q.push(make_pair(x + dx[j] * v[i], y + dy[j] * v[i]));
            }
            
            if (c & 1) c1++;
        }
        
        if (c1 <= 2) {
            int f1 = 0;
            
            for (j = 0; j < n; j++) {
                for (k = 0; k < m; k++) {
                    if (a[j][k] != b[j][k]) {
                        f1 = 1;
                        
                        break;
                    }
                }
            }
            
            if (f1 == 0) w.push_back(v[i]);
        }
    }
    
    if (w.size() == 0) {
        puts("-1");
        
        return 0;
    }
    
    for (i = 0; i < w.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", w[i]);
    }
    
    puts("");
    
    return 0;
}