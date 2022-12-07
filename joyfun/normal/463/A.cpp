#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, s;

int main() {
    scanf("%d%d", &n, &s);
    int x, y;
    int flag = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        if (x == s) {
            if (y == 0) {
                ans = max(ans, y);
                flag = 0;
            }
        }
        else if (x < s) {
            ans = max(ans, (100 - y) % 100);
            flag = 0;
        }
    }
    if (flag) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}