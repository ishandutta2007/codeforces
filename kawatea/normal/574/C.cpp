#include <cstdio>

using namespace std;

int a[100000];

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] != a[0]) {
            puts("No");
            
            return 0;
        }
    }
    
    puts("Yes");
    
    return 0;
}