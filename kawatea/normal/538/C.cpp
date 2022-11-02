#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000][2];

int main()
{
    int n, m, ans = 0, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    ans = max(ans, a[0][0] + a[0][1] - 1);
    ans = max(ans, n - a[m - 1][0] + a[m - 1][1]);
    
    for (i = 0; i < m - 1; i++) {
        int x = a[i + 1][0] - a[i][0];
        int y1 = a[i][1];
        int y2 = a[i + 1][1];
        
        if (y1 > y2) swap(y1, y2);
        
        if (x < y2 - y1) {
            puts("IMPOSSIBLE");
            
            return 0;
        }
        
        x -= y2 - y1;
        ans = max(ans, y2 + x / 2);
    }
    
    printf("%d\n", ans);
    
    return 0;
}