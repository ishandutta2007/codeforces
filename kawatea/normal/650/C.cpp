#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[1000000];
vector <int> w[1000000];
vector <int> z;
int f[1000000];
int c[1000000];
int a[1000000];
int d[1000000];
vector <pair<int, int> > vx[1000000];
vector <pair<int, int> > vy[1000000];
vector <int> v2[1000000];

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
    int n, m, p = 0, q, r = 0, i, j, k;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[p]);
            
            vx[i].push_back(make_pair(a[p], p));
            vy[j].push_back(make_pair(a[p], p));
            
            p++;
        }
    }
    
    for (i = 0; i < n; i++) {
        sort(vx[i].begin(), vx[i].end());
        
        for (j = 0; j + 1 < m; j++) {
            v[vx[i][j].second].push_back(vx[i][j + 1].second);
            w[vx[i][j + 1].second].push_back(vx[i][j].second);
        }
        
        for (j = 0; j < m; ) {
            for (k = j; k < m; k++) {
                if (vx[i][j].first != vx[i][k].first) break;
            }
            
            if (k - 1 > j) {
                v[vx[i][k - 1].second].push_back(vx[i][j].second);
                w[vx[i][j].second].push_back(vx[i][k - 1].second);
            }
            
            j = k;
        }
    }
    
    for (i = 0; i < m; i++) {
        sort(vy[i].begin(), vy[i].end());
        
        for (j = 0; j + 1 < n; j++) {
            v[vy[i][j].second].push_back(vy[i][j + 1].second);
            w[vy[i][j + 1].second].push_back(vy[i][j].second);
        }
        
        for (j = 0; j < n; ) {
            for (k = j; k < n; k++) {
                if (vy[i][j].first != vy[i][k].first) break;
            }
            
            if (k - 1 > j) {
                v[vy[i][k - 1].second].push_back(vy[i][j].second);
                w[vy[i][j].second].push_back(vy[i][k - 1].second);
            }
            
            j = k;
        }
    }
    
    q = scc(p);
    
    for (i = 0; i < p; i++) {
        for (j = 0; j < v[i].size(); j++) {
            if (c[i] == c[v[i][j]]) continue;
            
            v2[c[i]].push_back(c[v[i][j]]);
        }
    }
    
    for (i = q - 1; i >= 0; i--) {
        for (j = 0; j < v2[i].size(); j++) d[i] = max(d[i], d[v2[i][j]] + 1);
        
        r = max(r, d[i]);
    }
    
    p = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (j > 0) putchar(' ');
            
            printf("%d", r - d[c[p]] + 1);
            
            p++;
        }
        
        puts("");
    }
    
    return 0;
}