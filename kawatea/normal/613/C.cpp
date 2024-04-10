#include <cstdio>
#include <vector>

using namespace std;

int a[26];
char s[100001];

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    int n, ans, sum = 0, c = 0, i, j, k, l;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        sum += a[i];
        
        if (a[i] % 2 == 1) c++;
    }
    
    if (c >= 2) {
        ans = 0;
        
        for (i = 0, j = 0; i < n; i++) {
            while (a[i] > 0) {
                s[j++] = 'a' + i;
                a[i]--;
            }
        }
    } else {
        ans = a[0];
        
        for (i = 1; i < n; i++) ans = gcd(ans, a[i]);
        
        if (c == 1) {
            int p;
            
            for (i = 0; i < n; i++) {
                if (a[i] % 2 == 1) {
                    p = i;
                    a[i] -= ans;
                }
            }
            
            for (i = 0, l = 0; i < ans * 2; i++) {
                if (i % 2 == 0) {
                    for (j = 0; j < n; j++) {
                        for (k = 0; k < a[j] / ans / 2; k++) s[l++] = 'a' + j;
                    }
                    
                    s[l++] = 'a' + p;
                } else {
                    for (j = n - 1; j >= 0; j--) {
                        for (k = 0; k < a[j] / ans / 2; k++) s[l++] = 'a' + j;
                    }
                }
            }
        } else {
            for (i = 0, l = 0; i < ans; i++) {
                if (i % 2 == 0) {
                    for (j = 0; j < n; j++) {
                        for (k = 0; k < a[j] / ans; k++) s[l++] = 'a' + j;
                    }
                } else {
                    for (j = n - 1; j >= 0; j--) {
                        for (k = 0; k < a[j] / ans; k++) s[l++] = 'a' + j;
                    }
                }
            }
        }
    }
    
    printf("%d\n", ans);
    printf("%s\n", s);
    
    return 0;
}