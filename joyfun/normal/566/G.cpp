#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

struct Point {
    long long x, y;

    Point() {}
    Point(long long x, long long y) : x(x), y(y) {}

    void read() {
        scanf("%lld%lld", &x, &y);
    }

    bool operator < (const Point& c) const {
        if (x == c.x) return y < c.y;
        return x < c.x;
    }

    Point operator - (const Point& c) const {
        return Point(x - c.x, y - c.y);
    }

    long long operator * (const Point& c) const {
        return x * c.y - y * c.x;
    }
} a[N], b[N];

int n, m;

Point st[N];
int top;

bool judge() {
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (j <= top && st[j].x <= a[i].x) j++;
        if (j == top + 1) return false;
        if (j == 1) {
            if (a[i].y >= st[j].y) return false;
        } else if ((st[j] - st[j - 1]) * (a[i] - st[j - 1]) >= 0) return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%*d%*d");
    for (int i = 1; i <= n; i++) a[i].read();
    for (int i = 1; i <= m; i++) b[i].read();
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    for (int i = 1; i <= m; i++) {
        while (top && b[i].y >= st[top].y) top--;
        while (top > 1 && (st[top] - st[top - 1]) * (b[i] - st[top]) >= 0) top--;
        st[++top] = b[i];
    }
    printf("%s\n", judge() ? "Min" : "Max");
    return 0;
}