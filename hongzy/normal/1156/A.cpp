#include <algorithm>
#include <cstdio>
using namespace std;

int n, x, y, ans, a[100010];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        x = a[i];
        y = a[i - 1];
        if(i > 1) {
            if(x + y == 5) {
                puts("Infinite");
                return 0;
            }
            if(y == 1) {
                if(x == 2) {
                    ans += 3;
                    if(i >= 3 && a[i - 2] == 3) ans --;
                }
                if(x == 3) ans += 4;
            }
            if(y == 2) {
                ans += 3;
            }
            if(y == 3) {
                ans += 4;
            }
        }
        y = x;
    }
    puts("Finite");
    printf("%d\n", ans);
    return 0;
}