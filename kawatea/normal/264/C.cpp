#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, q, i, j;
    int v[100000], c[100000];
    long long d[100000];
    
    scanf("%d %d", &n, &q);
    
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    for (i = 0; i < n; i++) scanf("%d", &c[i]);
    
    for (i = 0; i < n; i++) c[i]--;
    
    for (i = 0; i < q; i++) {
        long long a, b, m1 = -1e18, m2 = -1e18, ans = 0;
        
        scanf("%I64d %I64d", &a, &b);
        
        for (j = 0; j < n; j++) d[j] = -1e18;
        
        for (j = 0; j < n; j++) {
            long long x, y, z;
            
            if (d[c[j]] == m1) {
                x = m2;
            } else {
                x = m1;
            }
            
            y = d[c[j]];
            
            z = max(y, max(b * v[j], max(y + a * v[j], x + b * v[j])));
            
            if (d[c[j]] == m1) {
                m1 = z;
                d[c[j]] = z;
            } else {
                if (z > m1) {
                    m2 = m1;
                    m1 = z;
                } else if (z > m2) {
                    m2 = z;
                }
                
                d[c[j]] = z;
            }
        }
        
        for (j = 0; j < n; j++) ans = max(ans, d[j]);
        
        printf("%I64d\n", ans);
    }
    
    return 0;
}