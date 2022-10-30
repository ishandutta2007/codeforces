#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, t, ans = 0, i;
    vector <long long> v;
    vector <long long>::iterator it;
    
    scanf("%d %d", &n, &t);
    
    v.push_back(0);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(v.back() + x);
    }
    
    for (it = v.begin(); it != v.end(); it++) {
        int x = upper_bound(it, v.end(), t + *it) - it - 1;
        
        ans = max(ans, x);
    }
    
    printf("%d\n", ans);
    
    return 0;
}