#include <cstdio>
#include <algorithm>

using namespace std;

double a[20];
double ans[20];
double dp[1 << 20];

int main() {
    int n, k, c = 0, i, j, l;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%lf", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0) c++;
    }
    
    for (i = 0; i < n; i++) dp[1 << i] = a[i];
    
    for (i = 1; i < (1 << n); i++) {
        double sum = 0;
        
        if (dp[i] == 0) continue;
        
        for (j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;
            
            sum += a[j];
        }
        
        if (sum == 0) continue;
        
        for (j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;
            
            dp[i | (1 << j)] += dp[i] * a[j] / sum;
        }
    }
    
    for (i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) == min(k, n - c)) {
            for (j = 0; j < n; j++) {
                if ((i >> j) & 1) ans[j] += dp[i];
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%.12lf", ans[i]);
    }
    puts("");
    
    return 0;
}