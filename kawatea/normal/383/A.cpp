#include <cstdio>
#include <algorithm>

using namespace std;

int a[200000];
int b[200001];
int c[200001];
long long d[200001];
long long e[200001];

int main()
{
    int n, i;
    long long ans = 1e18;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            b[i + 1]++;
        } else {
            d[i + 1] += b[i];
        }
        
        b[i + 1] += b[i];
        d[i + 1] += d[i];
    }
    
    for (i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            c[i]++;
        } else {
            e[i] += c[i + 1];
        }
        
        c[i] += c[i + 1];
        e[i] += e[i + 1];
    }
    
    for (i = 0; i <= n; i++) ans = min(ans, (long long)b[i] * c[i] + d[i] + e[i]);
    
    printf("%I64d\n", ans);
    
    return 0;
}