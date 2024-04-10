#include <cstdio>

using namespace std;

int a[100];

int main()
{
    int n, ans = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            ans += n - i;
            
            break;
        }
    }
    
    for (i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            ans -= n - i - 1;
            n = i + 1;
            
            break;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 1) break;
    }
    
    for (; i < n; i++) {
        if (a[i] == 1) continue;
        
        for (j = i; j < n; j++) {
            if (a[j] == 1) break;
        }
        
        if (j - i >= 2) ans -= j - i;
        
        i = j;
    }
    
    printf("%d\n", ans);
    
    return 0;
}