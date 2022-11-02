#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int c, d, n, m, k, ans = 1e9, i;
    
    scanf("%d %d", &c, &d);
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    
    for (i = 0; i <= m; i++) {
        int x = max(n * (m - i) - k, 0);
        
        ans = min(ans, i * c + x * d);
    }
    
    printf("%d\n", ans);
    
    return 0;
}