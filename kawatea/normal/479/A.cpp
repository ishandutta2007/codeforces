#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int x, y, z, ans = 0, i;
    
    scanf("%d %d %d", &x, &y, &z);
    
    ans = max(ans, x + y + z);
    ans = max(ans, x * y * z);
    ans = max(ans, x + y * z);
    ans = max(ans, x * y + z);
    ans = max(ans, (x + y) * z);
    ans = max(ans, x * (y + z));
    
    printf("%d\n", ans);
    
    return 0;
}