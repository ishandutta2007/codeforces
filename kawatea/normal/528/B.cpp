#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dp[200001];

int main()
{
    int n, i;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v.push_back(make_pair(x, y));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i <= n; i++) dp[i] = 2e9 + 1;
    
    for (i = 0; i < n; i++) {
        int x = upper_bound(dp, dp + n, v[i].first - v[i].second) - dp;
        
        dp[x] = min(dp[x], v[i].first + v[i].second);
    }
    
    printf("%d\n", lower_bound(dp, dp + n, 2e9 + 1) - dp);
    
    return 0;
}