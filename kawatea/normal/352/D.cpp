#include <cstdio>

using namespace std;

int main()
{
    int n, c = 0, i, j;
    int a[3000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (a[i] < a[j]) c++;
        }
    }
    
    if (c % 2 == 1) {
        printf("%d\n", c * 2 - 1);
    } else {
        printf("%d\n", c * 2);
    }
    
    return 0;
}