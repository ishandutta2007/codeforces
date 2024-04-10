#include <cstdio>

using namespace std;

int main()
{
    long long a, b, ans = 0;
    
    scanf("%I64d %I64d", &a, &b);
    
    while (1) {
        if (a == 0 || b == 0) break;
        
        if (a > b) {
            ans += a / b;
            
            a %= b;
        } else {
            ans += b / a;
            
            b %= a;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}