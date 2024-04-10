#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < 100000; i++) a[i] = -1;
    
    for (i = 0; i < n; i++) {
        int x, k;
        
        scanf("%d %d", &x, &k);
        
        k--;
        
        if (a[k] < x - 1) {
            puts("NO");
            
            return 0;
        }
        
        a[k] = max(a[k], x);
    }
    
    puts("YES");
    
    return 0;
}