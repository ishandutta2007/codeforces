#include <cstdio>
#include <vector>

using namespace std;

long long a[80000];
vector <int> v[80000];

int dfs(int x, int y)
{
    int i;
    
    a[x] = 1;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        a[x] += dfs(v[x][i], x);
    }
    
    return a[x];
}

long long dfs2(int x, int y, int z)
{
    int i;
    long long sum = 0, tmp = 0, tmp2 = 0, tmp3 = 0;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        tmp += a[v[x][i]] * (a[v[x][i]] - 1) / 2;
        tmp2 += a[v[x][i]] * tmp3;
        tmp3 += a[v[x][i]];
    }
    
    for (i = 0; i < v[x].size(); i++) {
        long long p = a[v[x][i]];
        long long q = a[x] - a[v[x][i]];
        
        if (v[x][i] == y) continue;
        
        sum += p * (p - 1) / 2 * (tmp - p * (p - 1) / 2);
        sum += p * (p - 1) / 2 * (tmp2 - p * (tmp3 - p)) * 2;
        sum += p * (p - 1) / 2 * (tmp3 - p) * 2;
        sum += p * (p - 1) / 2 * z * 2;
        sum += p * (p - 1) / 2 * (tmp3 - p) * z * 2;
        
        sum += dfs2(v[x][i], x, z + q);
    }
    
    return sum;
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
    
    dfs(0, -1);
    
    printf("%I64d\n", dfs2(0, -1, 0));
    
    return 0;
}