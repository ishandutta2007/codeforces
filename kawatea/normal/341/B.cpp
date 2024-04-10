#include <cstdio>
#include <algorithm>

using namespace std;

int a[(1 << 18) - 1];

void update(int k, int x)
{
    k += 1 << 17;
    
    a[k] = x;
    
    while (k > 0) {
        k = (k - 1) / 2;
        
        a[k] = max(a[k * 2 + 1], a[k * 2 + 2]);
    }
}

int query(int p, int q, int k, int l, int r)
{
    if (r <= p || q <= l) return 0;
    
    if (p <= l && r <= q) {
        return a[k];
    } else {
        int vl = query(p, q, k * 2 + 1, l, (l + r) / 2);
        int vr = query(p, q, k * 2 + 2, (l + r) / 2, r);
        
        return max(vl, vr);
    }
}

int main()
{
    int n, ans = 0, i;
    int a[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int x = query(0, a[i] + 1, 0, 0, 1 << 17);
        
        update(a[i], x + 1);
        
        ans = max(ans, x + 1);
    }
    
    printf("%d\n", ans);
    
    return 0;
}