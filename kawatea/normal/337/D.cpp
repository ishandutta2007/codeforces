#include <cstdio>
#include <vector>

using namespace std;

int d, ans;
int a[100000];
vector <int> v[100000];
vector <int> w[100000];

int dfs(int x, int y)
{
    int p = 1e9, i;
    
    if (a[x] == 1) p = d - 1;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) {
            w[x].push_back(-1e9);
        } else {
            w[x].push_back(dfs(v[x][i], x));
            
            p = min(p, w[x].back() - 1);
        }
    }
    
    return p;
}

void dfs2(int x, int y, int z)
{
    int x1 = 1e9, y1, x2 = 1e9, y2, i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) {
            if (z <= x1) {
                x2 = x1;
                y2 = y1;
                x1 = z;
                y1 = -1;
            } else if (z <= x2) {
                x2 = z;
                y2 = -1;
            }
        } else {
            if (w[x][i] <= x1) {
                x2 = x1;
                y2 = y1;
                x1 = w[x][i];
                y1 = i;
            } else if (w[x][i] <= x2) {
                x2 = w[x][i];
                y2 = i;
            }
        }
    }
    
    if (a[x] == 1) {
        if (d <= x1) {
            x2 = x1;
            y2 = y1;
            x1 = d;
            y1 = -1;
        } else if (d <= x2) {
            x2 = d;
            y2 = -1;
        }
    }
    
    if (x1 >= 0) ans++;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        if (i == y1) {
            dfs2(v[x][i], x, x2 - 1);
        } else {
            dfs2(v[x][i], x, x1 - 1);
        }
    }
}

int main()
{
    int n, m, i;
    
    scanf("%d %d %d", &n, &m, &d);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x - 1]++;
    }
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(0, -1);
    
    dfs2(0, -1, 1e9);
    
    printf("%d\n", ans);
    
    return 0;
}