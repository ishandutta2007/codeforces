#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int pre = 0, ans = 0;
    int a;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (a >= pre) {
            pre = a;
            cnt++;
        } else {
            pre = a;
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}