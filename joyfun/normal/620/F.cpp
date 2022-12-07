#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50005;
const int M = 5005;
const int MAXN = 1000005;

int n, m;

struct Q {
    int l, r, id;
    void read(int id) {
        this->id = id;
        scanf("%d%d", &l, &r);
    }
    bool operator < (const Q& c) const {
        return r < c.r;
    }
} q[M];

int a[N];

int to[MAXN];
int ans[M];

int main() {
    for (int i = 1; i < MAXN; i++)
        to[i] = (to[i - 1]^i);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) q[i].read(i);
    sort(q, q + m);
    for (int i = 1; i <= n; i++) {
        int r = i;
        int Max = 0;
        for (int j = 0; j < m; j++) {
            if (i < q[j].l || i > q[j].r) continue;
            while (r <= q[j].r) {
                if (a[i] < a[r]) Max = max(Max, to[a[i] - 1]^to[a[r]]);
                else Max = max(Max, to[a[i]]^to[a[r] - 1]);
                r++;
            }
            ans[q[j].id] = max(ans[q[j].id], Max);
        }
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
    return 0;
}