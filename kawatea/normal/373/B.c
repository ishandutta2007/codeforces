#include <stdio.h>

int s(long long x)
{
    int ans = 0;
    
    while (x) {
        x /= 10;
        ans++;
    }
    
    return ans;
}

long long f(long long x)
{
    long long y = 9, z = 0, ans = 0, i;
    
    for (i = 1; ; i++) {
        if (x <= y) {
            ans += (x - z) * i;
            
            break;
        }
        
        ans += (y - z) * i;
        
        z = y;
        y = y * 10 + 9;
    }
    
    return ans;
}

int main()
{
    long long w, m, k, l, r, mid;
    
    scanf("%I64d %I64d %I64d", &w, &m, &k);
    
    if (s(m) * k > w) {
        puts("0");
        
        return 0;
    }
    
    l = 0, r = w / k + 1, mid = (l + r) / 2;
    
    while (r - l > 1) {
        long long x = f(m + mid) - f(m - 1);
        
        if (x * k > w) {
            r = mid;
            mid = (l + r) / 2;
        } else {
            l = mid;
            mid = (l + r) / 2;
        }
    }
    
    printf("%I64d\n", l + 1);
    
    return 0;
}