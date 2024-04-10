#include <cstdio>

using namespace std;

int a[1000];

int main()
{
    int n, x, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    x = n - a[0];
    
    for (i = 0; i < n; i++) {
        int y;
        
        if (i % 2 == 0) {
            y = (a[i] + x) % n;
        } else {
            y = (a[i] - x + n) % n;
        }
        
        if (y != i) {
            puts("No");
            
            return 0;
        }
    }
    
    puts("Yes");
    
    return 0;
}