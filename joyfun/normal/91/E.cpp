#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
const long long INF = 1000000000000000000LL;

struct Point {
    int x, y, id;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    void read(int id) {
        scanf("%d%d", &x, &y);
        this->id = id;
    }

    Point operator - (const Point& c) const {
        return Point(x - c.x, y - c.y);
    }

    long long operator * (const Point& c) const {
        return 1LL * x * c.y - 1LL * y * c.x;
    }

    bool operator < (const Point& c) const {
        if (x == c.x) return y < c.y;
        return x < c.x;
    }
} p[N];

int n, qn;
long long ans[N];
int ansv[N];

Point st[N];
int top;

void add(Point p) {
    while (top >= 2 && (p - st[top - 2]) * (st[top - 1] - st[top - 2]) <= 0) top--;
    st[top++] = p;
}

long long cal(Point p, int w) {
    return 1LL * p.y * w + p.x;
}

int get(int w) {
    int l = 0, r = top - 1;
    while (l < r) {
        int mid = (l + r)>>1;
        if (mid == top - 1 || cal(st[mid], w) > cal(st[mid + 1], w)) r = mid;
        else l = mid + 1;
    }
    return l;
}

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)
struct Node {
    vector<Point> p;
    vector<pair<int, int> > q;
} node[N * 4];

void build(int L = 1, int R = n, int x = 1) {
    if (L == R) {
        Point s; s.read(L);
        node[x].p.push_back(s);
        return;
    }
    int mid = (L + R)>>1;
    build(L, mid, lson(x));
    build(mid + 1, R, rson(x));
    for (int i = 0; i < 2; i++) {
        int son = ((x<<1)|i);
        for (int j = 0; j < node[son].p.size(); j++) {
            node[x].p.push_back(node[son].p[j]);
        }
    }
}

void ins(int l, int r, pair<int, int> w, int L = 1, int R = n, int x = 1) {
    if (L >= l && R <= r) {
        node[x].q.push_back(w);
        return;
    }
    int mid = (L + R)>>1;
    if (l <= mid) ins(l, r, w, L, mid, lson(x));
    if (r > mid) ins(l, r, w, mid + 1, R, rson(x));
}

void go(int L = 1, int R = n, int x = 1) {
    top = 0;
    sort(node[x].p.begin(), node[x].p.end());
    for (int i = 0; i < node[x].p.size(); i++)
        add(node[x].p[i]);
    for (int i = 0; i < node[x].q.size(); i++) {
        int id = node[x].q[i].second;
        int w = node[x].q[i].first;
        int v = get(node[x].q[i].first);
        if (ans[id] < cal(st[v], w)) {
            ans[id] = cal(st[v], w);
            ansv[id] = st[v].id;
        }
    }
    if (L == R) return;
    int mid = (L + R)>>1;
    go(L, mid, lson(x));
    go(mid + 1, R, rson(x));
}

int main() {
    scanf("%d%d", &n, &qn);
    build();
    int l, r, ti;
    for (int i = 1; i <= qn; i++) {
        scanf("%d%d%d", &l, &r, &ti);
        ins(l, r, make_pair(ti, i));
        ans[i] = -INF;
    }
    go();
    for (int i = 1; i <= qn; i++) printf("%d\n", ansv[i]);
    return 0;
}