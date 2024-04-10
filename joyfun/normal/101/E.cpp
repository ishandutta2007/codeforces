#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20005;
int n, m, p;
int x[N], y[N];
long long f[N], L[N], R[N];

int w(int i, int j) {
    int ans = x[i] + y[j];
    if (ans >= p) ans -= p;
    return ans;
}

char ans[N];
int an;
int v[N];

void go(int l, int r, int l2, int r2, long long val) {
    if (l == r) return;
    int mid = (l + r)>>1;
    memset(L, 0, sizeof(L));
    for (int i = l; i <= mid; i++) {
        for (int j = l2; j <= r2; j++) {
            L[j] = max(L[j], L[j - 1]) + w(i, j);
        }
    }
    memset(R, 0, sizeof(R));
    for (int i = r; i >= mid + 1; i--) {
        for (int j = r2; j >= l2; j--) {
            R[j] = max(R[j], R[j + 1]) + w(i, j);
        }
    }
    int mid2;
    for (int i = l2; i <= r2; i++) {
        if (L[i] + R[i] == val) {
            mid2 = i;
            break;
        }
    }
    long long lval = L[mid2], rval = R[mid2];
    go(l, mid, l2, mid2, lval);
    ++an;
    v[an] = mid2;
    ans[an] = 'C';
    go(mid + 1, r, mid2, r2, rval);
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        x[i] %= p;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &y[i]);
        y[i] %= p;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[j] = max(f[j], f[j - 1]) + w(i, j);
        }
    }
    go(1, n, 1, m, f[m]);
    v[0] = 1;
    printf("%lld\n", f[m]);
    for (int i = 1; i <= an; i++) {
        for (int j = v[i - 1] + 1; j <= v[i]; j++)
            printf("%c", 'S');
        printf("%c", ans[i]);
    }
    for (int i = v[an] + 1; i <= m; i++) printf("%c", 'S');
    return 0;
}