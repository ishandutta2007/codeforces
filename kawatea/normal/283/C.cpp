#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long t;
int a[300];
int b[300];
int c[300];
long long dp[100001];
vector <int> v[300];
vector <int> v2[300];
vector <int> w;

void dfs(int x, int y)
{
    int i;
    
    y += a[x];
    
    w.push_back(y);
    
    for (i = 0; i < v[x].size(); i++) dfs(v[x][i], y);
}

void dfs2(int x, int y)
{
    int i;
    
    t -= y * a[x];
    
    for (i = 0; i < v2[x].size(); i++) dfs2(v2[x][i], y + 1);
}

int main()
{
    int n, q, m = 1000000007, i, j;
    
    scanf("%d %d %I64d", &n, &q, &t);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < q; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v2[y].push_back(x);
        
        b[y]++;
        c[x]++;
    }
    
    for (i = 0; i < n; i++) {
        if (b[i] == 0) dfs(i, 0);
    }
    
    if (w.size() != n) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (c[i] == 0) dfs2(i, 0);
    }
    
    if (t < 0) {
        puts("0");
        
        return 0;
    }
    
    dp[0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = w[i]; j <= t; j++) {
            dp[j] = (dp[j] + dp[j - w[i]]) % m;
        }
    }
    
    printf("%d\n", (int)dp[t]);
    
    return 0;
}