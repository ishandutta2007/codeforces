#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
    int n, x = 0, ans = 2, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    if (n == 1) {
        puts("1");
        
        return 0;
    }
    
    for (i = 2; i < n; i++) {
        if (a[i - 1] + a[i - 2] == a[i]) {
            x++;
        } else {
            ans = max(ans, x + 2);
            x = 0;
        }
    }
    
    ans = max(ans, x + 2);
    
    printf("%d\n", ans);
    
    return 0;
}