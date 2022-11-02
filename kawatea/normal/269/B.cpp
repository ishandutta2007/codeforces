#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dp[5001][5001];

int main()
{
    int n, m, i, j;
    int a[5000];
    vector <int> v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d %*lf", &x);
        
        a[i] = x;
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i] == v[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    
    printf("%d\n", n - dp[n][n]);
    
    return 0;
}