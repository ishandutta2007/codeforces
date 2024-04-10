#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
vector <int> v[100000];

pair <long long, long long> dfs(int x, int y)
{
    int i;
    long long z;
    pair <long long, long long> p, q;
    
    p.first = p.second = 0;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        q = dfs(v[x][i], x);
        
        p.first = max(p.first, q.first);
        p.second = max(p.second, q.second);
    }
    
    z = a[x] + p.first - p.second;
    
    if (z < 0) {
        p.first -= z;
    } else {
        p.second += z;
    }
    
    return p;
}

int main()
{
    int n, i;
    pair <long long, long long> p;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    p = dfs(0, -1);
    
    printf("%I64d\n", p.first + p.second);
    
    return 0;
}