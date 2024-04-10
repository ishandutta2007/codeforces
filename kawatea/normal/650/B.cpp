#include <cstdio>
#include <algorithm>

using namespace std;

int n, a, b;
char s[1000001];
int c[1000001];

long long get(int x, int y) {
    if (x == 0) {
        return (long long)(y - x) * a + (y - x + 1) + (long long)(c[y + 1] - c[x]) * b;
    } else if (y >= n) {
        int z = min(n - x, y - n);
        return (long long)(y - x + z) * a + (y - x + 1) + (long long)(c[y + 1] - c[x]) * b; 
    } else {
        return min(get(0, y), get(x, n));
    }
}

int main()
{
    int t, ans = 0, i, j;
    
    scanf("%d %d %d %d", &n, &a, &b, &t);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) s[i + n] = s[i];
    
    for (i = 0; i < n * 2; i++) {
        c[i + 1] = c[i];
        if (s[i] == 'w') c[i + 1]++;
    }
    
    if (get(0, n - 1) <= t) {
        ans = n;
    } else {
        for (i = 0, j = 0; i < n; i++) {
            while (get(i, j) <= t) j++;
            
            ans = max(ans, j - i);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}