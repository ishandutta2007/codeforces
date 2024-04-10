#include <cstdio>
#include <algorithm>

using namespace std;

long long comb[64][64];

long long f(long long x, int k)
{
    int c;
    long long ans;
    
    if (k == 0) return 1;
    if (x < (1LL << k) - 1) return 0;
    
    c = __builtin_clzll(x);
    
    ans = f(x ^ (1LL << (63 - c)), k - 1);
    
    if (63 - c >= k) ans += comb[63 - c][k];
    
    return ans;
}

int main()
{
    int k, i, j;
    long long m, l, r, mid;
    
    for (i = 0; i < 64; i++) {
        comb[i][0] = comb[i][i] = 1;
        
        for (j = 1; j < i; j++) comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
    
    scanf("%I64d %d", &m, &k);
    
    l = 0, r = 1e18, mid = (l + r) / 2;
    
    while (r - l > 1) {
        if (f(mid * 2, k) - f(mid, k) < m) {
            l = mid;
            mid = (l + r) / 2;
        } else {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    
    printf("%I64d\n", r);
    
    return 0;
}