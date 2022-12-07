#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

const int N = 200005;
long long a[N], s1[N], s2[N];

struct Point {
    long long x, y;
    Point() {}
    Point(long long x, long long y) : x(x), y(y) {}
} st[N];
int top;

bool cao(long long a1, long long b1, long long a2, long long b2) {
    if (a1 / b1 < a2 / b2) return true;
    if (a2 / b2 < a1 / b1) return false;
    a1 %= b1; a2 %= b2;
    if (a2 == 0) return false;
    if (a1 == 0) return true;
    return cao(b2, a2, b1, a1);
}

bool judge(Point a, Point b, Point c) {
    long long x1 = b.x - a.x, y1 = b.y - a.y;
    long long x2 = c.x - a.x, y2 = c.y - a.y;
   // return x1 * y2 - x2 * y1 > 0;
    if (x2 == 0) return (x1 < 0 && y2 < 0) || (x1 > 0 && y2 > 0);
    if (y2 == 0) return (x2 < 0 && y1 > 0) || (x2 > 0 && y1 < 0);
    if ((x2 < 0 && y2 < 0) || (x2 > 0 && y2 > 0)) return cao(y1, y2, x1, x2);
    return cao(x1, x2, y1, y2);
}

void add(long long x, long long y) {
    Point p = Point(x, y);
    while (top >= 2 && !judge(st[top - 2], p, st[top - 1])) top--;
    st[top++] = p;
}

long long get(long long C) {
    int l = 0, r = top - 1;
    while (l < r) {
        int ml = (l * 2 + r) / 3;
        int mr = (l + r * 2 + 2) / 3;
        if (st[ml].x * C + st[ml].y < st[mr].x * C + st[mr].y) l = ml + 1;
        else r = mr - 1;
    }
    return st[l].x * C + st[l].y;
}

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s1[i] = s1[i - 1] + a[i];
        s2[i] = s2[i - 1] + a[i] * i;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        add(i, s1[i] * i - s2[i]);
        ans = max(ans, s2[i + 1] + get(-s1[i + 1]));
    }
    printf("%lld\n", ans);
    return 0;
}