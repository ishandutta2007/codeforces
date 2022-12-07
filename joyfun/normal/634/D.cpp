#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int d, n, m;
struct Sta {
    int x, p;

    Sta() {}
    Sta(int x, int p) : x(x), p(p) {}
    void read() {
        scanf("%d%d", &x, &p);
    }

    bool operator < (const Sta& c) const {
        return x < c.x;
    }
} p[N];

#define lson(x) (x<<1)
#define rson(x) (x<<1)|1

struct Node {
    int Min, Minid;
} node[N<<2];

void pushup(int x) {
    node[x].Min = min(node[lson(x)].Min, node[rson(x)].Min);
    if (node[x].Min == node[rson(x)].Min) node[x].Minid = node[rson(x)].Minid;
    if (node[x].Min == node[lson(x)].Min) node[x].Minid = node[lson(x)].Minid;
}

void build(int L = 1, int R = m, int x = 1) {
    if (L == R) {
        node[x].Min = p[L].p;
        node[x].Minid = L;
        return;
    }
    int mid = (L + R)>>1;
    build(L, mid, lson(x));
    build(mid + 1, R, rson(x));
    pushup(x);
}

int Min, Minid;

void getMin(int l, int r, int L = 1, int R = m, int x = 1) {
    if (L >= l && R <= r) {
        if (Min > node[x].Min) {
            Min = node[x].Min;
            Minid = node[x].Minid;
        }
        return;
    }
    int mid = (L + R)>>1;
    if (l <= mid) getMin(l, r, L, mid, lson(x));
    if (r > mid) getMin(l, r, mid + 1, R, rson(x));
}

ll solve() {
    int s = 0;
    ll ans = 0;
    int yu = 0;
    while (s < m) {
        int v = upper_bound(p + s + 1, p + m + 1, Sta(p[s].x + n, 0)) - p - 1;
        if (v == s) return -1;
        Min = INF;
        getMin(s + 1, v);
        if (Min > p[s].p) {
            ans += 1LL * (n - yu) * p[s].p;
            yu = n;
            yu -= p[Minid].x - p[s].x;
            s = Minid;
        } else {
            for (int j = s + 1; j <= Minid; j++) {
               if (p[j].p <= p[s].p) {
                   int dis = p[j].x - p[s].x;
                   if (yu >= dis) {
                       yu -= dis;
                   } else {
                       ans += 1LL * (dis - yu) * p[s].p;
                       yu = 0;
                   }
                   s = j;
                   break;
               }
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &d, &n, &m);
    p[0] = Sta(0, 0);
    for (int i = 1; i <= m; i++) p[i].read();
    p[++m] = Sta(d, 0);
    sort(p, p + m + 1);
    build();
    printf("%lld\n", solve());
    return 0;
}