#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int ans = 1e9, i;
    int a[5];
    int b[5] = {1, 1, 2, 7, 4};
    
    for (i = 0; i < 5; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < 5; i++) ans = min(ans, a[i] / b[i]);
    
    printf("%d\n", ans);
    
    return 0;
}