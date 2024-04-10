#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 1e9, c = 0, i, j;
    long long a[8];
    int b[8] = {0};
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
    
    for (i = 0; i < n; i++) {
        long long x = a[i];
        
        for (j = 2; (long long)j * j <= x; j++) {
            if (x % j == 0) {
                while (x % j == 0) {
                    x /= j;
                    b[i]++;
                }
            }
        }
        
        if (x > 1) b[i]++;
        
        if (b[i] == 1) c++;
    }
    
    for (i = 0; i < n; i++) v.push_back(i);
    
    do {
        int sum = 0, p = 0;
        long long c[8];
        long long f[8] = {0};
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (c[j] % a[v[i]] == 0) {
                    c[j] /= a[v[i]];
                    f[i] = 1;
                    
                    break;
                }
            }
            
            c[i] = a[v[i]];
        }
        
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                sum += b[v[i]];
                p++;
            }
        }
        
        if (p >= 2) sum++;
        
        ans = min(ans, sum);
    } while (next_permutation(v.begin(), v.end()));
    
    ans += n - c;
    
    printf("%d\n", ans);
    
    return 0;
}