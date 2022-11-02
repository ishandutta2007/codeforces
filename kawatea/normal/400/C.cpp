#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, x, y, z, p, i, j;
    
    scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);
    
    x %= 4;
    y %= 2;
    z %= 4;
    
    for (i = 0; i < p; i++) {
        int n1 = n, m1 = m, a, b;
        
        scanf("%d %d", &a, &b);
        
        for (j = 0; j < x; j++) {
            int na = b;
            int nb = n1 - a + 1;
            
            a = na;
            b = nb;
            
            swap(n1, m1);
        }
        
        for (j = 0; j < y; j++) {
            b = m1 - b + 1;
        }
        
        for (j = 0; j < z; j++) {
            int na = m1 - b + 1;
            int nb = a;
            
            a = na;
            b = nb;
            
            swap(n1, m1);
        }
        
        printf("%d %d\n", a, b);
    }
    
    return 0;
}