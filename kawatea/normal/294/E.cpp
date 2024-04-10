#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[5000][3];
long long b[5000];
int c[5000];
int d[5000];
int e[5000];
long long g[5000];
vector <pair<int, int> > v[5000];

int dfs(int x, int y, int z)
{
    int c = 1, i;
    
    for (i = 0; i < v[y].size(); i++) {
        int p;
        
        if (v[y][i].first == z) continue;
        
        p = dfs(x, v[y][i].first, y);
        
        b[x] += (long long)v[y][i].second * p;
        
        c += p;
    }
    
    return c;
}

int dfs2(int x, int y, int z)
{
    int i;
    
    c[x] = 1;
    d[x] = z;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i].first == y) continue;
        
        c[x] += dfs2(v[x][i].first, x, z + 1);
    }
    
    return c[x];
}

pair <int, long long> dfs3(int x, int y, int z, int w, long long s)
{
    int c = 1, i;
    long long sum = 0;
    
    e[x] = w;
    g[x] = s * z;
    
    for (i = 0; i < v[x].size(); i++) {
        pair <int, long long> p;
        
        if (v[x][i].first == y) continue;
        
        p = dfs3(v[x][i].first, x, z, w, s + v[x][i].second);
        c += p.first;
        sum += (long long)v[x][i].second * p.first + p.second;
    }
    
    return make_pair(c, sum);
}

int main()
{
    int n, i, j;
    long long sum = 0, ans = 1e18;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        
        a[i][0]--;
        a[i][1]--;
        
        v[a[i][0]].push_back(make_pair(a[i][1], a[i][2]));
        v[a[i][1]].push_back(make_pair(a[i][0], a[i][2]));
    }
    
    for (i = 0; i < n; i++) dfs(i, i, -1);
    
    for (i = 0; i < n; i++) sum += b[i];
    
    sum /= 2;
    
    dfs2(0, -1, 0);
    
    for (i = 0; i < n - 1; i++) {
        int p, q;
        long long tmp, tmp2, tmp3 = sum, x = 1e18, y = 1e18;
        
        if (d[a[i][0]] < d[a[i][1]]) {
            p = n - c[a[i][1]];
            q = c[a[i][1]];
        } else {
            p = c[a[i][0]];
            q = n - c[a[i][0]];
        }
        
        tmp = dfs3(a[i][0], a[i][1], q, 0, 0).second;
        tmp2 = dfs3(a[i][1], a[i][0], p, 1, 0).second;
        
        for (j = 0; j < n; j++) {
            if (e[j] == 0) {
                x = min(x, b[j] - g[j] - tmp2 - (long long)a[i][2] * q);
            } else {
                y = min(y, b[j] - g[j] - tmp - (long long)a[i][2] * p);
            }
            
            tmp3 -= g[j];
        }
        
        tmp3 += x * q + y * p;
        
        ans = min(ans, tmp3);
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}