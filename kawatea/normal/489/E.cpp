#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000][2];
int p[1000];
double dp[1000];

int main()
{
    int n, l, x, i, j, k;
    double l1, r1, m;
    vector <int> v;
    
    scanf("%d %d", &n, &l);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    l1 = 0, r1 = 1e6, m = (l1 + r1) / 2;
    
    for (i = 0; i < 50; i++) {
        for (j = 0; j < n; j++) {
            dp[j] = m * a[j][1] - sqrt(abs(a[j][0] - l));
            
            for (k = 0; k < j; k++) {
                dp[j] = max(dp[j], dp[k] + m * a[j][1] - sqrt(abs(a[j][0] - a[k][0] - l)));
            }
        }
        
        if (dp[n - 1] >= 0) {
            r1 = m;
            m = (l1 + r1) / 2;
        } else {
            l1 = m;
            m = (l1 + r1) / 2;
        }
    }
    
    for (i = 0; i < n; i++) {
        dp[i] = r1 * a[i][1] - sqrt(abs(a[i][0] - l));
        p[i] = -1;
        
        for (j = 0; j < i; j++) {
            double x = dp[j] + r1 * a[i][1] - sqrt(abs(a[i][0] - a[j][0] - l));
            
            if (x > dp[i]) {
                dp[i] = x;
                p[i] = j;
            }
        }
    }
    
    x = n - 1;
    
    while (x >= 0) {
        v.push_back(x + 1);
        
        x = p[x];
    }
    
    reverse(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", v[i]);
    }
    
    puts("");
    
    return 0;
}