#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];

int main()
{
    int n, ans = 0, x = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) b[i] = 1e9;
    
    for (i = 0; i < n; i++) {
        x = min(x + 1, a[i]);
        
        b[i] = min(b[i], x);
    }
    
    x = 0;
    
    for (i = n - 1; i >= 0; i--) {
        x = min(x + 1, a[i]);
        
        b[i] = min(b[i], x);
    }
    
    for (i = 0; i < n; i++) ans = max(ans, b[i]);
    
    printf("%d\n", ans);
    
    return 0;
}