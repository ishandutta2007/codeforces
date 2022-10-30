#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 0, i, j;
    int a[2000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int c1 = 0, c2 = 0;
        
        for (j = 0; j < i; j++) {
            if (abs(a[j]) < abs(a[i])) c1++;
        }
        
        for (j = i + 1; j < n; j++) {
            if (abs(a[j]) < abs(a[i])) c2++;
        }
        
        ans += min(c1, c2);
    }
    
    printf("%d\n", ans);
    
    return 0;
}