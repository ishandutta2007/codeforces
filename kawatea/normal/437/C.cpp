#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];

int main()
{
    int n, m, ans = 0, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        ans += min(a[x - 1], a[y - 1]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}