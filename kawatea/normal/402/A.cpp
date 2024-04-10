#include <cstdio>

using namespace std;

int main()
{
    int k, a, b, v, i;
    
    scanf("%d %d %d %d", &k, &a, &b, &v);
    
    a = (a + v - 1) / v;
    
    for (i = 0; ; i++) {
        if (b >= k - 1) {
            if (a <= k) break;
            
            a -= k;
            b -= k - 1;
        } else {
            if (a <= b + 1) break;
            
            a -= b + 1;
            b = 0;
        }
    }
    
    printf("%d\n", i + 1);
    
    return 0;
}