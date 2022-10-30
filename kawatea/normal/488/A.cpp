#include <cstdio>

using namespace std;

int f(int x)
{
    if (x < 0) x = -x;
    
    while (x) {
        if (x % 10 == 8) return 1;
        
        x /= 10;
    }
    
    return 0;
}

int main()
{
    int a, i;
    
    scanf("%d", &a);
    
    for (i = 1; ; i++) {
        if (f(a + i)) {
            printf("%d\n", i);
            
            break;
        }
    }
    
    return 0;
}