#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000][2];
int b[5000];

int main()
{
    int n, m, k, p, i;
    long long l, r, mid;
    
    scanf("%d %d %d %d", &n, &m, &k, &p);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    l = 0, r = 6e13, mid = (l + r) / 2;
    
    while (r - l > 1) {
        int sum = 0, c = 0, f = 0;
        
        for (i = 0; i < m; i++) b[i] = 0;
        
        for (i = 0; i < n && f == 0; i++) {
            long long x = a[i][0] + (long long)a[i][1] * m;
            long long y, z, h = a[i][0], d = 0;
            
            if (x <= mid) continue;
            
            y = (x - mid) / p;
            z = (x - mid) % p;
            
            sum += y;
            if (z > 0) sum++;
            
            if (sum > m * k) {
                f = 1;
                
                break;
            }
            
            if (z > 0) {
                if (h >= z) {
                    b[0]++;
                    h = max(0LL, h - p);
                } else {
                    long long c = (z - h + a[i][1] - 1) / a[i][1];
                    
                    if (c >= m) {
                        f = 1;
                        
                        break;
                    } else {
                        b[c]++;
                        d = c;
                        h += c * a[i][1];
                        h = max(0LL, h - p);
                    }
                }
            }
            
            while (y) {
                long long c;
                
                if (d >= m) {
                    f = 1;
                    
                    break;
                }
                
                if (h >= p) {
                    long long t = min(h / p, y);
                    
                    b[d] += t;
                    h -= p * t;
                    y -= t;
                }
                
                c = (p - h + a[i][1] - 1) / a[i][1];
                d += c;
                h += c * a[i][1];
            }
        }
        
        for (i = m - 1; i >= 0; i--) {
            c += b[i];
            
            if (c > (m - i) * k) {
                f = 1;
                
                break;
            }
        }
        
        if (f == 0) {
            r = mid;
            mid = (l + r) / 2;
        } else {
            l = mid;
            mid = (l + r) / 2;
        }
    }
    
    printf("%I64d\n", r);
    
    return 0;
}