#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int n, i;
    long long ans = 0;
    map <int, int> mpx, mpy;
    map <pair<int, int>, int> mp;
    map <int, int>::iterator it;
    map <pair<int, int>, int>::iterator it2;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        mpx[x]++;
        mpy[y]++;
        mp[make_pair(x, y)]++;
    }
    
    for (it = mpx.begin(); it != mpx.end(); it++) ans += (long long)it->second * (it->second - 1) / 2;
    
    for (it = mpy.begin(); it != mpy.end(); it++) ans += (long long)it->second * (it->second - 1) / 2;
    
    for (it2 = mp.begin(); it2 != mp.end(); it2++) ans -= (long long)it2->second * (it2->second - 1) / 2;
    
    printf("%I64d\n", ans);
    
    return 0;
}