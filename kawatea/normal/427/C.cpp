#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[100000];
vector <int> w[100000];
vector <int> z;
vector <int> p[100000];
int a[100000];
int f[100000];
int c[100000];

void dfs(int x)
{
    f[x] = 1;
    
    for (int i = 0; i < v[x].size(); i++) {
        if (f[v[x][i]] == 0) dfs(v[x][i]);
    }
    
    z.push_back(x);
}

void dfs2(int x, int k)
{
    f[x] = 1;
    c[x] = k;
    
    for (int i = 0; i < w[x].size(); i++) {
        if (f[w[x][i]] == 0) dfs2(w[x][i], k);
    }
}

int scc(int n)
{
    int k = 0;
    
    for (int i = 0; i < n; i++) f[i] = 0;
    
    z.clear();
    
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) dfs(i);
    }
    
    for (int i = 0; i < n; i++) f[i] = 0;
    
    for (int i = z.size() - 1; i >= 0; i--) {
        if (f[z[i]] == 0) dfs2(z[i], k++);
    }
    
    return k;
}

int main()
{
    int n, m, mod = 1000000007, i, j;
    long long sum = 0, ans = 1;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        w[y].push_back(x);
    }
    
    scc(n);
    
    for (i = 0; i < n; i++) p[c[i]].push_back(a[i]);
    
    for (i = 0; i < n; i++) {
        if (p[i].size() == 0) continue;
        
        sort(p[i].begin(), p[i].end());
        
        for (j = 0; j < p[i].size(); j++) {
            if (p[i][j] != p[i][0]) break;
        }
        
        sum += p[i][0];
        ans = ans * j % mod;
    }
    
    printf("%I64d %I64d\n", sum, ans);
    
    return 0;
}