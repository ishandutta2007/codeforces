#include <cstdio>

using namespace std;

int a[2000000];

int main()
{
    int n, ans = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x]++;
    }
    
    for (i = 0; i < 2000000; i++) {
        if (a[i] == 0) continue;
        
        a[i + 1] += a[i] / 2;
        ans += a[i] % 2;
    }
    
    printf("%d\n", ans);
    
    return 0;
}