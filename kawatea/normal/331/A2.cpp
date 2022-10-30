#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[300000];
long long sum[300001];

int main()
{
    int n, p, q, i;
    long long ans = -1e18;
    vector <int> v;
    map <int, int> mp;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        sum[i + 1] = sum[i];
        
        if (a[i] >= 0) sum[i + 1] += a[i];
    }
    
    for (i = 0; i < n; i++) {
        if (mp.count(a[i])) {
            int x = mp[a[i]];
            
            if (sum[i] - sum[x + 1] + a[i] * 2 > ans) {
                ans = sum[i] - sum[x + 1] + a[i] * 2;
                p = x;
                q = i;
            }
        } else {
            mp[a[i]] = i;
        }
    }
    
    for (i = 0; i < p; i++) v.push_back(i + 1);
    for (i = p + 1; i < q; i++) {
        if (a[i] < 0) v.push_back(i + 1);
    }
    for (i = q + 1; i < n; i++) v.push_back(i + 1);
    
    printf("%I64d %d\n", ans, v.size());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", v[i]);
    }
    
    puts("");
    
    return 0;
}