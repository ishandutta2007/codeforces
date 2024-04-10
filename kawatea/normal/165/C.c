#include <stdio.h>
#include <string.h>

char s[1000001];
int a[1000001];

int lower_bound(int n, int x)
{
    int l = -1, r = n, m = (l + r) / 2;
    
    while (r - l > 1) {
        if (a[m] >= x) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    return r;
}

int upper_bound(int n, int x)
{
    int l = -1, r = n, m = (l + r) / 2;
    
    while (r - l > 1) {
        if (a[m] > x) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    return r;
}

int main()
{
    int k, n, i;
    long long sum = 0;
    
    scanf("%d", &k);
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        a[i + 1] = a[i];
        
        if (s[i] == '1') a[i + 1]++;
    }
    
    for (i = 0; i <= n; i++) {
        if (a[i] < k) continue;
        
        sum += upper_bound(i, a[i] - k) - lower_bound(i, a[i] - k);
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}