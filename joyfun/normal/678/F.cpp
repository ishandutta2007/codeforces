#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 300005;
const long long INF = 2000000000000000000LL;
int n;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator < (const Point& c) const {
        if (x == c.x) return y < c.y;
        return x < c.x;
    }

    Point operator - (const Point& c) const {
        return Point(x - c.x, y - c.y);
    }

    long long operator * (const Point& c) const {
        return 1LL * x * c.y - 1LL * y * c.x;
    }

};

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
struct Node {
    vector<Point> p;
    vector<pair<int, int> > q;
} node[N * 4];

int tp[N], x[N], y[N];
long long ans[N];

void build(int L = 1, int R = n, int x = 1) {
    if (L == R) return;
    int mid = (L + R)>>1;
    build(L, mid, lson(x));
    build(mid + 1, R, rson(x));
}

void ins(pair<int, int> v, int L = 1, int R = n, int x = 1) {
    node[x].q.push_back(v);
    if (L == R) return;
    int mid = (L + R)>>1;
    if (v.second <= mid) ins(v, L, mid, lson(x));
    else ins(v, mid + 1, R, rson(x));
}

void add(int l, int r, Point p, int L = 1, int R = n, int x = 1) {
    if (L >= l && R <= r) {
        node[x].p.push_back(p);
        return;
    }
    int mid = (L + R)>>1;
    if (l <= mid) add(l, r, p, L, mid, lson(x));
    if (r > mid) add(l, r, p, mid + 1, R, rson(x));
}

Point st[N];
int top;

void gao(vector<Point> p) {
    sort(p.begin(), p.end());
    top = 0;
    for (int i = 0; i < p.size(); i++) {
        while (top >= 2 && (p[i] - st[top - 2]) * (st[top - 1] - st[top - 2]) <= 0) top--;
        st[top++] = p[i];
    }
}

long long cal(Point p, int q) {
    return 1LL * p.x * q + p.y;
}

long long get(int q) {
    if (top == 0) return -INF;
    int l = 0, r = top - 1;
    while (l < r) {
        int mid = (l + r)>>1;
        if (mid == top - 1 || cal(st[mid], q) > cal(st[mid + 1], q)) r = mid;
        else l = mid + 1;
    }
    return cal(st[l], q);
}

void go(int L = 1, int R = n, int x = 1) {
    gao(node[x].p);
    for (int i = 0; i < node[x].q.size(); i++) {
        int w = node[x].q[i].first;
        int id = node[x].q[i].second;
        ans[id] = max(ans[id], get(w));
    }
    if (L == R) return;
    int mid = (L + R)>>1;
    go(L, mid, lson(x));
    go(mid + 1, R, rson(x));
}

int main() {
    scanf("%d", &n);
    build();
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &tp[i], &x[i]);
        if (tp[i] == 1) scanf("%d", &y[i]);
        else if (tp[i] == 2) {
            add(x[i], i, Point(x[x[i]], y[x[i]]));
            tp[x[i]] = 0;
        } else ins(make_pair(x[i], i));
        ans[i] = -INF;
    }
    for (int i = 1; i <= n; i++) if (tp[i] == 1) add(i, n, Point(x[i], y[i]));
    go();
    for (int i = 1; i <= n; i++) {
        if (tp[i] == 3) {
            if (ans[i] == -INF) printf("EMPTY SET\n");
            else printf("%lld\n", ans[i]);
        }
    }
    return 0;
}