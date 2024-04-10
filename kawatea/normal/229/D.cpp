#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int> > v;
int dp[5001];
int sum[5001];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        sum[i + 1] = sum[i] + x;
    }
    
    for (i = 0; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            v.push_back(make_pair(sum[j] - sum[i], i * 10000 + j));
        }
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        int x = v[i].second / 10000;
        int y = v[i].second % 10000;
        
        if (x > 0 && dp[x] == 0) continue;
        
        if (dp[y] >= dp[x] + 1) continue;
        
        dp[y] = dp[x] + 1;
    }
    
    printf("%d\n", n - dp[n]);
    
    return 0;
}