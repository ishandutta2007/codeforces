#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
int n, q;

struct Base {
    int s[30], w;
    Base() {memset(s, 0, sizeof(s)); w = 0;}
    void ins(int val) {
        for (int i = 29; i >= 0; i--) {
            if ((val>>i)&1) {
                if (!s[i]) {
                    s[i] = val;
                    return;
                }
                val ^= s[i];
            }
        }
    }

    int sz() {
        int cnt = 0;
        for (int i = 0; i <= 29; i++) if (s[i]) cnt++;
        return cnt;
    }
};

Base meg(Base a, Base b) {
    for (int i = 0; i <= 29; i++)
        if (b.s[i]) a.ins(b.s[i]);
    a.ins(a.w^b.w);
    return a;
}

struct Node {
    Base b;
    int lazy;
    Node() {b = Base(); lazy = 0;}

    void gao(int f) {
        b.w ^= f;
        lazy ^= f;
    }
} node[N<<2];

void pushdown(int x) {
    if (node[x].lazy) {
        node[lson(x)].gao(node[x].lazy);
        node[rson(x)].gao(node[x].lazy);
        node[x].lazy = 0;
    }
}

void pushup(int x) {
    node[x].b = meg(node[lson(x)].b, node[rson(x)].b);
}

void build(int L = 1, int R = n, int x = 1) {
    if (L == R) {
        scanf("%d", &node[x].b.w);
        return;
    }
    int mid = (L + R)>>1;
    build(L, mid, lson(x));
    build(mid + 1, R, rson(x));
    pushup(x);
}

void add(int l, int r, int w, int L = 1, int R = n, int x = 1) {
    if (L >= l && R <= r) {
        node[x].gao(w);
        return;
    }
    int mid = (L + R)>>1;
    pushdown(x);
    if (l <= mid) add(l, r, w, L, mid, lson(x));
    if (r > mid) add(l, r, w, mid + 1, R, rson(x));
    pushup(x);
}

Base get(int l, int r, int L = 1, int R = n, int x = 1) {
    if (L >= l && R <= r)
        return node[x].b;
    int mid = (L + R)>>1;
    pushdown(x);
    Base ans;
    if (l <= mid) ans = meg(ans, get(l, r, L, mid, lson(x)));
    if (r > mid) ans = meg(ans, get(l, r, mid + 1, R, rson(x)));
    pushup(x);
    return ans;
}

int main() {
    scanf("%d%d", &n, &q);
    build();
    int tp, l, r, w;
    while (q--) {
        scanf("%d%d%d", &tp, &l, &r);
        if (tp == 1) {
            scanf("%d", &w);
            add(l, r, w);
        } else {
            Base ans;
            ans = meg(ans, get(l, r));
            printf("%d\n", 1<<ans.sz());
        }
    }
    return 0;
}