#include <cstdio>

using namespace std;

double pow(double x, int n)
{
    double ans = 1;
    
    while (n) {
        if (n & 1) ans *= x;
        
        x *= x;
        n >>= 1;
    }
    
    return ans;
}

double a[100001];

int main()
{
    int m, n, i;
    double ans = 0;
    
    scanf("%d %d", &m, &n);
    
    for (i = 1; i <= m; i++) a[i] = pow((double)i / m, n);
    
    for (i = 1; i <= m; i++) ans += i * (a[i] - a[i - 1]);
    
    printf("%.12lf\n", ans);
    
    return 0;
}