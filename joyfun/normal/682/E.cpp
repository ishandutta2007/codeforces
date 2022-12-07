#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5005;

typedef long long ll;

struct Point {
    ll x, y;

    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
    void read() {
        scanf("%lld%lld", &x, &y);
    }

    Point operator + (const Point &c) const {
        return Point(x + c.x, y + c.y);
    }

    Point operator - (const Point&c) const {
        return Point(x - c.x, y - c.y);
    }
    ll operator * (const Point& c) const {
        return x * c.y - y * c.x;
    }

    bool operator < (const Point& c) const {
        return x < c.x || (x == c.x && y < c.y);
    }

    Point operator - (const Point&c) {
        return Point(x - c.x, y - c.y);
    }
} p[N], st[N];

int n;

void gao() {
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && (st[m - 1] - st[m - 2]) * (p[i] - st[m - 2]) <= 0) m--;
        st[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && (st[m - 1] - st[m - 2]) * (p[i] - st[m - 2]) <= 0) m--;
        st[m++] = p[i];
    }
    if (n > 1) m--;
    for (int i = 0; i < m; i++) p[i] = st[i];
    n = m;
}

ll area(Point a, Point b, Point c) {
    ll tmp = (c - a) * (b - a);
    return max(tmp, -tmp);
}

int ii = 0, jj = 1, kk = 2;

int main() {
    scanf("%d%*d", &n);
    for (int i = 0; i < n; i++) p[i].read();
    gao();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n, k = (j + 1) % n;
        while (j != i) {
            while (k != i && area(p[i], p[j], p[k]) < area(p[i], p[j], p[(k + 1) % n]))
                k = (k + 1) % n;
            if (k == i) break;
            if (area(p[ii], p[jj], p[kk]) < area(p[i], p[j], p[k])) {
                ii = i;
                jj = j;
                kk = k;
            }
            j = (j + 1) % n;
        }
    }
    //for (int i = 0; i < n; i++) printf("%lld %lld\n", p[i].x, p[i].y);
    Point pp[3];
    pp[0] = (p[jj] + p[kk] - p[ii]);
    pp[1] = (p[ii] + p[kk] - p[jj]);
    pp[2] = (p[ii] + p[jj] - p[kk]);
    for (int i = 0; i < 3; i++) printf("%lld %lld\n", pp[i].x, pp[i].y);
    return 0;
}