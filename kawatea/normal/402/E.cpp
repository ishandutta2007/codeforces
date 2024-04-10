#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[2000];
vector <int> w[2000];
vector <int> z;
int f[2000];
int c[2000];

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
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int x;
            
            scanf("%d", &x);
            
            if (x > 0) {
                v[i].push_back(j);
                w[j].push_back(i);
            }
        }
    }
    
    if (scc(n) == 1) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}