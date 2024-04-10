#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2005;
const int INF = 0x3f3f3f3f;

int n;
int Min = INF;

int main() {
    int x;
    scanf("%d", &n);
    long long ans = 0;
    while (n--) {
        scanf("%d", &x);
        ans += x;
        if (x % 2) Min = min(Min, x);
    }
    if (ans % 2) ans -= Min;
    printf("%lld\n", ans);
    return 0;
}