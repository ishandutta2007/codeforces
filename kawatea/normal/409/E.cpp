#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int i, j;
    double x;
    
    scanf("%lf", &x);
    
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            double y = i * j / sqrt(4 * j * j + i * i);
            
            if (abs(x - y) < 1e-6) {
                printf("%d %d\n", i, j);
                
                return 0;
            }
        }
    }
    
    return 0;
}