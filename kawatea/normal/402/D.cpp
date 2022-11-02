#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int a[5000];
int b[5000];
int d[5000];

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int n, m, g, ans = 0, i, j;
    set <int> s;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        s.insert(x);
    }
    
    for (i = 0; i < n; i++) {
        int x = a[i];
        
        for (j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                int c = 0;
                
                while (x % j == 0) {
                    x /= j;
                    c++;
                }
                
                if (s.count(j)) {
                    ans -= c;
                } else {
                    ans += c;
                }
            }
        }
        
        if (x > 1) {
            if (s.count(x)) {
                ans--;
            } else {
                ans++;
            }
        }
    }
    
    g = a[0];
    
    for (i = 0; i < n; i++) {
        g = gcd(g, a[i]);
        
        b[i] = g;
    }
    
    for (i = 0; i < n; i++) {
        int x = b[i];
        
        for (j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                int c = 0;
                
                while (x % j == 0) {
                    x /= j;
                    c++;
                }
                
                if (s.count(j)) {
                    d[i] -= c;
                } else {
                    d[i] += c;
                }
            }
        }
        
        if (x > 1) {
            if (s.count(x)) {
                d[i]--;
            } else {
                d[i]++;
            }
        }
    }
    
    for (i = n - 1; i >= 0; i--) {
        if (d[i] < 0) {
            ans -= d[i] * (i + 1);
            
            for (j = 0; j <= i; j++) d[j] -= d[i];
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}