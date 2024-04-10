#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

long long a[100000];
long long b[100000];
map <long long, int> mp;

int main()
{
    int n, i, j;
    long long ans = 0, x = 0;
    map <long long, int>::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
    
    for (i = 0; i < n; i++) {
        x ^= a[n - i - 1];
        
        ans = max(ans, x);
        
        b[n - i - 1] = x;
        
        mp[b[n - i - 1]]++;
    }
    
    x = 0;
    
    for (i = 0; i < n; i++) {
        long long y = 0;
        int c[40] = {0};
        
        x ^= a[i];
        
        ans = max(ans, x);
        
        mp[b[i]]--;
        
        if (mp[b[i]] == 0) mp.erase(b[i]);
        
        a[i] = x;
        
        for (j = 0; j < 40; j++) {
            if (a[i] % 2 == 1) c[j] = 1;
            
            a[i] /= 2;
        }
        
        for (j = 39; j >= 0; j--) {
            long long z = y;
            
            if (c[j] == 0) z |= (1LL << j);
            
            it = mp.lower_bound(z);
            
            if (it == mp.end()) {
                if (c[j] == 1) break;
            } else {
                if ((it->first >> (j + 1)) == (y >> (j + 1))) {
                    if ((it->first >> j) & 1) y |= (1LL << j);
                }
            }
        }
        
        ans = max(ans, x ^ y);
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}