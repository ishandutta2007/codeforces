#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n;
long long v[N], d[N], p[N];
int ans[N], an;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &v[i], &d[i], &p[i]);
    an = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] < 0) continue;
        ans[an++] = i;
        long long s = v[i];
        long long ds = 0;
        for (int j = i + 1; j <= n; j++) {
            if (p[j] < 0) continue;
            p[j] -= s;
            p[j] -= ds;
            if (p[j] < 0) {
                ds += d[j];
            }
            if (s) s--;
        }
    }
    printf("%d\n", an);
    for (int i = 0; i < an; i++) printf("%d ", ans[i]);
    return 0;
}