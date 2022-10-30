#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, s, ans = -1, i;
    
    scanf("%d %d", &n, &s);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        if (x > s || (x == s && y > 0)) continue;
        
        if (y > 0) {
            ans = max(ans, 100 - y);
        } else {
            ans = max(ans, 0);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}