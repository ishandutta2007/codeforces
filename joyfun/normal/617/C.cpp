#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2005;

int n;

struct Point {
    long long x, y;
    void read() {
        scanf("%lld%lld", &x, &y);
    }
} p1, p2, p[N];

long long dist(Point a, Point b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool cmp(Point a, Point b) {
    if (dist(a, p1) == dist(b, p1)) return dist(a, p2) < dist(b, p2);
    return dist(a, p1) > dist(b, p1);
}

int main() {
    scanf("%d", &n);
    p1.read();
    p2.read();
    long long r1 = 0, r2 = 0;
    for (int i = 0; i < n; i++)
        p[i].read();
    sort(p, p + n, cmp);
    long long ans = dist(p[0], p1);
    long long tmp = 0;
    for (int i = 0; i < n - 1; i++) {
        tmp = max(tmp, dist(p[i], p2));
        ans = min(ans, dist(p[i + 1], p1) + tmp);
    }
    tmp = max(tmp, dist(p[n - 1], p2));
    ans = min(ans, tmp);
    printf("%lld\n", ans);
    return 0;
}