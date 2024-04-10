#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 0, i;
    vector <pair<int, long long> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v.push_back(make_pair(x, y));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        int x = 0;
        long long y = 1;
        
        while (1) {
            x++;
            y *= 4;
            
            if (y >= v[i].second) break;
        }
        
        ans = max(ans, v[i].first + x);
    }
    
    printf("%d\n", ans);
    
    return 0;
}