#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];
long long sum[100001];

int main()
{
    int n, l, r, ql, qr, i;
    long long ans = 1e18;
    
    scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
    
    for (i = 0; i <= n; i++) {
        long long tmp = 0;
        
        tmp += sum[i] * l;
        tmp += (sum[n] - sum[i]) * r;
        
        if (i > n - i) {
            tmp += (i * 2 - n - 1) * ql;
        } else if (i < n - i) {
            tmp += (n - i * 2 - 1) * qr;
        }
        
        ans = min(ans, tmp);
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}