#include <cstdio>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map <int, int> mp[2];
set <int> s;

int main()
{
    int n, ans = 1e9, i;
    set <int>::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        s.insert(x);
        s.insert(y);
        
        mp[0][x]++;
        
        if (x != y) mp[1][y]++;
    }
    
    for (it = s.begin(); it != s.end(); it++) {
        if ((mp[0][*it] + mp[1][*it]) * 2 < n) continue;
        
        ans = min(ans, max(0, (n + 1) / 2 - mp[0][*it]));
    }
    
    if (ans == 1e9) ans = -1;
    
    printf("%d\n", ans);
    
    return 0;
}