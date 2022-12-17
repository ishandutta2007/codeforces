#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
const int inf = 1e9 + 1;
const int mod = 1e9 + 7;
const long double eps = 1e-6;
mt19937 rnd(58);

struct point {
    long double x, y;
    bool operator==(const point &right);
};

bool point:: operator==(const point &b) {
    return (x == b.x && y == b.y);
}


long double dist(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


long double mindist(point A1, point A2, point B1, point B2) {
    long double x0 = A1.x - B1.x, y0 = A1.y - B1.y;
    long double k = A2.x - A1.x - (B2.x - B1.x), s = A2.y - A1.y - (B2.y - B1.y);
    if (A1 == A2 && B1 == B2)
        return dist(A1, B1);
    long double v = -(x0 * k + y0 * s) / (k*k + s * s);
    long double ans = min(dist(A1, B1), dist(A2, B2));
    if (v > 0 && v < 1)
        ans = min(ans, (k * k + s * s) * v * v + 2 * v * (x0 * k + y0 * s) + x0 * x0 + y0 * y0);
    //cout << A1.x << ' ' << A1.y << ' ' << A2.x << ' ' << A2.y << "\n";
    //cout << B1.x << ' ' << B1.y << ' ' << B2.x << ' ' << B2.y << "\n";
    //cout << ans << ' ' << (k * k + s * s) * v * v - 2 * v * (x0 * k + y0 * s) + x0 * x0 + y0 * y0 << endl;
    return ans;
}

point A[N], B[N];

void solve() {
    int i, j, k, n, d1, d2;
    cin >> n >> d1 >> d2;
    d1 = d1 * d1;
    d2 = d2 * d2;
    for (i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y >> B[i].x >> B[i].y;
    }
    int ans = 0;
    bool canHello = 1;
    for (i = 0; i < n - 1; ++i) {
        if (dist(A[i], B[i]) >= d2 + eps)
            canHello = 1;
        if (canHello && mindist(A[i], A[i + 1], B[i], B[i + 1]) <= d1 + eps) {
            ++ans;
            canHello = 0;
        }
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}