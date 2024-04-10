#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m, k, ans = 0;
    
    scanf("%I64d %I64d %I64d", &n, &m, &k);
    
    if (k > n + m - 2) {
        puts("-1");
        
        return 0;
    }
    
    if (n >= k + 1) {
        ans = max(ans, n / (k + 1) * m);
    } else {
        ans = max(ans, m / (k - n + 2));
    }
    
    if (m >= k + 1) {
        ans = max(ans, m / (k + 1) * n);
    } else {
        ans = max(ans, n / (k - m + 2));
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}