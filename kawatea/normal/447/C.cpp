#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];

int main()
{
    int n, ans = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    b[0] = 1;
    
    for (i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            b[i] = b[i - 1] + 1;
        } else {
            b[i] = 1;
        }
    }
    
    for (i = 0; i < n; i++) {
        ans = max(ans, b[i]);
        
        if (i > 0) ans = max(ans, b[i - 1] + 1);
        
        if (b[i] > i) continue;
        
        ans = max(ans, b[i] + 1);
        
        if (b[i] < i && a[i - b[i] - 1] < a[i - b[i] + 1] - 1) ans = max(ans, b[i] + b[i - b[i] - 1] + 1);
        
        if (b[i] > 1 && b[i] < i && a[i - b[i]] < a[i - b[i] + 2] - 1) ans = max(ans, b[i] + b[i - b[i]]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}