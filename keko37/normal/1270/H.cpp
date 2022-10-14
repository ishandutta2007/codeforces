#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 1000005;
const int BIG = 1000000000;
const llint INF = 1000000000000000000LL;
const int LIM = 1e6+1;

int n, q;
llint a[MAXN], prop[MAXN * 2];
pi t[MAXN * 2];

pi spoji (pi a, pi b) {
    if (a.first < b.first) return a;
    if (a.first > b.first) return b;
    return {a.first, a.second + b.second};
}

void init () {
    for (int i = 0; i < LIM; i++) t[i + LIM] = {BIG, 1};
    for (int i = 1; i <= n; i++) t[a[i] + LIM] = {0, 1};
    for (int i = LIM - 1; i >= 1; i--) t[i] = spoji(t[i<<1], t[i<<1|1]);
}

void build (int p) {
    while (p > 1) p >>= 1, t[p] = spoji(t[p<<1], t[p<<1|1]), t[p].first += prop[p];
}

void upd (int l, int r, int value) {
    l += LIM; r += LIM;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) t[l].first += value, prop[l] += value, l++;
        if (r & 1) r--, t[r].first += value, prop[r] += value;
    }
    build(l0);
    if (r0 - 1 != l0) build(r0 - 1);
}

void two (int pos, int d) {
    int lo = min(a[pos], a[pos + 1]);
    int hi = max(a[pos], a[pos + 1]);
    upd(lo, hi, d);
}

void update (int pos, int x) {
    two(pos - 1, -1); two(pos, -1);
    upd(a[pos], a[pos] + 1, BIG);
    a[pos] = x;
    upd(a[pos], a[pos] + 1, -BIG);
    two(pos - 1, 1); two(pos, 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    a[0] = LIM;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init();
    for (int i = 0; i <= n; i++) {
        two(i, 1);
    }
    for (int i = 0; i < q; i++) {
        int pos, x;
        cin >> pos >> x;
        update(pos, x);
        if (t[1].first > 1) cout << "0\n"; else cout << t[1].second << '\n';
    }
    return 0;
}