#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int c = 0;
int a[100000];
int b[100000];
int p[17][100000];
int d[100000];
vector <int> e[100000];
vector <int> v[100000];

void dfs(int x, int y)
{
    int i;
    
    a[x] = c++;
    b[x] = v[y].size();
    d[x] = y;
    v[y].push_back(a[x]);
    
    for (i = 0; i < e[x].size(); i++) dfs(e[x][i], y + 1);
}

int parent(int x, int y)
{
    int c = 1, i;
    
    if (y == 0) return x;
    
    for (i = 0; ; i++) {
        if (c > y) return parent(p[i - 1][x], y - c / 2);
        
        c *= 2;
    }
}

int main()
{
    int n, m, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &p[0][i]);
        
        p[0][i]--;
        
        if (p[0][i] >= 0) e[p[0][i]].push_back(i);
    }
    
    for (i = 0; i < n; i++) {
        if (p[0][i] == -1) dfs(i, 0);
    }
    
    for (i = 0; i < 16; i++) {
        for (j = 0; j < n; j++) {
            if (p[i][j] < 0) {
                p[i + 1][j] = -1;
            } else {
                p[i + 1][j] = p[i][p[i][j]];
            }
        }
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y, p, s, t;
        
        scanf("%d %d", &x, &y);
        
        x--;
        
        if (i > 0) putchar(' ');
        
        if (d[x] < y) {
            putchar('0');
            
            continue;
        }
        
        p = parent(x, y);
        s = a[p];
        if (v[d[x] - y].size() == b[p] + 1) {
            t = 1e9;
        } else {
            t = v[d[x] - y][b[p] + 1];
        }
        
        printf("%d", lower_bound(v[d[x]].begin(), v[d[x]].end(), t) - lower_bound(v[d[x]].begin(), v[d[x]].end(), s) - 1);
    }
    
    puts("");
    
    return 0;
}