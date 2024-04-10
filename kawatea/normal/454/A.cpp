#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (abs(i - n / 2) + abs(j - n / 2) <= n / 2) {
                putchar('D');
            } else {
                putchar('*');
            }
        }
        
        puts("");
    }
    
    return 0;
}