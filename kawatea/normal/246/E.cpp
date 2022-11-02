#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int p;
int a[100000];
int b[100000];
int d[100000];
int l[100000];
int r[100000];
int f[100000];
vector <int> v[100000];
vector <pair<int, int> > w[100000];
map <string, int> mp;
map <pair<int, int>, int> mp2[100000];

void dfs(int x, int y)
{
    int i;
    
    d[x] = y;
    w[y].push_back(make_pair(p, a[x]));
    
    l[x] = p++;
    
    for (i = 0; i < v[x].size(); i++) dfs(v[x][i], y + 1);
    
    r[x] = p++;
}

int query(int x, int y)
{
    int z = d[x] + y, p, q, sum = 0, i;
    
    if (z >= 100000) return 0;
    
    p = lower_bound(w[z].begin(), w[z].end(), make_pair(l[x], 0)) - w[z].begin();
    q = lower_bound(w[z].begin(), w[z].end(), make_pair(r[x], 0)) - w[z].begin();
    
    if (mp2[z].count(make_pair(p, q))) return mp2[z][make_pair(p, q)];
    
    for (i = p; i < q; i++) {
        if (f[w[z][i].second] == 0) {
            sum++;
            
            f[w[z][i].second] = 1;
        }
    }
    
    for (i = p; i < q; i++) f[w[z][i].second] = 0;
    
    return mp2[z][make_pair(p, q)] = sum;
}

int main()
{
    int n, m, c = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        char s[21];
        
        scanf("%s %d", s, &x);
        
        if (mp.count(string(s))) {
            a[i] = mp[string(s)];
        } else {
            mp[string(s)] = c;
            
            a[i] = c++;
        }
        
        if (x == 0) {
            b[i] = 1;
        } else {
            v[x - 1].push_back(i);
        }
    }
    
    for (i = 0; i < n; i++) {
        if (b[i] == 1) dfs(i, 0);
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        printf("%d\n", query(x - 1, y));
    }
    
    return 0;
}