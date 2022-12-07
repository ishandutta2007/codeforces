#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int N = 1000005;

struct Point {
    int x, y, val, id;
    void read(int x, int y) {
        this->x = x; this->y = y;
        scanf("%d", &val);
    }
    bool operator < (const Point& c) const {
        return val < c.val;
    }
} p[N], tmp[N];

int n, m, tn, ans[N];
int r[N], c[N], parent[N], Max[N];

bool cmpx(Point a, Point b) {
    return a.x < b.x;
}

bool cmpy(Point a, Point b) {
    return a.y < b.y;
}

int st[N], top;

int find(int x) {
    top = 0;
    while (x != parent[x]) {
        st[top++] = x;
        x = parent[x];
    }
    for (int i = 0; i < top; i++)
        parent[st[i]] = x;
    return x;
}

void cao() {
    for (int i = 0; i < tn; i++) {
        int x = tmp[i].x, y = tmp[i].y;
        tmp[i].id = i; parent[i] = i;
        Max[i] = max(r[x], c[y]) + 1;
    }
    sort(tmp, tmp + tn, cmpx);
    for (int i = 1; i < tn; i++) {
        if (tmp[i].x == tmp[i - 1].x) {
            int pu = find(tmp[i - 1].id);
            int pv = find(tmp[i].id);
            if (pu != pv) {
                Max[pv] = max(Max[pv], Max[pu]);
                parent[pu] = pv;
            }
        }
    }
    sort(tmp, tmp + tn, cmpy);
    for (int i = 1; i < tn; i++) {
        if (tmp[i].y == tmp[i - 1].y) {
            int pu = find(tmp[i - 1].id);
            int pv = find(tmp[i].id);
            if (pu != pv) {
                Max[pv] = max(Max[pv], Max[pu]);
                parent[pu] = pv;
            }
        }
    }
    for (int i = 0; i < tn; i++) {
        int val = Max[find(tmp[i].id)];
        int x = tmp[i].x, y = tmp[i].y;
        ans[(x - 1) * m + y - 1] = val;
        r[x] = val; c[y] = val;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int pn = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
           p[pn++].read(i, j);
    sort(p, p + pn);
    tn = 0;
    tmp[tn++] = p[0];
    for (int i = 1; i < pn; i++) {
        if (p[i].val == p[i - 1].val) tmp[tn++] = p[i];
        else {
            cao();
            tn = 0;
            tmp[tn++] = p[i];
        }
    }
    cao();
    for (int i = 0; i < pn; i++) {
        if (i && i % m == 0) printf("\n");
        printf("%d ", ans[i]);
    }
    return 0;
}