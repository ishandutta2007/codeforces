#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
    int n, ans, c = 1e9, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 1; i < n; i++) c = min(c, abs(a[i]));
    
    ans = c * c + 1;
    
    for (i = 1; i < n; i++) {
        int sum = 0;
        
        for (j = i; j < n && j <= i + c; j++) {
            sum += a[j];
            
            if (abs(sum) < c) ans = min(ans, sum * sum + (j - i + 1) * (j - i + 1));
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}