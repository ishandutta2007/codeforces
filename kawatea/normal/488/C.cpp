#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int hy, ay, dy, hm, am, dm, h, a, d, ans = 1e9, i, j;
    
    scanf("%d %d %d", &hy, &ay, &dy);
    scanf("%d %d %d", &hm, &am, &dm);
    scanf("%d %d %d", &h, &a, &d);
    
    for (i = 0; i <= 200; i++) {
        for (j = 0; j <= 100; j++) {
            int x = max(0, ay + i - dm);
            int y = max(0, am - dy - j);
            int z, t;
            
            if (x == 0) continue;
            
            t = (hm + x - 1) / x;
            
            z = max(0, y * t + 1 - hy);
            
            ans = min(ans, i * a + j * d + z * h);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}