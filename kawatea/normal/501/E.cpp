#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];
int b[100001];
int c1[100001];
int c2[100001];

int main()
{
    int n, c = 0, x = 0, y = 0, z1 = 0, z2 = 0, i;
    long long ans = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        b[a[i]]++;
        
        if (b[a[i]] % 2 == 0) {
            c--;
        } else {
            c++;
        }
    }
    
    if (c >= 2) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) break;
        
        x++;
    }
    
    if (x == n / 2) {
        printf("%I64d\n", (long long)n * (n + 1) / 2);
        
        return 0;
    }
    
    for (i = n / 2 - 1; i >= 0; i--) {
        if (a[i] != a[n - i - 1]) break;
        
        y++;
    }
    
    for (i = 0; i < x; i++) c1[a[i]]++;
    
    for (i = x; i < n / 2; i++) {
        c1[a[i]]++;
        
        if (c1[a[i]] * 2 > b[a[i]]) break;
        
        z1++;
    }
    
    for (i = 0; i < x; i++) c2[a[i]]++;
    
    for (i = x; i < n / 2; i++) {
        c2[a[n - i - 1]]++;
        
        if (c2[a[n - i - 1]] * 2 > b[a[n - i - 1]]) break;
        
        z2++;
    }
    
    for (i = 0; i <= x; i++) {
        ans += x + z1 + z2 + 1;
        
        if (x + z1 == n / 2) {
            if (n % 2 == 1) {
                if (b[a[n / 2]] % 2 == 1) {
                    ans++;
                    
                    ans += min(y, n / 2 - i);
                }
            } else {
                ans += min(y, n / 2 - i);
            }
        }
        
        if (x + z2 == n / 2) {
            if (n % 2 == 1) {
                if (b[a[n / 2]] % 2 == 1) {
                    ans++;
                    
                    ans += min(y, n / 2 - i);
                }
            } else {
                ans += min(y, n / 2 - i);
            }
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}