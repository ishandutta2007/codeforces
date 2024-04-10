#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int i, j, k;
    long long r, g, b, ans;
    
    scanf("%I64d %I64d %I64d", &r, &g, &b);
    
    if (r < g) swap(r, g);
    if (r < b) swap(r, b);
    if (g < b) swap(g, b);
    
    if (r / 3 <= g / 3 * 2 + b / 3 * 2) {
        ans = r / 3 + g / 3 + b / 3 + (r % 3 + g % 3 + b % 3) / 3;
    } else {
        ans = g / 3 * 3 + b / 3 * 3;
        
        r -= g / 3 * 3 * 2 + b / 3 * 3 * 2;
        g %= 3;
        b %= 3;
        
        while (r >= 2 && g >= 1) {
            r -= 2;
            g--;
            ans++;
        }
        
        while (r >= 2 && b >= 1) {
            r -= 2;
            b--;
            ans++;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}