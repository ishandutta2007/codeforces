#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int n;

int main() {
    scanf("%d", &n);
    int a, b;
    b = INF;
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (b >= a) {
            cnt = 1;
        } else cnt++;
        b = a;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}