#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[1 << 20];

int main()
{
    int n, m, b, i, j;
    long long ans = 2e18;
    vector <pair<int, pair<int, int> > > v;
    
    scanf("%d %d %d", &n, &m, &b);
    
    for (i = 0; i < n; i++) {
        int x, y, z, w = 0;
        
        scanf("%d %d %d", &x, &y, &z);
        
        for (j = 0; j < z; j++) {
            int x;
            
            scanf("%d", &x);
            
            w |= (1 << (x - 1));
        }
        
        v.push_back(make_pair(y, make_pair(x, w)));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < (1 << m); i++) dp[i] = 2e18;
    
    dp[0] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = (1 << m) - 1; j >= 0; j--) {
            dp[j | v[i].second.second] = min(dp[j | v[i].second.second], dp[j] + v[i].second.first);
        }
        
        ans = min(ans, (long long)v[i].first * b + dp[(1 << m) - 1]);
    }
    
    if (ans == 2e18) ans = -1;
    
    printf("%I64d\n", ans);
    
    return 0;
}