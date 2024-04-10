#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[200];
int b[200];
vector <int> g[200];
vector <int> v[3];

int dfs(int x)
{
    int sum = 0, r = n, i;
    int p[200];
    vector <int> w[3];
    
    for (i = 0; i < n; i++) p[i] = b[i];
    for (i = 0; i < 3; i++) w[i] = v[i];
    
    while (r) {
        while (w[x].size() > 0) {
            for (i = 0; i < g[w[x][0]].size(); i++) {
                int y = g[w[x][0]][i];
                
                p[y]--;
                
                if (p[y] == 0) w[a[y]].push_back(y);
            }
            
            w[x].erase(w[x].begin());
            
            r--;
            sum++;
        }
        
        x = (x + 1) % 3;
        
        if (r > 0) sum++;
    }
    
    return sum;
}

int main()
{
    int ans = 1e9, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        a[i]--;
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        
        for (j = 0; j < b[i]; j++) {
            int x;
            
            scanf("%d", &x);
            
            x--;
            
            g[x].push_back(i);
        }
        
        if (b[i] == 0) v[a[i]].push_back(i);
    }
    
    for (i = 0; i < 3; i++) {
        ans = min(ans, dfs(i));
    }
    
    printf("%d\n", ans);
    
    return 0;
}