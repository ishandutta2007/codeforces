#include <cstdio>
#include <algorithm>

using namespace std;

int a[100];

int main()
{
    int n, k, x, ans = 0, i, j, l, r;
    
    scanf("%d %d %d", &n, &k, &x);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n - 1; i++) {
        if (a[i] == x && a[i + 1] == x) {
            int sum = 2;
            
            for (j = i - 1, l = i + 2; j >= 0 && l < n; ) {
                int c1 = 0, c2 = 0;
                
                if (a[j] != a[l]) break;
                
                for (r = j; r >= 0; r--) {
                    if (a[r] != a[j]) break;
                    
                    c1++;
                }
                
                for (r = l; r < n; r++) {
                    if (a[r] != a[l]) break;
                    
                    c2++;
                }
                
                if (c1 + c2 < 3) break;
                
                sum += c1 + c2;
                j -= c1;
                l += c2;
            }
            
            ans = max(ans, sum);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}