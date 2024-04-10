#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i;
    long long ans = 0;
    vector <int> v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v.push_back(y);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 0; i < m; i++) {
        long long x;
        
        if (i % 2 == 0) {
            x = (long long)i * (i + 1) / 2 + 1;
        } else {
            x = (long long)(i + 1) * (i - 1) / 2 + 1;
            x += i;
        }
        
        if (x > n) break;
        
        ans += v[i];
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}