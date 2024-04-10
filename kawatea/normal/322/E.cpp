#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int ans[100000];
vector <int> v[100000];
bool centroid[100000];
int subtree_size[100000];

int compute_subtree_size(int x, int y)
{
    int c = 1, i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        if (centroid[v[x][i]]) continue;
        
        c += compute_subtree_size(v[x][i], x);
    }
    
    subtree_size[x] = c;
    
    return c;
}

pair <int, int> search_centroid(int x, int y, int t)
{
    int s = 1, m = 0, i;
    pair <int, int> ans = make_pair(1e9, -1);
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        if (centroid[v[x][i]]) continue;
        
        ans = min(ans, search_centroid(v[x][i], x, t));
        
        m = max(m, subtree_size[v[x][i]]);
        s += subtree_size[v[x][i]];
    }
    
    m = max(m, t - s);
    
    ans = min(ans, make_pair(m, x));
    
    return ans;
}

void dfs(int x, int y)
{
    int s, i;
    
    compute_subtree_size(x, -1);
    
    s = search_centroid(x, -1, subtree_size[x]).second;
    
    centroid[s] = true;
    ans[s] = y;
    
    for (i = 0; i < v[s].size(); i++) {
        if (centroid[v[s][i]]) continue;
        
        dfs(v[s][i], y + 1);
    }
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    
    dfs(0, 0);
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%c", ans[i] + 'A');
    }
    
    puts("");
    
    return 0;
}