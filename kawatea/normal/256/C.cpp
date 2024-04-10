#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int g[10000000];
vector <long long> v;
map <int, int> mp;

int main()
{
    int n, ans = 0, i, j;
    long long p = 1, q = 2;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        long long x;
        
        scanf("%I64d", &x);
        
        v.push_back(x);
    }
    
    g[1] = 0;
    
    mp[0]++;
    
    for (i = 2; i < 10000000; i++) {
        while (q * q <= i) {
            mp[g[q]]++;
            
            q++;
        }
        
        while (p * p * p * p < i) {
            mp[g[p]]--;
            
            if (mp[g[p]] == 0) mp.erase(g[p]);
            
            p++;
        }
        
        for (j = 0; ; j++) {
            if (!mp.count(j)) break;
        }
        
        g[i] = j;
    }
    
    sort(v.begin(), v.end());
    
    mp.clear();
    
    p = 1;
    
    while (p * p * p * p <= v[0]) p++;
    
    q = p;
    
    for (i = 0; i < v.size(); i++) {
        while (q * q <= v[i]) {
            mp[g[q]]++;
            
            q++;
        }
        
        while (p * p * p * p < v[i]) {
            mp[g[p]]--;
            
            if (mp[g[p]] == 0) mp.erase(g[p]);
            
            p++;
        }
        
        for (j = 0; ; j++) {
            if (!mp.count(j)) break;
        }
        
        ans ^= j;
    }
    
    if (ans == 0) {
        puts("Rublo");
    } else {
        puts("Furlo");
    }
    
    return 0;
}