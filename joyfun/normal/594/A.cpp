#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int n, x[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    sort(x + 1, x + 1 + n);
    int yu = n - (n - 1) / 2;
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        if (i + yu - 1 > n) break;
        ans = min(ans, x[i + yu - 1] - x[i]);
    }
    printf("%d\n", ans);
    return 0;
}