#include <cstdio>
#include <algorithm>

using namespace std;

int a[5];
int b[5];

int main()
{
    int h1, h2, ans = 0, i;
    
    for (i = 0; i < 5; i++) scanf("%d", &a[i]);
    for (i = 0; i < 5; i++) scanf("%d", &b[i]);
    
    scanf("%d %d", &h1, &h2);
    
    for (i = 0; i < 5; i++) {
        int x = (i + 1) * 500;
        
        ans += max(x * 3 / 10, x - x * a[i] / 250 - b[i] * 50);
    }
    
    ans += h1 * 100;
    ans -= h2 * 50;
    
    printf("%d\n", ans);
    
    return 0;
}