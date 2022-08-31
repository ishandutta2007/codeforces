#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1<<30;
const int N = 200111;

struct node {
    int i, j;
    ll mn, ad = 0;
    node *l, *r;
    node (ll *a, int i, int j): i(i), j(j) {
        if (j - i == 1) {
            l = r = NULL;
            mn = a[i];
        } else {
            int k = i + j >> 1;
            l = new node(a, i, k);
            r = new node(a, k, j);
            combine();
        }
    }
    inline void combine() {
        mn = min(l->mn, r->mn);
    }
    void visit() {
        if (ad) {
            mn += ad;
            if (l) l->ad += ad, r->ad += ad;
            ad = 0;
        }
    }
    void inc(int I, int J, ll a) {
        if (I <= i && j <= J) {
            ad += a;
            visit();
        } else {
            visit();
            if (!(J <= i || j <= I)) {
                l->inc(I, J, a);
                r->inc(I, J, a);
                combine();
            }
        }
    }
    int find() {
        visit();
        if (mn > 0) return INF;
        if (!l) {
            return mn == 0 ? i : INF;
        } else {
            int ans = INF;
            if (ans >= INF) ans = l->find();
            if (ans >= INF) ans = r->find();
            return ans;
        }
    }
};

ll a[N], s[N];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s[i + 1] = s[i] + a[i];
    }
    for (int i = 0; i < n; i++) {
        s[i] -= a[i];
    }
    node *t = new node(s, 0, n);
    while (q--) {
        int i; ll v;
        scanf("%d%lld", &i, &v);
        ll d = v - a[--i];
        t->inc(i, i+1, -d);
        t->inc(i+1, n, +d);
        t->visit();
        a[i] += d;
        int ans = t->find();
        printf("%d\n", ans >= INF ? -1 : ans + 1);
    }
}