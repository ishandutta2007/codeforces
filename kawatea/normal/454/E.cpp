#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int f[100000];
vector <int> v[100000];
vector <int> w[100000];
vector <int> ans;

void dfs(int x, int y)
{
    int i;
    
    f[x] = 1;
    
    for (i = 0; i < v[x].size(); i++) {
        if (f[v[x][i]] == 0) {
            dfs(v[x][i], x);
            
            w[x].push_back(v[x][i]);
        }
    }
}

void dfs2(int x)
{
    int i;
    
    a[x] = 1 - a[x];
    ans.push_back(x);
    
    for (i = 0; i < w[x].size(); i++) {
        dfs2(w[x][i]);
        
        a[x] = 1 - a[x];
        ans.push_back(x);
        
        if (a[w[x][i]] == 1) {
            a[x] = 1 - a[x];
            ans.push_back(w[x][i]);
            ans.push_back(x);
        }
    }
}

int main()
{
    int n, m, c, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            dfs(i, -1);
            
            c = i;
            
            break;
        }
    }
    
    if (i == n) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (f[i] == 0 && a[i] == 1) {
            puts("-1");
            
            return 0;
        }
    }
    
    dfs2(c);
    
    if (a[c] == 1) ans.erase(ans.begin());
    
    printf("%d\n", ans.size());
    
    for (i = 0; i < ans.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", ans[i] + 1);
    }
    
    puts("");
    
    return 0;
}