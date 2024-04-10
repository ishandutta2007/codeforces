#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int c1, c2, c3, c4, n, m, sum1 = 0, sum2 = 0, ans, i;
    int a[1000];
    int b[1000];
    
    scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);
    
    ans = c4;
    
    for (i = 0; i < n; i++) sum1 += min(a[i] * c1, c2);
    for (i = 0; i < m; i++) sum2 += min(b[i] * c1, c2);
    
    sum1 = min(sum1, c3);
    sum2 = min(sum2, c3);
    
    ans = min(ans, sum1 + sum2);
    
    printf("%d\n", ans);
    
    return 0;
}