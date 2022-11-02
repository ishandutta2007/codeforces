#include <cstdio>

using namespace std;

int dp[500001];

int main()
{
    int n, d, x = 0, i, j;
    int a[50];
    
    scanf("%d %d", &n, &d);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    dp[0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = 500000; j >= 0; j--) {
            if (dp[j] == 1) dp[j + a[i]] = 1;
        }
    }
    
    for (i = 0; ; i++) {
        int y = 0;
        
        for (j = x + 1; j <= x + d && j <= 500000; j++) {
            if (dp[j] == 1) y = j;
        }
        
        if (y > x) {
            x = y;
        } else {
            printf("%d %d\n", x, i);
            
            return 0;
        }
    }
    
    return 0;
}