#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;
const int INF = 1000000000;

int n, q, last;
int par[MAXN], lef[MAXN], rig[MAXN], prior[MAXN], cnt[MAXN], val[MAXN], root[MAXN];

void upd (int x) {
    if (x == 0) return;
    cnt[x] = 1 + cnt[lef[x]] + cnt[rig[x]];
}

void spoji (int & t, int l, int r) {
    if (l == 0 || r == 0) {
        if (l != 0) t = l; else t = r;
    } else if (prior[l] > prior[r]) {
        spoji(rig[l], rig[l], r);
        t = l; if (rig[l]) par[rig[l]] = l;
    } else {
        spoji(lef[r], l, lef[r]);
        t = r; if (lef[r]) par[lef[r]] = r;
    }
    upd(t);
}

int climb (int t) {
    int res = 1 + cnt[lef[t]];
    while (par[t] > 0) {
        if (t == lef[par[t]]) {
            t = par[t];
        } else {
            t = par[t];
            res += 1 + cnt[lef[t]];
        }
    }
    return res;
}

void split (int t, int k, int & l, int & r, int add = 0, bool flg = 0) {
    if (t == 0) {
        l = r = 0;
        return;
    }
    int curr = (flg ? climb(t - n) : add + 1 + cnt[lef[t]]);
    if (k < curr) {
        split(lef[t], k, l, lef[t], add, flg);
        r = t; if (lef[t]) par[lef[t]] = t;
    } else {
        split(rig[t], k, rig[t], r, curr, flg);
        l = t; if (rig[t]) par[rig[t]] = t;
    }
    upd(t);
}

int kth (int t, int k) {
    if (k == cnt[lef[t]] + 1) return val[t];
    if (k <= cnt[lef[t]]) return kth(lef[t], k);
    return kth(rig[t], k - cnt[lef[t]] - 1);
}

void refresh (int & a, int & b, int & k) {
    a = (a + last - 1) % n + 1;
    b = (b + last - 1) % n + 1;
    k = (k + last - 1) % n + 1;
    if (a > b) swap(a, b);
}

void okreni (int & rt, int a, int b, bool flg, bool vrati) {
    int jen, dva, tri, cet;
    split(rt, b, tri, cet, 0, flg);
    split(tri, b - 1, dva, tri, 0, flg);
    split(dva, a - 1, jen, dva, 0, flg);
    if (vrati) {
        last = cnt[dva] + cnt[tri];
        cout << last << '\n';
        spoji(rt, jen, dva);
        spoji(rt, rt, tri);
        spoji(rt, rt, cet);
        return;
    }
    spoji(rt, jen, tri);
    spoji(rt, rt, dva);
    spoji(rt, rt, cet);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        prior[i] = prior[i + n] = uniform_int_distribution <int> (0, INF)(rng);
        cnt[i] = cnt[i + n] = 1;
        val[i] = val[i + n] = x;
        spoji(root[0], root[0], i);
        spoji(root[x], root[x], i + n);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tip, a, b, k;
        cin >> tip;
        if (tip == 1) {
            cin >> a >> b; refresh(a, b, k);
            int br = kth(root[0], b);
            okreni(root[br], a, b, 1, 0);
            okreni(root[0], a, b, 0, 0);
        } else {
            cin >> a >> b >> k; refresh(a, b, k);
            okreni(root[k], a, b, 1, 1);
        }
    }
    return 0;
}