#include <stdio.h>

using namespace std;

const int N = 111;
int a[N], n, k;
int ans;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
        
    if (a[k - 1] == 0) {
        ans = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] > 0) ++ans;
        printf("%d\n", ans);
        return 0;
    }
    
    for (int i = k; i <= n; ++i)
        if (a[i] != a[k - 1]) {
            printf("%d\n", i);
            return 0;
        }
        
    return 0;
}