#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];
vector <int> v[100000];
vector <int> w[100000];
vector <int> z;

int dfs(int x, int y)
{
    int ans = 0, i;
    
    if (a[x] == 1 && y == 1) return 0;
    
    if (a[x] == 0 && v[x].size() > 1) return 0;
    
    for (i = 0; i < w[x].size(); i++) {
        ans = max(ans, dfs(w[x][i], 1));
    }
    
    return b[x] = ans + 1;
}

void dfs2(int x, int y)
{
    int i;
    
    if (b[x] == 0) return;
    
    for (i = 0; i < w[x].size(); i++) {
        if (b[w[x][i]] == y - 1) {
            dfs2(w[x][i], y - 1);
            
            break;
        }
    }
    
    z.push_back(x + 1);
}

int main()
{
    int n, ans = 0, num, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 0) continue;
        
        v[x - 1].push_back(i);
        w[i].push_back(x - 1);
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            int tmp = dfs(i, 0);
            
            if (tmp > ans) {
                ans = tmp;
                num = i;
            }
        }
    }
    
    dfs2(num, ans);
    
    printf("%d\n", ans);
    
    for (i = 0; i < z.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", z[i]);
    }
    
    puts("");
    
    return 0;
}