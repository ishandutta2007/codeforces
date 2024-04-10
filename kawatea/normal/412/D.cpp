#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[30000];
vector <int> w[30000];
vector <int> z;
int f[30000];
int c[30000];

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
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        w[y].push_back(x);
    }
    
    scc(n);
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", z[i] + 1);
    }
    
    puts("");
    
    return 0;
}