#include <cstdio>

using namespace std;

int a[100000];
long long bit[17][100001];

long long sum(int x, int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += bit[x][i];
        i -= i & -i;
    }
    
    return s;
}

void add(int x, int i, long long v)
{
    while (i <= 100000) {
        bit[x][i] += v;
        i += i & -i;
    }
}

int main()
{
    int n, m, i, j, k;
    long long ans = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[i] = x;
        
        for (j = 0; x > 0; j++, x >>= 1) {
            if (x & 1) add(j, i + 1, 1);
        }
    }
    
    for (i = 0; i < 17; i++) {
        for (j = 0; j < n; j++) {
            for (k = j; k < n; k++) {
                if (((a[k] >> i) & 1) == 0) break;
            }
            
            ans += (long long)(k - j) * (k - j + 1) / 2 * (1 << i);
            
            j = k;
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d", &x, &y);
        
        x--;
        
        z = a[x];
        a[x] = y;
        
        for (j = 0; j < 17; j++, y >>= 1, z >>= 1) {
            int l1, r1, m1, l2, r2, m2, p;
            
            if ((y & 1) == (z & 1)) continue;
            
            if (y & 1) add(j, x + 1, 1);
            
            p = sum(j, x + 1);
            
            l1 = -1, r1 = x, m1 = (l1 + r1) / 2;
            
            while (r1 - l1 > 1) {
                if (p - sum(j, m1) == x - m1 + 1) {
                    r1 = m1;
                    m1 = (l1 + r1) / 2;
                } else {
                    l1 = m1;
                    m1 = (l1 + r1) / 2;
                }
            }
            
            l2 = x, r2 = n, m2 = (l2 + r2) / 2;
            
            while (r2 - l2 > 1) {
                if (sum(j, m2 + 1) - p == m2 - x) {
                    l2 = m2;
                    m2 = (l2 + r2) / 2;
                } else {
                    r2 = m2;
                    m2 = (l2 + r2) / 2;
                }
            }
            
            if (y & 1) {
                ans -= (long long)(x - r1) * (x - r1 + 1) / 2 * (1 << j);
                ans -= (long long)(l2 - x) * (l2 - x + 1) / 2 * (1 << j);
                ans += (long long)(l2 - r1 + 1) * (l2 - r1 + 2) / 2 * (1 << j);
            } else {
                ans += (long long)(x - r1) * (x - r1 + 1) / 2 * (1 << j);
                ans += (long long)(l2 - x) * (l2 - x + 1) / 2 * (1 << j);
                ans -= (long long)(l2 - r1 + 1) * (l2 - r1 + 2) / 2 * (1 << j);
                
                add(j, x + 1, -1);
            }
        }
        
        printf("%I64d\n", ans);
    }
    
    return 0;
}