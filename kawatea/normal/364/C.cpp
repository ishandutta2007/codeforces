#include <cstdio>
#include <vector>

using namespace std;

int b[32];
int f[10000];

int main()
{
    int n, c, i, j, k, l, r;
    vector <long long> v[32];
    vector <long long> w;
    
    scanf("%d", &n);
    
    int sum = 0;
    
    for (i = 0; ; i++) {
        long long x = 1LL << i;
        
        if (x > n * n * 2) break;
        
        for (j = 0; ; j++, x *= 3) {
            long long y = x;
            
            if (y > n * n * 2) break;
            
            for (k = 0; ; k++, y *= 5) {
                long long z = y;
                
                if (z > n * n * 2) break;
                
                for (l = 0; ; l++, z *= 7) {
                    long long w = z;
                    
                    if (w > n * n * 2) break;
                    
                    for (r = 0; ; r++, w *= 11) {
                        int c = 0;
                        
                        if (w > n * n * 2) break;
                        
                        if (i > 0) c |= 1;
                        if (j > 0) c |= 2;
                        if (k > 0) c |= 4;
                        if (l > 0) c |= 8;
                        if (r > 0) c |= 16;
                        
                        v[c].push_back(w);
                    }
                }
            }
        }
    }
    
    if (n <= 50) {
        c = 4;
    } else if (n <= 300) {
        c = 8;
    } else if (n <= 2000) {
        c = 16;
    } else {
        c = 32;
    }
    
    while (w.size() < n) {
        int f = 0;
        
        for (i = 1; i < c; i++) {
            if (b[i] == v[i].size()) continue;
            
            if (w.size() < n) {
                w.push_back(v[i][b[i]++]);
                f = 1;
            }
        }
        
        if (f == 0) break;
    }
    
    for (i = 0; i < w.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%I64d", w[i]);
    }
    
    puts("");
    
    return 0;
}