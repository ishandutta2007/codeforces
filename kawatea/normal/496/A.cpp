#include <cstdio>
#include <algorithm>

using namespace std;

int a[100];

int main()
{
    int n, ans = 1e9, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 1; i < n - 1; i++) {
        int x = 0;
        
        for (j = 0; j < n - 1; j++) x = max(x, a[j + 1] - a[j]);
        
        x = max(x, a[i + 1] - a[i - 1]);
        
        ans = min(ans, x);
    }
    
    printf("%d\n", ans);
    
    return 0;
}