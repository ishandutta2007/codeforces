#include <cstdio>

using namespace std;

int par[50];
int cnt[50];

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
    int n, m, c = 0, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        unite(x - 1, y - 1);
    }
    
    for (i = 0; i < n; i++) cnt[find(i)]++;
    
    for (i = 0; i < n; i++) {
        if (cnt[i] > 0) c++;
    }
    
    printf("%I64d\n", 1LL << (n - c));
    
    return 0;
}