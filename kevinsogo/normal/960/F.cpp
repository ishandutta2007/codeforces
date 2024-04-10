#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 111111;
const int E = 111111;
const ll INF = 1LL<<60;

struct segtree {
    int vi, vj;
    ll mx;
    segtree *l, *r;
    segtree(vector<int>& vals, int i, int j) {
        assert(i <= j);
        vi = vals[i];
        vj = vals[j];
        mx = -INF;
        if (i == j) {
            l = r = NULL;
        } else {
            int k = i + j >> 1;
            l = new segtree(vals, i, k);
            r = new segtree(vals, k + 1, j);
        }
    }
    ll prefmax(int w) {
        if (vj < w) {
            return mx;
        } else if (vi >= w) {
            return -INF;
        } else {
            return max(l->prefmax(w), r->prefmax(w));
        }
    }
    void push(int w, ll m) {
        if (vi <= w && w <= vj) {
            if (vi == vj) {
                mx = max(mx, m);
            } else {
                l->push(w, m);
                r->push(w, m);
                mx = max(l->mx, r->mx);
            }
        }
    }
};

struct edge {
    int a, b, w;
};

edge es[E];
set<int> vals[N];
segtree *segs[N];
int main() {
    int n, e;
    scanf("%d%d", &n, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &es[i].a, &es[i].b, &es[i].w);
        es[i].a--;
        es[i].b--;
        vals[es[i].b].insert(es[i].w);
    }

    for (int i = 0; i < n; i++) {
        vals[i].insert(0);
        vector<int> vs(vals[i].begin(), vals[i].end());
        segs[i] = new segtree(vs, 0, vs.size() - 1);
    }
    int ans = 0;
    for (int i = 0; i < e; i++) {
        int l = segs[es[i].a]->prefmax(es[i].w) + 1;
        ans = max(ans, l);
        segs[es[i].b]->push(es[i].w, l);
    }
    printf("%d\n", ans);
}