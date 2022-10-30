#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, x1 = 1e9, x2 = -1e9, y1 = 1e9, y2 = -1e9, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = min(y1, y);
        y2 = max(y2, y);
    }
    
    printf("%I64d\n", (long long)max(x2 - x1, y2 - y1) * max(x2 - x1, y2 - y1));
    
    return 0;
}