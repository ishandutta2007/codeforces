#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int a[100000];
int par[100000];
vector <int> v[100000];
vector <int> w[100000];

int find(int x)
{
    if (par[x] == x) return x;
    
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main()
{
    int n, m, ans = 0, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        a[y]++;
        v[x].push_back(y);
        unite(x, y);
    }
    
    for (i = 0; i < n; i++) w[find(i)].push_back(i);
    
    for (i = 0; i < n; i++) {
        if (w[i].size() >= 2) {
            int c = 0;
            queue <int> q;
            
            for (j = 0; j < w[i].size(); j++) {
                if (a[w[i][j]] == 0) q.push(w[i][j]);
            }
            
            while (!q.empty()) {
                int x = q.front();
                
                q.pop();
                
                c++;
                
                for (j = 0; j < v[x].size(); j++) {
                    a[v[x][j]]--;
                    
                    if (a[v[x][j]] == 0) q.push(v[x][j]);
                }
            }
            
            if (c == w[i].size()) {
                ans += w[i].size() - 1;
            } else {
                ans += w[i].size();
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}