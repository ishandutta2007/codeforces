#include <bits/stdc++.h>
using namespace std;

#define N 1111

typedef long long ll;
#define PI 3.141592653589793238462643383279502884

struct tree {
    ll area;
    ll x, y, r;
    tree *parent;
    vector<tree*> children;
    ll s00, s01, s11;
    ll t00, t01, t11;
    tree() {
        parent = NULL;
    }
    void set(ll x, ll y, ll r) {
        this->x = x;
        this->y = y;
        this->r = r;
        area = r * r;
    }
    void try_parent(tree* t) {
        if (r < t->r) {
            double d = hypot(x - t->x, y - t->y);
            if (d < t->r) {
                if (!parent || parent->r > t->r) {
                    parent = t;
                }
            }
        }
    }
    void solve() {
        t00 = t01 = t11 = 0;
        for (tree *t: children) {
            t->solve();
            t00 += t->s00;
            t01 += t->s01;
            t11 += t->s11;
        }
        s00 = area + t01;
        s11 = -area + t01;
        s01 = max(area + t11, -area + t00);
        // printf("! %lld %lld %lld: %lld %lld %lld\n", x, y, r, s00, s01, s11);
    }
};

tree trees[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll x, y, r;
        scanf("%lld%lld%lld", &x, &y, &r);
        trees[i].set(x, y, r);
    }
    trees[n].r = 1LL<<30;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i != j) {
                trees[i].try_parent(&trees[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        trees[i].parent->children.push_back(&trees[i]);
    }
    // for (int i = 0; i < n; i++) {
    //     printf("%lld %lld %lld: %lld %lld %lld\n", trees[i].x, trees[i].y, trees[i].r,
    //         trees[i].parent->x, trees[i].parent->y, trees[i].parent->r);
    // }
    trees[n].solve();
    printf("%.11lf\n", PI * trees[n].t00);
}