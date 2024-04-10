#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, l, r, m, i;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    l = 0, r = n, m = (l + r) / 2;
    
    while (r - l > 1) {
        for (i = 0; i < n; i++) {
            if (i / m > v[i]) break;
        }
        
        if (i < n) {
            l = m;
            m = (l + r) / 2;
        } else {
            r = m;
            m = (l + r) / 2;
        }
    }
    
    printf("%d\n", r);
    
    return 0;
}