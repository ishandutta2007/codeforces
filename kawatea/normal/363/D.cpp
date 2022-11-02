#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, a, l, r, mid, ans = 0, i;
    vector <int> v, w;
    
    scanf("%d %d %d", &n, &m, &a);

    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        w.push_back(x);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    l = -1, r = min(n, m), mid = (l + r) / 2;
    
    while (r - l > 1) {
        long long sum = 0;
        
        for (i = 0; i <= mid; i++) sum += max(0, w[mid - i] - v[i]);
        
        if (sum <= a) {
            l = mid;
            mid = (l + r) / 2;
        } else {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    
    for (i = 0; i <= l; i++) {
        a -= max(0, w[l - i] - v[i]);
        
        ans += min(v[i], w[l - i]);
    }
    
    ans -= a;
    
    ans = max(ans, 0);
    
    printf("%d %d\n", l + 1, ans);
    
    return 0;
}