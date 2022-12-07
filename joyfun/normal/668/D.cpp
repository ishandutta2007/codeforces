#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int N = 100005;

map<int, int> S;

struct OP {
    int tp, ti, a, id;

    void read(int id) {
        scanf("%d%d%d", &tp, &ti, &a);
        this->id = id;
    }

    bool operator < (const OP& c) const {
        return ti < c.ti;
    }
} op[N];

int n, ans[N], vis[N];

void cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r)>>1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(op + l, op + mid + 1);
    sort(op + mid + 1, op + r + 1);
    int i = l, j = mid + 1;
    while (j <= r) {
        if (i <= mid && op[i].ti < op[j].ti) {
            if (op[i].tp == 1) S[op[i].a]++;
            if (op[i].tp == 2) S[op[i].a]--;
            i++;
        } else {
            if (op[j].tp == 3) {
                ans[op[j].id] += S[op[j].a];
            }
            j++;
        }
    }
    S.clear();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        op[i].read(i);
        if (op[i].tp == 3) vis[i] = 1;
    }
    cdq(1, n);
    for (int i = 1; i <= n; i++) if (vis[i]) printf("%d\n", ans[i]);
    return 0;
}