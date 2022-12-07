#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, up, down;

int main() {
    scanf("%d%d", &n, &up); down = up;
    long long ans = 0;
    int l, r;
    while (n--) {
        scanf("%d%d", &l, &r);
        if (l >= down && r <= up) {
            down = l;
            up = r;
        } else if (down > r) {
            ans += down - r;
            up = down;
            down = r;
        } else if (l > up) {
            ans += l - up;
            down = up;
            up = l;
        } else if (l >= down && l <= up) {
            down = l;
        } else if (r >= down && r <= up) {
            up = r;
        }
      //  printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
    return 0;
}