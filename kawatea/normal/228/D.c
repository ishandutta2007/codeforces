#include <stdio.h>

long long bit[10][10][100001];

long long sum(long long *b, int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += b[i];
        i -= i & -i;
    }
    
    return s;
}

void add(long long *b, int i, long long x)
{
    while (i <= 100000) {
        b[i] += x;
        i += i & -i;
    }
}

int main()
{
    int n, m, i, j;
    int a[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        for (j = 0; j < 10; j++) {
            add(bit[j][i % (j + 1)], i + 1, a[i]);
        }
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int t;
        
        scanf("%d", &t);
        
        if (t == 1) {
            int p, v;
            
            scanf("%d %d", &p, &v);
            
            for (j = 0; j < 10; j++) {
                add(bit[j][(p - 1) % (j + 1)], p, v - a[p - 1]);
            }
            
            a[p - 1] = v;
        } else {
            int l, r, z;
            long long ans = 0;
            
            scanf("%d %d %d", &l, &r, &z);
            
            for (j = 1; j <= 2 * (z - 1); j++) {
                int c;
                
                if (j % (2 * (z - 1)) == 0) {
                    c = 2;
                } else if (j % (2 * (z - 1)) <= z) {
                    c = j % (2 * (z - 1));
                } else {
                    c = 2 * z - j % (2 * (z - 1));
                }
                
                ans += (sum(bit[2 * (z - 1) - 1][(l + j - 2) % (2 * (z - 1))], r) - sum(bit[2 * (z - 1) - 1][(l + j - 2) % (2 * (z - 1))], l - 1)) * c;
            }
            
            printf("%I64d\n", ans);
        }
    }
    
    return 0;
}