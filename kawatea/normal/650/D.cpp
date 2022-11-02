#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[400002];
int b[400002];
int c[400002];
int d[400002];
int f[400002];
int g[400000][2];
int p[400000];
int p2[400000];
vector <int> v[400002];
vector <pair<int, int> > w[400002];

int main()
{
    int n, m, r, i, j;
    
    scanf("%d %d", &n, &m);
    
    a[0] = 0;
    a[n + 1] = 1e9 + 1;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    n += 2;
    
    for (i = 0; i < n; i++) d[i] = 1e9 + 2;
    
    for (i = 0; i < n; i++) {
        int x = lower_bound(d, d + n, a[i]) - d;
        d[x] = a[i];
        b[i] = x;
    }
    
    r = lower_bound(d, d + n, 1e9 + 2) - d - 2;
    
    for (i = 0; i < n; i++) d[i] = 1e9 + 2;
    
    for (i = n - 1; i >= 0; i--) {
        int x = lower_bound(d, d + n, -a[i]) - d;
        d[x] = -a[i];
        c[i] = x;
    }
    
    for (i = 0; i < n; i++) {
        if (b[i] + c[i] == r + 1) {
            f[i] = 1;
            v[b[i]].push_back(i);
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        g[i][0] = x;
        g[i][1] = y;
        w[x].push_back(make_pair(i, y));
    }
    
    for (i = 0; i < n; i++) d[i] = 1e9 + 2;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < w[i].size(); j++) {
            int x = w[i][j].first;
            int y = w[i][j].second;
            
            p[x] = lower_bound(d, d + n, y) - d;
        }
        
        d[lower_bound(d, d + n, a[i]) - d] = a[i];
    }
    
    for (i = 0; i < n; i++) d[i] = 1e9 + 2;
    
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < w[i].size(); j++) {
            int x = w[i][j].first;
            int y = w[i][j].second;
            
            p2[x] = lower_bound(d, d + n, -y) - d;
        }
        
        d[lower_bound(d, d + n, -a[i]) - d] = -a[i];
    }
    
    for (i = 0; i < m; i++) {
        int x = g[i][0], y = g[i][1], ans = r;
        
        if (f[x] == 1 && v[b[x]].size() == 1) ans--;
        
        ans = max(ans, p[i] + p2[i] - 1);
        
        printf("%d\n", ans);
    }
    
    return 0;
}