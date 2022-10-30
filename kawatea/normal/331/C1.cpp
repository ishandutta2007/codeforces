#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000001];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        dp[i] = 1e9;
        
        for (j = i; j > 0; j /= 10) dp[i] = min(dp[i], dp[i - j % 10] + 1);
    }
    
    printf("%d\n", dp[n]);
    
    return 0;
}