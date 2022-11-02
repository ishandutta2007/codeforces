#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
    int n, k, ans = 0, i, j;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (n - i >= k * 2) break;
        
        ans = max(ans, a[n - i - 1]);
        k--;
    }
    
    if (i < n) {
        for (j = 0; j < k; j++) {
            ans = max(ans, a[j] + a[k * 2 - j - 1]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}