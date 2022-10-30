#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int n, m, k, c = 0, i;
    map <int, int> mp;
    map <int, int>::iterator it;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        mp[-x]++;
    }
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        mp[-x]--;
    }
    
    for (it = mp.begin(); it != mp.end(); it++) {
        c += it->second;
        
        if (c > 0) {
            puts("YES");
            
            return 0;
        }
    }
    
    puts("NO");
    
    return 0;
}