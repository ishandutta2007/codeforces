#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, d, m, ans = 0, i;
    vector <int> v;
    
    scanf("%d %d", &n, &d);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    scanf("%d", &m);
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n && i < m; i++) ans += v[i];
    
    if (m > n) ans -= (m - n) * d;
    
    printf("%d\n", ans);
    
    return 0;
}