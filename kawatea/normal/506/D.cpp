#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int d[100000];
int par[500][100000];
vector <pair<int, pair<int, int> > > v[100001];
map <int, int> mp[100000];

int find(int x, int y)
{
    if (par[x][y] == y) return y;
    
    return par[x][y] = find(x, par[x][y]);
}

void unite(int x, int y, int z)
{
    y = find(x, y);
    z = find(x, z);
    
    if (y == z) return;
    
    par[x][y] = z;
}

int main()
{
    int n, m, q, i, j, k, l;
    vector <pair<int, int> > w;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        v[z].push_back(make_pair(x - 1, make_pair(y - 1, 0)));
    }
    
    for (i = 1; i <= m; i++) {
        if (v[i].size() == 0) continue;
        
        w.push_back(make_pair(v[i].size(), i));
    }
    
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    
    for (i = 0; i < w.size() && i < 500; i++) {
        int x = w[i].second;
        
        for (j = 0; j < n; j++) par[i][j] = j;
        
        for (j = 0; j < v[x].size(); j++) unite(i, v[x][j].first, v[x][j].second.first);
    }
    
    for (; i < w.size(); i++) {
        int x = w[i].second;
        vector <int> z;
        queue <int> q;
        
        for (j = 0; j < v[x].size(); j++) {
            int c = 0;
            
            if (v[x][j].second.second == 1) continue;
            
            d[v[x][j].first] = 1;
            z.push_back(v[x][j].first);
            q.push(v[x][j].first);
            
            while (!q.empty()) {
                int y = q.front();
                
                q.pop();
                
                c++;
                
                for (k = 0; k < v[x].size(); k++) {
                    if (v[x][k].first == y) {
                        if (d[v[x][k].second.first] == 0) {
                            v[x][k].second.second = 1;
                            d[v[x][k].second.first] = 1;
                            z.push_back(v[x][k].second.first);
                            q.push(v[x][k].second.first);
                        }
                    } else if (v[x][k].second.first == y) {
                        if (d[v[x][k].first] == 0) {
                            v[x][k].second.second = 1;
                            d[v[x][k].first] = 1;
                            z.push_back(v[x][k].first);
                            q.push(v[x][k].first);
                        }
                    }
                }
            }
            
            for (k = 1; k <= c; k++) {
                for (l = k + 1; l <= c; l++) {
                    int x = z[z.size() - k];
                    int y = z[z.size() - l];
                    
                    if (x > y) swap(x, y);
                    
                    mp[x][y]++;
                }
            }
        }
        
        for (j = 0; j < z.size(); j++) d[z[j]] = 0;
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int x, y, ans = 0;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        if (x > y) swap(x, y);
        
        for (j = 0; j < w.size() && j < 500; j++) {
            if (find(j, x) == find(j, y)) ans++;
        }
        
        ans += mp[x][y];
        
        printf("%d\n", ans);
    }
    
    return 0;
}