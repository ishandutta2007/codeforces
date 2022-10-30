#include <cstdio>

using namespace std;

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        long long l, r, ans = 0;
        
        scanf("%I64d %I64d", &l, &r);
        
        for (j = 60; j >= 0; j--) {
            if ((l >> j) & 1) {
                ans |= (1LL << j);
                
                l ^= (1LL << j);
                r ^= (1LL << j);
            } else if ((r >> j) & 1) {
                if (r == (1LL << (j + 1)) - 1) {
                    ans |= r;
                } else {
                    ans |= (1LL << j) - 1;
                }
                
                break;
            }
        }
        
        printf("%I64d\n", ans);
    }
    
    return 0;
}