#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100];
int b[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int c[59];
long long dp[101][1 << 16];
int dp2[101][1 << 16];

int main()
{
    int n, p = 0, i, j, k;
    vector <long long> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 1; i < 59; i++) {
        for (j = 0; j < 16; j++) {
            if (i % b[j] == 0) c[i] |= (1 << j);
        }
    }
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j < (1 << 16); j++) {
            dp[i][j] = 1e18;
        }
    }
    
    dp[0][0] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < (1 << 16); j++) {
            if (dp[i][j] == 1e18) continue;
            
            for (k = 1; k < 59; k++) {
                if ((j & c[k]) == 0) {
                    long long x = dp[i][j] + abs(a[i] - k);
                    
                    if (dp[i + 1][j | c[k]] > x) {
                        dp[i + 1][j | c[k]] = x;
                        dp2[i + 1][j | c[k]] = k;
                    }
                }
            }
        }
    }
    
    for (i = 0; i < (1 << 16); i++) {
        if (dp[n][i] < dp[n][p]) p = i;
    }
    
    for (i = n; i > 0; i--) {
        v.push_back(dp2[i][p]);
        
        p ^= c[dp2[i][p]];
    }
    
    reverse(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%I64d", v[i]);
    }
    
    puts("");
    
    return 0;
}