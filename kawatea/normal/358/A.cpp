#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, j;
    int a[1000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n - 1; i++) {
        int x, y, f1 = 0, f2 = 0;
        
        x = min(a[i], a[i + 1]);
        y = max(a[i], a[i + 1]);
        
        for (j = i + 2; j < n; j++) {
            if (a[j] < x || a[j] > y) {
                f1 = 1;
            } else {
                f2 = 1;
            }
        }
        
        if (f1 == 1 && f2 == 1) {
            puts("yes");
            
            return 0;
        }
    }
    
    puts("no");
    
    return 0;
}