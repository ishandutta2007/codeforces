#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, ans = 1e9, i;
    vector <int> v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        if (i + n > v.size()) break;
        
        ans = min(ans, v[i + n - 1] - v[i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}