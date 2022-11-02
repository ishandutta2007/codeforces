#include <cstdio>

double bit[1001];
double dp[1001];

double sum(int i)
{
    double s = 0;
    
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    
    return s;
}

void add(int i, double v)
{
    while (i <= 1000) {
        bit[i] += v;
        i += i & -i;
    }
}

int main()
{
    int n, m, i, j;
    double ans = 0;
    int a[1000];
    int b[1000];
    int c[1000][2];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {        
        scanf("%d", &a[i]);
        
        a[i]--;
        
        b[a[i]] = i;
    }
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &c[i][0], &c[i][1]);
        
        c[i][0]--;
        c[i][1]--;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) dp[j] = 0;
        
        dp[b[i]] = 1;
        
        for (j = 0; j < m; j++) {
            double x = dp[c[j][0]] + dp[c[j][1]];
            
            dp[c[j][0]] = dp[c[j][1]] = x / 2;
        }
        
        for (j = 0; j < n; j++) {
            double x = sum(j + 1) - sum(j);
            
            ans += dp[j] * (i - sum(j + 1));
            ans += dp[j] * x / 2;
        }
        
        for (j = 0; j < n; j++) add(j + 1, dp[j]);
    }
    
    printf("%.12lf\n", ans);
    
    return 0;
}