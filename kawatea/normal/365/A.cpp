#include <cstdio>

using namespace std;

int main()
{
    int n, k, ans = 0, i, j;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        int a[10] = {0};
        
        scanf("%d", &x);
        
        while (x) {
            a[x % 10] = 1;
            x /= 10;
        }
        
        for (j = 0; j <= k; j++) {
            if (a[j] == 0) break;
        }
        
        if (j > k) ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}