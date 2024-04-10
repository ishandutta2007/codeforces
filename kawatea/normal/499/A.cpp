#include <cstdio>

using namespace std;

int main()
{
    int n, x, p = 1, ans = 0, i;
    
    scanf("%d %d", &n, &x);
    
    for (i = 0; i < n; i++) {
        int l, r;
        
        scanf("%d %d", &l, &r);
        
        ans += (l - p) % x;
        ans += r - l + 1;
        
        p = r + 1;
    }
    
    printf("%d\n", ans);
    
    return 0;
}