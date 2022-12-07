#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int n, a[N];

int main() {
    scanf("%d", &n);
    int Min = INF;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        Min = min(Min, a[i]);
    }
    long long ans = 1LL * Min * n;
    for (int i = 1; i <= n; i++) {
        a[i] -= Min;
        if (a[i] != 0) a[i] = 1;
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) break;
        cnt++;
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) break;
        cnt++;
    }
    long long tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cnt = max(cnt, tmp);
            tmp = 0;
        } else {
            tmp++;
        }
    }
    cnt = max(cnt, tmp);
    printf("%lld\n", ans + cnt);
    return 0;
}