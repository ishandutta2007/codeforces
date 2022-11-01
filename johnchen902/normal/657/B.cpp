#include <cstdio>
#include <cassert>
using namespace std;
int a[200001];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n + 1; i++)
        scanf("%d", a + i);
    long long x = 0;
    int finalzr = n;
    for(int i = 0; i < n + 1; i++) {
        x /= 2;
        x += a[i];
        if(x % 2 != 0) {
            finalzr = i;
            break;
        }
    }
    // a[0, finalzr] = x << finalzr
    long long y = 0;
    int ans = 0;
    for(int i = n; i >= 0; i--) {
        y *= 2;
        if(i <= finalzr) {
            if(i == finalzr)
                y += x;
            long long aa = a[i] - y;
            // fprintf(stderr, "a[%d]->%lld\n", i, aa);
            assert(aa != a[i]);
            if(aa >= -k && aa <= k && (i != n || aa != 0))
                ans++;
        } else {
            y += a[i];
        }
        if(y > k || y < -k)
            break;
    }

    printf("%d\n", ans);
}