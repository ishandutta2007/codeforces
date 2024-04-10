#include <cstdio>
#include <algorithm>

using namespace std;

int a[3002];
int b[3002];

int main()
{
    int n, v, ans = 0, i;
    
    scanf("%d %d", &n, &v);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        a[x - 1] += y;
    }
    
    for (i = 0; i <= 3000; i++) {
        if (a[i] <= v) {
            ans += a[i];
        } else {
            ans += v;
            a[i] -= v;
            b[i] = max(b[i] - v, 0);
            a[i + 1] += a[i] - b[i];
            b[i + 1] = a[i] - b[i];
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}