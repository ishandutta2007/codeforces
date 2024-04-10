#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 1, i, j;
    int a[100];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 2; i <= 100; i++) {
        for (j = 0; j < n; j++) {
            if (a[j] % i != 0) break;
        }
        
        if (j == n) ans = i;
    }
    
    printf("%d\n", ans * n);
    
    return 0;
}