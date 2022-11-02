#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100];
int b[301];
int dp[301];
int dp2[301];

int main()
{
    int n, t, ans = 0, i, j;
    
    scanf("%d %d", &n, &t);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    if (t < 600) {
        vector <int> v;
        
        for (i = 0; i < t; i++) {
            for (j = 0; j < n; j++) {
                v.push_back(a[j]);
            }
        }
        
        for (i = 0; i < v.size(); i++) {
            for (j = 300; j > 0; j--) {
                if (v[i] >= j) dp[v[i]] = max(dp[v[i]], dp[j] + 1);
            }
        }
        
        for (i = 0; i <= 300; i++) ans = max(ans, dp[i]);
    } else {
        vector <int> v, w;
        
        for (i = 0; i < 300; i++) {
            for (j = 0; j < n; j++) {
                v.push_back(a[j]);
                w.push_back(a[j]);
            }
        }
        
        reverse(w.begin(), w.end());
        
        for (i = 0; i < v.size(); i++) {
            for (j = 300; j > 0; j--) {
                if (v[i] >= j) dp[v[i]] = max(dp[v[i]], dp[j] + 1);
            }
        }
        
        for (i = 0; i < w.size(); i++) {
            for (j = 0; j <= 300; j++) {
                if (w[i] <= j) dp2[w[i]] = max(dp2[w[i]], dp2[j] + 1);
            }
        }
        
        for (i = 0; i < n; i++) b[a[i]]++;
        
        for (i = 0; i <= 300; i++) ans = max(ans, dp[i] + b[i] * (t - 600) + dp2[i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}