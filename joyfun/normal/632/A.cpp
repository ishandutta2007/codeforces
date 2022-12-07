#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, p;
char str[45][20];

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) scanf("%s", str[i]);
    long long cnt = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int len = strlen(str[i]);
        ans += cnt * p;
        cnt *= 2;
        if (len == 8) {
            ans += p / 2;
            cnt++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}