#include <stdio.h>

int n, u, r;
int b[30], k[30], p[30];
long long ans = -1e18;

long long max(long long a, long long b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void dfs(int x, int y, int a[])
{
    int i;
    int c[30];
    
    if (x % 2 == 0) {
        long long sum = 0;
        
        for (i = 0; i < n; i++) sum += a[i] * k[i];
        
        ans = max(ans, sum);
    }
    
    if (x == 0) return;
    
    if (y != 0) {
        for (i = 0; i < n; i++) c[i] = a[i] ^ b[i];
        
        dfs(x - 1, 0, c);
    }
    
    for (i = 0; i < n; i++) c[i] = a[p[i]] + r;
    
    dfs(x - 1, 1, c);
}

int main()
{
    int i;
    int a[30];
    
    scanf("%d %d %d", &n, &u, &r);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    for (i = 0; i < n; i++) scanf("%d", &k[i]);
    for (i = 0; i < n; i++) scanf("%d", &p[i]);
    
    for (i = 0; i < n; i++) p[i]--;
    
    dfs(u, -1, a);
    
    printf("%I64d\n", ans);
    
    return 0;
}