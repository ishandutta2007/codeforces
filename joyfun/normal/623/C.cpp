#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 100005;
const ll INF = 100000000000000000LL;
int n;

struct Point {
    ll x, y;
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    bool operator < (const Point& c) const {
        return x < c.x;
    }
} p[N];

ll pre[N][2], suf[N][2];

int find1(int l, int r, ll x) {
    ll lx = p[l].x;
    while (l < r) {
        int mid = (l + r)>>1;
        if ((p[mid].x - lx) * (p[mid].x - lx) <= x && lx * lx >= p[mid].x * p[mid].x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int find2(int l, int r, ll x) {
    ll rx = p[r].x;
    while (l < r) {
        int mid = (l + r)>>1;
        if ((p[mid].x - rx) * (p[mid].x - rx) <= x && rx * rx >= p[mid].x * p[mid].x) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

bool judge(ll x) {
    if ((p[n].x - p[1].x) * (p[n].x - p[1].x) <= x) return true;
    if ((pre[n][1] - pre[n][0]) * (pre[n][1] - pre[n][0]) <= x) return true;
    for (int l = 1; l <= n; l++) {
        int r = find1(l, n + 1, x);
        ll Max = max(pre[l - 1][1], suf[r][1]);
        ll Min = min(pre[l - 1][0], suf[r][0]);
        ll d = max(Max * Max, Min * Min);
        if (p[l].x * p[l].x + d <= x && (Max - Min) * (Max - Min) <= x) return true;
    }
    int l = n;
    for (int r = n; r >= 1; r--) {
        int l = find2(1, r, x);
        ll Max = max(pre[l][1], suf[r + 1][1]);
        ll Min = min(pre[l][0], suf[r + 1][0]);
        ll d = max(Max * Max, Min * Min);
        if (p[r].x * p[r].x + d <= x && (Max - Min) * (Max - Min) <= x) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        p[i].read();
    sort(p + 1, p + 1 + n);
    pre[0][0] = suf[n + 1][0] = INF;
    pre[0][1] = suf[n + 1][1] = -INF;
    for (int i = 1; i <= n; i++) {
        pre[i][0] = min(pre[i - 1][0], p[i].y);
        pre[i][1] = max(pre[i - 1][1], p[i].y);
    }
    for (int i = n; i >= 1; i--) {
        suf[i][0] = min(suf[i + 1][0], p[i].y);
        suf[i][1] = max(suf[i + 1][1], p[i].y);
    }
    ll l = 0, r = INF;
    while (l < r) {
        ll mid = (l + r)>>1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%lld\n", l);
    return 0;
}