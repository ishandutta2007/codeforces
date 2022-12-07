#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
typedef long long ll;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}

    Point operator - (const Point& c) const {
        return Point(x - c.x, y - c.y);
    }

    ll operator * (const Point& c) const {
        return x * c.y - y * c.x;
    }
} p[N];

int n;
ll a[N], sum;

Point st[N];
int top;

ll get(int i, int tp) {
    ll c = a[i];
    int l = 0, r = top - 1;
    while (l < r) {
        int ml = (l * 2 + r) / 3;
        int mr = (l + r * 2 + 2) / 3;
        if (st[ml].x * c - st[ml].y < st[mr].x * c - st[mr].y) l = ml + 1;
        else r = mr - 1;
    }
    return st[l].x * c - st[l].y + p[i - tp].y - c * (i - tp);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i] * i;
        p[i] = Point(1LL * i, p[i - 1].y + a[i]);
    }
    top = 0;
    ll Max = 0;
    for (int i = n; i >= 1; i--) {
        while (top >= 2 && (p[i] - st[top - 1]) * (st[top - 1] - st[top - 2]) <= 0) --top;
        st[top++] = p[i];
        Max = max(Max, get(i, 0));
    }
    top = 0;
    for (int i = 1; i <= n; i++) {
        while (top >= 2 && (p[i - 1] - st[top - 1]) * (st[top - 1] - st[top - 2]) >= 0) --top;
        st[top++] = p[i - 1];
        Max = max(Max, get(i, 1));
    }
    printf("%lld\n", Max + sum);
    return 0;
}