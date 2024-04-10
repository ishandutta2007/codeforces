#include <cstdio>

using namespace std;

int a[6];

int main()
{
    int n, m = 1000000007, ans, i;
    
    scanf("%d %d", &a[0], &a[1]);
    scanf("%d", &n);
    
    n--;
    n %= 6;
    
    for (i = 2; i < 6; i++) a[i] = a[i - 1] - a[i - 2];
    
    ans = a[n];
    
    while (ans < 0) ans += m;
    
    printf("%d\n", ans % m);
    
    return 0;
}