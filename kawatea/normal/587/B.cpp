#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[1000000];
long long sum[1000001];
long long sum2[1000001];

int main()
{
    int n, k, m = 1000000007, i, j;
    long long l, ans;
    map <int, int> mp;
    map <int, int>::iterator it;
    
    scanf("%d %I64d %d", &n, &l, &k);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        mp[a[i]] = 1;
    }
    
    for (it = mp.begin(), i = 0; it != mp.end(); it++, i++) it->second = i;
    
    for (i = 0; i < n; i++) a[i] = mp[a[i]];
    
    for (i = 0; i < n; i++) sum[a[i] + 1]++;
    
    for (i = 1; i <= n; i++) sum[i] += sum[i - 1];
    
    ans = l % m;
    
    for (i = 2; i <= k && i <= (l + n - 1) / n; i++) {
        for (j = 0; j < n; j++) sum2[a[j] + 1] += sum[a[j] + 1];
        
        for (j = 1; j <= n; j++) sum2[j] += sum2[j - 1];
        
        for (j = 0; j < n; j++) {
            long long x = l / n;
            
            if (l % n > j) x++;
            
            x = (x - i + 1) % m;
            
            ans += sum[a[j] + 1] * x % m;
            if (ans >= m) ans -= m;
        }
        
        for (j = 0; j <= n; j++) {
            sum[j] = sum2[j] % m;
            sum2[j] = 0;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}