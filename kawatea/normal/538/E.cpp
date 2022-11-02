#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[200000];

int get(int x, int y)
{
    int ans = 0, i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        ans += get(v[x][i], x);
    }
    
    if (ans == 0) ans++;
    
    return ans;
}

int dfs(int x, int y, int z)
{
    int c = 0, i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        c++;
    }
    
    if (c == 0) return 0;
    
    if (z == 0) {
        int ans = 1e9;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            ans = min(ans, dfs(v[x][i], x, 1 - z));
        }
        
        return ans;
    } else {
        int ans = c - 1;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            ans += dfs(v[x][i], x, 1 - z);
        }
        
        return ans;
    }
}

int dfs2(int x, int y, int z)
{
    int c = 0, i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        c++;
    }
    
    if (c == 0) return 0;
    
    if (z == 0) {
        int ans = c - 1;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            ans += dfs2(v[x][i], x, 1 - z);
        }
        
        return ans;
    } else {
        int ans = 1e9;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            ans = min(ans, dfs2(v[x][i], x, 1 - z));
        }
        
        return ans;
    }
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    printf("%d %d\n", get(0, -1) - dfs(0, -1, 0), dfs2(0, -1, 0) + 1);
    
    return 0;
}