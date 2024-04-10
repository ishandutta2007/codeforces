#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[10000001];
int b[10000001];
vector <int> v;
map <int, long long> mp;

int main()
{
    int k, i, j;
    long long n = 1;
    map <int, long long>::iterator it;
    
    scanf("%d", &k);
    
    for (i = 0; i < k; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 2, j = 0; i <= 10000000; i++) {
        while (j < v.size()) {
            if (v[j] >= i) break;
            
            j++;
        }
        
        a[i] = v.size() - j;
    }
    
    for (i = 0; i <= 10000000; i++) b[i] = i;
    
    for (i = 2; i <= 10000000; i += 2) {
        int c = 0;
        
        while (b[i] % 2 == 0) {
            b[i] /= 2;
            c++;
        }
        
        if (a[i] > 0) mp[2] += (long long)c * a[i];
    }
    
    for (i = 3; i <= 10000000; i += 2) {
        if (b[i] == 1) continue;
        
        for (j = i; j <= 10000000; j += i) {
            int c = 0;
            
            while (b[j] % i == 0) {
                b[j] /= i;
                c++;
            }
            
            if (a[j] > 0) mp[i] += (long long)c * a[j];
        }
    }
    
    for (it = mp.begin(); it != mp.end(); it++) {
        long long l = 0, r = 1e18, m = (l + r) / 2;
        map <int, long long>::iterator it2 = it;
        
        it2++;
        
        if (it2 != mp.end() && it2->second == it->second) continue;
        
        while (r - l > 1) {
            long long c = 0;
            long long x = it->first;
            
            while (x <= m) {
                c += m / x;
                x *= it->first;
            }
            
            if (c >= it->second) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m;
                m = (l + r) / 2;
            }
        }
        
        n = max(n, r);
    }
    
    printf("%I64d\n", n);
    
    return 0;
}