// O((m + n) log (m + n))

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1LL<<60;

struct Line {
    ll m, b;
    ll operator()(ll x) const {
        return m * x + b;
    }
};

int compare_lines(Line& orig, Line& bago, ll x) {
    return orig(x) > bago(x) ? 0 : orig.b < bago.b ? 1 : -1;
}

struct Node {
    ll i, j;
    Line lf, rg, st; bool has = false;
    Node *l, *r;
    Node(vector<ll>& xs, int i, int j): i(xs[i]), j(xs[j]) {
        if (i == j) {
            l = r = NULL;
            lf = rg = {0LL, inf};
        } else {
            int k = i + j >> 1;
            l = new Node(xs, i, k);
            r = new Node(xs, k + 1, j);
            combine();
        }
    }

    inline void combine() {
        lf = l->lf;
        rg = r->rg;
    }

    inline void visit() {
        if (has) {
            lf = rg = st;
            if (l) {
                l->has = r->has = true;
                l->st = r->st = st;
            }
            has = false;
        }
    }

    void add_line(Line& ln) {
        visit();
        int tpl = compare_lines(lf, ln, i);
        int tpr = compare_lines(rg, ln, j);
        if (tpl == tpr) {
            if (!tpl) {
                st = ln;
                has = true;
                visit();
            }
            return;
        }

        l->add_line(ln);
        r->add_line(ln);
        combine();
    }

    ll get_min(ll x) {
        visit();
        if (!(i <= x && x <= j)) return inf;
        if (i == j) return lf(x);
        return min(l->get_min(x), r->get_min(x));
    }
};

int main() {
    ll a; int n, m;
    scanf("%lld%d%d", &a, &n, &m);
    vector<pair<ll,ll>> rains;
    rains.reserve(n);
    set<ll> xset;
    xset.insert(0);
    xset.insert(a);
    while (n--) {
        ll i, j;
        scanf("%lld%lld", &i, &j);
        rains.emplace_back(i, j);
        xset.insert(i);
        xset.insert(j);
    }
    vector<pair<ll,ll>> umbrellas;
    umbrellas.reserve(m);
    while (m--) {
        ll p, w;
        scanf("%lld%lld", &p, &w);
        umbrellas.emplace_back(p, w);
        xset.insert(p);
    }
    vector<ll> xs(xset.begin(), xset.end());
    map<ll,int> xi;
    for (int i = 0; i < xs.size(); i++) xi[xs[i]] = i;

    vector<bool> good(xs.size(), true);
    for (auto ij: rains) {
        ll i = xi[ij.first];
        ll j = xi[ij.second];
        for (int k = i; k < j; k++) good[k] = false;
    }
    vector<ll> wat(xs.size());
    for (auto pw: umbrellas) {
        ll p = xi[pw.first];
        ll w = pw.second;
        if (wat[p] == 0 || wat[p] > w) wat[p] = w;
    }
    set<ll> wset;
    for (int i = 0; i < xs.size(); i++) wset.insert(wat[i]);
    vector<ll> ws(wset.begin(), wset.end());
    Node *lines = new Node(ws, 0, ws.size() - 1);
    ll curr = inf;
    for (int p = xs.size(); p--;) {
        if (xs[p] == a) {
            curr = 0;
        } else {
            if (!good[p]) curr = inf;
            if (wat[p]) curr = min(curr, lines->get_min(wat[p]) - xs[p] * wat[p]);
        }
        Line nline = {xs[p], curr};
        lines->add_line(nline);
    }

    printf("%lld\n", curr < inf ? curr : -1);
}