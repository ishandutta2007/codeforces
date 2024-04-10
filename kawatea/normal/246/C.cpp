#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int n, k, i, j;
    int a[50];
    map <int, long long> mp;
    map <int, long long>::iterator it;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    mp[0] = 0;
    
    for (i = 0; i < n && k > 0; i++) {
        map <int, long long> mp2;
        
        for (it = mp.begin(); it != mp.end() && k > 0; it++) {
            if (!mp.count(it->first + a[i])) {
                int c = 0;
                
                mp2[it->first + a[i]] = it->second | (1LL << i);
                
                for (j = 0; j < n; j++) {
                    if ((it->second >> j) & 1) c++;
                }
                
                printf("%d", c + 1);
                
                for (j = 0; j < n; j++) {
                    if ((it->second >> j) & 1) printf(" %d", a[j]);
                }
                
                printf(" %d\n", a[i]);
                
                k--;
            }
        }
        
        for (it = mp2.begin(); it != mp2.end(); it++) {
            mp[it->first] = it->second;
        }
    }
    
    return 0;
}