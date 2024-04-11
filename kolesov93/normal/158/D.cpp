#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int N = 111111;
int a[N], s[N], n;
int ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { 
        scanf("%d", a + i);
        ans += a[i];
    }
    
    for (int d = 3; d < n; ++d)
        if ((n % d) == 0) {
            int c = n / d;
            memset(s, 0, sizeof(s));
            for (int i = 0; i < c; ++i) s[i] = a[i];
            for (int i = c; i < n; ++i) s[i] = a[i] + s[i - c];
            for (int i = 1; i <= c; ++i) ans = max(ans, s[n - i]);
        }
    
    cout << ans << endl;
    
    return 0;
}