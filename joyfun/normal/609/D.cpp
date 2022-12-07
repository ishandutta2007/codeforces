#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, m, k, S;
int a[N], b[N], av[N], bv[N];
int cn0;
struct SB {
    long long c;
    int id;
    bool operator < (const SB &x) const {
        return c < x.c;
    }
} s[2][N];

int sn[2];

bool judge(int mid) {
    int ma = a[av[mid]];
    int mb = b[bv[mid]];
    for (int i = 0; i <= sn[0]; i++) {
        if (k - i > sn[1]) continue;
        if (s[0][i].c * ma + s[1][k - i].c * mb <= 1LL * S) {
            cn0 = i;
            return true;
        }
    }
    return false;
}

void solve() {
    if (!judge(n)) {
        printf("-1\n");
        return;
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r)>>1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    judge(l);
    printf("%d\n", l);
    for (int i = 1; i <= cn0; i++) printf("%d %d\n", s[0][i].id, av[l]);
    for (int i = 1; i <= k - cn0; i++) printf("%d %d\n", s[1][i].id, bv[l]);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &S);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    av[1] = bv[1] = 1;
    for (int i = 2; i <= n; i++) {
        av[i] = av[i - 1];
        bv[i] = bv[i - 1];
        if (a[i] < a[i - 1]) av[i] = i;
        else a[i] = a[i - 1];
        if (b[i] < b[i - 1]) bv[i] = i;
        else b[i] = b[i - 1];
    }
    int ti, ci;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &ti, &ci); ti--;
        sn[ti]++;
        s[ti][sn[ti]].c = ci;
        s[ti][sn[ti]].id = i + 1;
    }
    sort(s[0] + 1, s[0] + sn[0] + 1);
    sort(s[1] + 1, s[1] + sn[1] + 1);
    for (int i = 1; i <= sn[0]; i++) s[0][i].c += s[0][i - 1].c;
    for (int i = 1; i <= sn[1]; i++) s[1][i].c += s[1][i - 1].c;
    solve();
    return 0;
}