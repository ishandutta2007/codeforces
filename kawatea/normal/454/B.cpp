#include <cstdio>

using namespace std;

int a[100000];

int main()
{
    int n, c = -1, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i % n] > a[(i + 1) % n]) {
            if (c == -1) {
                c = i;
            } else {
                puts("-1");
                
                return 0;
            }
        }
    }
    
    if (c == -1) {
        puts("0");
    } else {
        printf("%d\n", n - c - 1);
    }
    
    return 0;
}