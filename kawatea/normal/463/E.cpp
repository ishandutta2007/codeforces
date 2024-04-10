#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[100000];
int b[2000001];
int c[2000001];
int d[100000];
int ans[100000];
vector <int> v[100000];

void dfs(int x, int y, int z)
{
    int i;
    
    d[x] = z;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        dfs(v[x][i], x, z + 1);
    }
}

void dfs2(int x, int y, vector <int> &w)
{
    int p = a[x], i;
    vector <int> z, z2;
    
    while (p > 1) {
        int q = c[p];
        
        while (p % q == 0) p /= q;
        
        z.push_back(q);
    }
    
    ans[x] = -1;
    
    for (i = 0; i < z.size(); i++) {
        if (w[z[i]] != -1) {
            if (ans[x] != -1 && d[ans[x]] >= d[w[z[i]]]) continue;
            
            ans[x] = w[z[i]];
        }
    }
    
    if (ans[x] >= 0) ans[x]++;
    
    for (i = 0; i < z.size(); i++) {
        z2.push_back(w[z[i]]);
        
        w[z[i]] = x;
    }
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        dfs2(v[x][i], x, w);
    }
    
    for (i = 0; i < z.size(); i++) w[z[i]] = z2[i];
}

int main()
{
    int q;
    long long i, j;
    vector <int> w(2000001, -1);
    
    b[0] = b[1] = 1;
    c[0] = 0;
    c[1] = 1;
    
    for (i = 2; i <= 2000000; i++) {
        if (b[i] == 0) {
            c[i] = i;
            
            for (j = i * i; j <= 2000000; j += i) {
                b[j] = 1;
                if (c[j] == 0) c[j] = i;
            }
        }
    }
    
    scanf("%d %d", &n, &q);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(0, -1, 0);
    dfs2(0, -1, w);
    
    for (i = 0; i < q; i++) {
        int t;
        
        scanf("%d", &t);
        
        if (t == 1) {
            int x;
            
            scanf("%d", &x);
            
            printf("%d\n", ans[x - 1]);
        } else {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            a[x - 1] = y;
            
            dfs2(0, -1, w);
        }
    }
    
    return 0;
}