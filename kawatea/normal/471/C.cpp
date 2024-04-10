#include <cstdio>

using namespace std;

int main()
{
    int ans = 0, i;
    long long n;
    
    scanf("%I64d", &n);
    
    for (i = 1; ; i++) {
        long long x = n - i * 2 - (long long)i * (i - 1) / 2 * 3;
        
        if (x < 0) break;
        
        if (x % 3 != 0) continue;
        
        ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}