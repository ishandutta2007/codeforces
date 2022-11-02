#include <cstdio>

using namespace std;

int main()
{
    int n, ans = 0, x = -1, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int y;
        
        scanf("%d", &y);
        
        if (y == 1) {
            ans++;
            
            if (x != -1 && x != i - 1) ans++;
            
            x = i;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}