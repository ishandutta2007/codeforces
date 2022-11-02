#include <cstdio>

using namespace std;

int main()
{
    int n, m, ans = 0, c = 0, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if ((x + m - 1) / m >= c) {
            ans = i + 1;
            c = (x + m - 1) / m;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}