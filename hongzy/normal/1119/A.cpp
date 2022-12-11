#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 3e5 + 10;

int c[N], l[N], r[N], n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        l[i] = n + 1; r[i] = 0;
    }
    for(int i = 1; i <= n; i ++) {
        int x; scanf("%d", &x);
        l[x] = min(l[x], i);
        r[x] = max(r[x], i);
    }
    int ans = 0, mi = n + 1, ma = 0;
    for(int i = 1; i <= n; i ++) {
        if(mi != n + 1 && r[i]) {
            ans = max(ans, r[i] - mi);
        }
        if(ma && l[i] != n + 1) {
            ans = max(ans, ma - l[i]);
        }
        mi = min(mi, l[i]);
        ma = max(ma, r[i]);
    }
    printf("%d\n", ans);
    return 0;
}