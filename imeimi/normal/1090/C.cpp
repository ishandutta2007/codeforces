#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n, m;
set<int> S[100001];
int need[100001];

int nC[100001];
int oC[100001];

int nSeg[1 << 18];
void update(int i, int s, int e, int x, int v) {
    nSeg[i] += v;
    if (s == e) return;
    int m = (s + e) / 2;
    if (x <= m) update(i << 1, s, m, x, v);
    else update(i << 1 | 1, m + 1, e, x, v);
}

struct segtree {
    struct node {
        node * l, * r;
        int cnt;
        node() : l(0), r(0), cnt(0) {}
    } * rt;
    segtree() : rt(0) {}
    void update(node * &p, int s, int e, int x, int v) {
        if (p == 0) p = new node();
        p->cnt += v;
        if (s == e) return;
        int m = (s + e) / 2;
        if (x <= m) update(p->l, s, m, x, v);
        else update(p->r, m + 1, e, x, v);
    }
    void insert(int x) {
        update(rt, 1, n, x, 1);
    }
    void erase(int x) {
        update(rt, 1, n, x, -1);
    }
    int get(node * &p, int i, int s, int e) {
        if (p == 0) p = new node();
        if (p->cnt == nSeg[i]) return -1;
        p->cnt += 1;
        if (s == e) return s;
        int m = (s + e) / 2;
        int ret = get(p->l, i << 1, s, m);
        if (ret != -1) return ret;
        return get(p->r, i << 1 | 1, m + 1, e);
    }
    int get() {
        return get(rt, 1, 1, n);
    }
} ncontain[100001];
set<int> contain[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int C = 0;
    for (int i = 1; i <= n; ++i) {
        int s;
        cin >> s;
        C += s;
        while (s--) {
            int x;
            cin >> x;
            S[i].insert(x);
        }
    }
    int D = (C + n - 1) / n;
    int R = D * n - C;
    vector<int> ord;
    for (int i = 1; i <= n; ++i) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return S[i].size() < S[j].size(); });
    for (int i = 0; i < n; ++i) {
        if (i < R) need[ord[i]] = D - 1;
        else need[ord[i]] = D;
    }
    for (int i = 1; i <= n; ++i) {
        if (S[i].size() < need[i]) update(1, 1, n, i, 1);
        for (int j : S[i]) {
            if (S[i].size() < need[i]) ++nC[j], ncontain[j].insert(i);
            if (S[i].size() > need[i]) ++oC[j], contain[j].insert(i);
        }
    }
    vector<int> can;
    for (int i = 1; i <= m; ++i) if (nC[i] < nSeg[1] && oC[i] > 0) can.push_back(i);
    vector<pair<pii, int>> ans;
    while (!can.empty()) {
        int x = can.back();
        can.pop_back();
        if (nC[x] == nSeg[1] || oC[x] == 0) continue;
        int from = *contain[x].begin(); contain[x].erase(contain[x].begin());
        int to = ncontain[x].get();
        ans.emplace_back(pii(from, to), x);
        S[from].erase(x);
        S[to].insert(x);
        ++nC[x]; --oC[x];
        if (S[from].size() == need[from]) {
            for (int i : S[from]) {
                --oC[i];
                contain[i].erase(from);
            }
        }
        if (S[to].size() == need[to]) {
            update(1, 1, n, to, -1);
            for (int i : S[to]) {
                --nC[i];
                ncontain[i].erase(to);
            }
        }
        if (nC[x] < nSeg[1] && oC[x] > 0) can.push_back(x);
    }
    printf("%u\n", ans.size());
    for (auto i : ans) {
        printf("%d %d %d\n", i.first.first, i.first.second, i.second);
    }
    return 0;
}