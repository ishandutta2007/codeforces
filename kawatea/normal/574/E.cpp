#include <cstdio>
#include <vector>
#include <map>

using namespace std;

vector <int> v[100000];
map <int, bool> mp[100000][4];

bool dfs(int x, int y, int z) {
    int i;
    
    if (mp[x][z].count(y)) return mp[x][z][y];
    
    if (v[x].size() == 1) return mp[x][z][y] = true;
    
    if (z <= 1) {
        int c = 0;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            if (dfs(v[x][i], x, 2)) continue;
            
            if (!dfs(v[x][i], x, 1)) return mp[x][z][y] = false;
            
            c++;
        }
        
        if (c <= 2 - z) {
            return mp[x][z][y] = true;
        } else {
            return mp[x][z][y] = false;
        }
    } else if (z == 2) {
        if (v[x].size() > 3) return mp[x][z][y] = false;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            if (!dfs(v[x][i], x, 3)) return mp[x][z][y] = false;
        }
        
        return mp[x][z][y] = true;
    } else if (z == 3) {
        if (v[x].size() > 2) return mp[x][z][y] = false;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            return mp[x][z][y] = dfs(v[x][i], x, 3);
        }
    }
}

int main()
{
    int n, c = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    if (n <= 2) {
        puts("Yes");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (v[i].size() > v[c].size()) c = i;
    }
    
    if (v[c].size() > 3) {
        if (dfs(c, -1, 0)) {
            puts("Yes");
        } else {
            puts("No");
        }
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (v[i].size() == 1) continue;
        
        if (dfs(i, -1, 0)) {
            puts("Yes");
            
            return 0;
        }
    }
    
    puts("No");
    
    return 0;
}