#include <cstdio>

using namespace std;

int a[20][100000];
int b[100000];
int c[20];
int e[1 << 20];

int main()
{
    int n, m, d, l, r, mid, i, j;
    
    scanf("%d %d %d", &n, &m, &d);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        for (j = 0; j < x; j++) {
            scanf("%d", &a[i][j]);
            
            a[i][j]--;
            
            b[a[i][j]] = i;
        }
    }
    
    for (i = 0; i < d; i++) c[b[i]]++;
    
    for (; ; i++) {
        int x = 0;
        
        for (j = 0; j < m; j++) {
            if (c[j] > 0) x |= (1 << j);
        }
        
        e[x] = 1;
        
        if (i == n) break;
        
        c[b[i]]++;
        c[b[i - d]]--;
    }
    
    l = 0, r = m, mid = (l + r) / 2;
    
    while (r - l > 1) {
        int comb = (1 << mid) - 1, f = 0;
        
        while (comb < (1 << m)) {
            int x = comb & -comb, y = comb + x, z = ((1 << m) - 1) & ~comb, w = z, f2 = 0;
            
            do {
                if (e[w] == 1) {
                    f2 = 1;
                    
                    break;
                }
                
                w = (w - 1) & z;
            } while (w != z);
            
            if (f2 == 0) {
                f = 1;
                
                break;
            }
            
            comb = ((comb & ~y) / x >> 1) | y;
        }
        
        if (f == 0) {
            l = mid;
            mid = (l + r) / 2;
        } else {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    
    printf("%d\n", r);
    
    return 0;
}