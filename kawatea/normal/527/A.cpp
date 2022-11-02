#include <cstdio>

using namespace std;

int main()
{
    long long a, b, ans = 0;
    
    scanf("%I64d %I64d", &a, &b);
    
    while (b) {
        long long na, nb;
        
        ans += a / b;
        
        na = b;
        nb = a % b;
        
        a = na;
        b = nb;
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}