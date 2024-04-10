#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct seg {
    int xl, xr, y;
};

struct vec {
    int x, y, p1, p2, t;
    double ang;
};

bool cmp(vec a, vec b) {
    if (abs(a.ang - b.ang) > 1e-15) return a.ang > b.ang;
    return a.t < b.t;
}

bool cmps(seg x, seg y) {
    if (x.y != y.y) return x.y > y.y;
    return x.xl < y.xl;
}

const int MN = 2005;

int n, rev[MN], flip[MN][MN];
seg a[MN];
vector<vec> v;

double pos(int x, int y, int dx, int dy) {
    double times = (double) y / (double) -dy;
    return (double) x + (double) dx * times;
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].xl >> a[i].xr >> a[i].y;
    }
    double ans = 1e18;
    sort(a + 1, a + n + 1, cmps);
    for (int i = 1; i <= n; i++) rev[i] = i;
    //ANGULAR LINE SWEEP ON VECTORS
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dx = a[i].xr - a[j].xl;
            int dy = a[i].y - a[j].y;
            if (dy == 0) continue;
            if (dy > 0) dy = -dy, dx = -dx;
            double ang = (double) dx / (double) dy;
            swap(i, j);
            int dx1 = a[i].xr - a[j].xl;
            int dy1 = a[i].y - a[j].y;
            if (dy1 > 0) dy1 = -dy1, dx1 = -dx1;
            double ang1 = (double) dx1 / (double) dy1;
            swap(i, j);
            v.push_back({dx, dy, i, j, 1, ang});
            v.push_back({dx1, dy1, i, j, 0, ang1});
        }
    }
    if (v.empty()) return 0 * printf("%d\n", a[n].xr - a[1].xl);
    sort(v.begin(), v.end(), cmp);
    seg L = a[1], R = a[n];
    int layer = 0;
    for (vec p : v) {
        int dx = p.x, dy = p.y;
        assert(dy != 0);
        if (layer == 0) {
            double lft = pos(L.xl, L.y, dx, dy);
            double rit = pos(R.xr, R.y, dx, dy);
            ans = min(ans, rit - lft);
        }
        flip[p.p1][p.p2] ^= 1;
        if (flip[p.p1][p.p2]) layer++;
        else {
            layer--;
            rev[p.p1]++;
            rev[p.p2]--;
            if (rev[p.p1] == n) R = a[p.p1];
            if (rev[p.p2] == 1) L = a[p.p2];
        }
        if (layer == 0) {
            double lft = pos(L.xl, L.y, dx, dy);
            double rit = pos(R.xr, R.y, dx, dy);
            ans = min(ans, rit - lft);
        }
    }
    printf("%.8f\n", ans);

    return 0;
}
/*
3
1 5 3
6 9 1
8 12 4
 */