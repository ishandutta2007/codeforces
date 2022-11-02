#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans, i, j;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    ans = n;
    
    for (i = 0, j = 0; i < n; i++, j++) {
        while (j < n) {
            if (v[j] >= v[i] * 2) break;
            
            j++;
        }
        
        if (j == n) break;
        
        if (j - i > i || 2 * i - j + 1 <= n - j - 1) ans = min(ans, n - i - 1);
    }
    
    printf("%d\n", ans);
    
    return 0;
}