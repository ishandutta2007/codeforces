#include <cstdio>
using namespace std;
int a[1999], b[1999];
int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x + y - 2]++;
        b[x - y + 999]++;
    }
    long long ans = 0;
    for(int i = 0; i < 1999; i++) {
        ans += a[i] * (a[i] - 1LL) / 2;
        ans += b[i] * (b[i] - 1LL) / 2;
    }
    printf("%lld\n", ans);
}