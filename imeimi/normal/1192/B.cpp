#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;
typedef pair<llong, llong> pll;

int n, q;
llong w;
int A[100000], B[100000];
llong C[100000];
vector<int> edge[100001];

int st[100001];
int ed[100001];
llong dist[100001];
vector<int> ord;
void dfs(int x, int p) {
    ord.push_back(x);
    st[x] = ord.size();
    for (int it : edge[x]) {
        if (it == p) continue;
        int i = x ^ A[it] ^ B[it];
        dist[i] = dist[x] + C[it];
        dfs(i, it);
        ord.push_back(x);
    }
    ed[x] = ord.size();
}

struct node {
    llong L, M, LM, MR, LMR, add;
    void init(llong v) {
        L = v;
        M = -(v + v);
        LM = -v;
        MR = -v;
        LMR = 0;
        add = 0;
    }
    void addv(llong v) {
        L += v;
        M -= v + v;
        LM -= v;
        MR -= v;
        add += v;
    }
    node operator+(const node &p) const {
        node ret;
        ret.L = max(L, p.L);
        ret.M = max(M, p.M);
        ret.LM = max({ LM, p.LM, L + p.M });
        ret.MR = max({ MR, p.MR, M + p.L });
        ret.LMR = max({ LMR, p.LMR, LM + p.L, L + p.MR });
        ret.add = 0;
        return ret;
    }
} seg[1 << 19];

void init(int i, int s, int e) {
    if (s == e) {
        seg[i].init(dist[ord[s - 1]]);
        return;
    }
    int m = (s + e) / 2;
    init(i << 1, s, m);
    init(i << 1 | 1, m + 1, e);
    seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

void update(int i, int s, int e, int x, int y, llong v) {
    if (e < x || y < s) return;
    if (x <= s && e <= y) {
        seg[i].addv(v);
        return;
    }
    seg[i << 1].addv(seg[i].add);
    seg[i << 1 | 1].addv(seg[i].add);
    seg[i].add = 0;
    int m = (s + e) / 2;
    update(i << 1, s, m, x, y, v);
    update(i << 1 | 1, m + 1, e, x, y, v);
    seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q >> w;
    for (int i = 0; i < n - 1; ++i) {
        cin >> A[i] >> B[i] >> C[i];
        edge[A[i]].push_back(i);
        edge[B[i]].push_back(i);
    }
    dfs(1, -1);
    init(1, 1, ord.size());
    llong last = 0;
    while (q--) {
        llong d, e;
        cin >> d >> e;
        d = (d + last) % (n - 1);
        e = (e + last) % w;
        llong dv = e - C[d];
        C[d] = e;
        int x = A[d], y = B[d];
        if (st[x] < st[y]) swap(x, y);
        update(1, 1, ord.size(), st[x], ed[x], dv);
        last = seg[1].LMR;
        printf("%lld\n", last);
    }
    return 0;
}