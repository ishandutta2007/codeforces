#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 100005;

int n, m, k, a[N];

int block_size;

struct Query {
    int l, r, id;
    void read(int id) {
        scanf("%d%d", &l, &r);
        l--;
        this->id = id;
    }
} q[N];

bool cmp(Query a, Query b) {
    if (a.l / block_size == b.l / block_size) return a.r < b.r;
    return a.l / block_size < b.l / block_size;
}

ll cal, ans[N], cnt[N * 20];

ll query(int p, int u) {
    if (p != -1) {
        for (int i = q[u].l; i < q[p].l; i++) {
            cal += cnt[k^a[i]];
            cnt[a[i]]++;
        }
        for (int i = q[p].l; i < q[u].l; i++) {
            cnt[a[i]]--;
            cal -= cnt[k^a[i]];
        }
        for (int i = q[p].r + 1; i <= q[u].r; i++) {
            cal += cnt[k^a[i]];
            cnt[a[i]]++;
        }
        for (int i = q[u].r + 1; i <= q[p].r; i++) {
            cnt[a[i]]--;
            cal -= cnt[k^a[i]];
        }
    } else {
        for (int i = q[u].l; i <= q[u].r; i++) {
//            printf("%d %d\n", a[i], k^a[i]);
            cal += cnt[k^a[i]];
            cnt[a[i]]++;
        }
    }
    return cal;
}

int main() {
    while (~scanf("%d%d%d", &n, &m, &k)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] ^= a[i - 1];
        }
        block_size = sqrt(n + 0.5);
        for (int i = 0; i < m; i++) q[i].read(i);
        sort(q, q + m, cmp);
        cal = 0;
        for (int i = 0; i < m; i++)
            ans[q[i].id] = query(i - 1, i);
        for (int i = 0; i < m; i++)
            printf("%lld\n", ans[i]);
    }
    return 0;
}