#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> v[1000];
int match[1000];
int level[1000];
bool f[1000];

bool dfs(int x)
{
    f[x] = true;
    
    for (int i = 0; i < v[x].size(); i++) {
        int u = v[x][i], w = match[u];
        
        if (w < 0 || (f[w] == 0 && level[x] < level[w] && dfs(w))) {
            match[x] = u;
            match[u] = x;
            
            return true;
        }
    }
    
    return false;
}

int bipartite_matching(int n)
{
    int ans = 0;
    
    for (int i = 0; i < n; i++) match[i] = -1;
    
    while (1) {
        int d = 0;
        queue <int> q;
        
        for (int i = 0; i < n; i++) level[i] = -1;
        
        for (int i = 0; i < n; i++) {
            if (match[i] < 0) {
                q.push(i);
                level[i] = 0;
            }
        }
        
        while (!q.empty()) {
            int x = q.front();
            
            q.pop();
            
            for (int i = 0; i < v[x].size(); i++) {
                int u = v[x][i], w = match[u];
                
                if (w != -1 && level[w] < 0) {
                    level[w] = level[x] + 1;
                    q.push(w);
                }
            }
        }
        
        for (int i = 0; i < n; i++) f[i] = false;
        
        for (int i = 0; i < n; i++) {
            if (match[i] == -1 && dfs(i)) d++;
        }
        
        if (d == 0) return ans;
        
        ans += d;
    }
}

int main()
{
    int n, m, ans = 1e9, i, j;
    int a[1000][2];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        
        a[i][0]--;
        a[i][1]--;
    }
    
    for (i = 0; i < n; i++) {
        int sum = n * 3 + m - 2;
        
        for (j = 0; j < n * 2; j++) v[j].clear();
        
        for (j = 0; j < m; j++) {
            if (a[j][0] == i || a[j][1] == i) {
                sum -= 2;
                
                continue;
            }
            
            v[a[j][0]].push_back(a[j][1] + n);
            v[a[j][1] + n].push_back(a[j][0]);
        }
        
        sum -= 2 * bipartite_matching(n * 2);
        
        ans = min(ans, sum);
    }
    
    printf("%d\n", ans);
    
    return 0;
}