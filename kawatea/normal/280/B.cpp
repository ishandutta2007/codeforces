#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int n;
int a[100000];
int d[(1 << 18) - 1];
map <int, int> mp;

int query(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return 0;
    
    if (a <= l && r <= b) {
        return d[k];
    } else {
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        
        return max(vl, vr);
    }
}

int dfs(int x, int y)
{
    int p, q, ans = 0;
    
    if (x + 1 == y) return 0;
    
    p = query(x + 1, y, 0, 0, 1 << 17);
    q = mp[p];
    
    if (x >= 0) ans = max(ans, p ^ a[x]);
    if (y < n) ans = max(ans, p ^ a[y]);
    
    ans = max(ans, dfs(x, q));
    ans = max(ans, dfs(q, y));
    
    return ans;
}

int main()
{
    int i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) d[i + (1 << 17) - 1] = a[i];
    
    for (i = (1 << 17) - 2; i >= 0; i--) d[i] = max(d[i * 2 + 1], d[i * 2 + 2]);
    
    for (i = 0; i < n; i++) mp[a[i]] = i;
    
    printf("%d\n", dfs(-1, n));
    
    return 0;
}