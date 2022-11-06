#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct frac {
    ll b, a;
    frac(ll b, ll a) : b(b), a(a) {}
    bool operator<(const frac &p) const {
        return b * p.a < p.b * a;
    }
};

struct fenwick {
    ll fen[200005];
    void update(int i, ll x) {
        while (i <= 200000) {
            fen[i] += x;
            i += i & -i;
        }
    }
    ll query(int i) const {
        ll r = 0;
        while (i) {
            r += fen[i];
            i -= i & -i;
        }
        return r;
    }
    ll query(int x, int y) const {
        return query(y) - query(x - 1);
    }
} fen0, fen1;

int n, q;
vector<int> edge[200005];
int st[200005], ed[200005];
int child[200005];
vector<pair<frac, int>> L;

void dfs(int x, int p, priority_queue<frac> &pq) {
    static int ord = 0;
    st[x] = ++ord;
    for (int i : edge[x]) {
        if (i == p) continue;
        ++child[x];
        priority_queue<frac> c;
        dfs(i, x, c);
        if (pq.size() < c.size()) swap(pq, c);
        while (!c.empty()) {
            pq.push(c.top());
            c.pop();
        }
    }
    frac f = frac(child[x] - 1, 1);
    while (!pq.empty() && f < pq.top()) {
        f.b += pq.top().b;
        f.a += pq.top().a;
        L.emplace_back(pq.top(), -p);
        pq.pop();
    }
    pq.push(f);
    L.emplace_back(f, p);
    ed[x] = ord;
}

ll ans[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    priority_queue<frac> c;
    dfs(1, 0, c);
    sort(L.begin(), L.end());
    cin >> q;
    vector<tuple<int, int, int>> Q;
    for (int i = 1; i <= q; ++i)  {
        int v, k;
        cin >> v >> k;
        Q.emplace_back(k, v, i);
    }
    sort(Q.rbegin(), Q.rend());
    for (auto [k, v, i] : Q) {
        while (!L.empty() && frac(k, 1) < L.back().first) {
            auto [f, x] = L.back();
            L.pop_back();
            if (x < 0) {
                fen0.update(st[-x], -f.b);
                fen1.update(st[-x], -f.a);
            }
            else if (x > 0) {
                fen0.update(st[x], f.b);
                fen1.update(st[x], f.a);
            }
        }
        ans[i] = child[v] + fen0.query(st[v], ed[v]) - fen1.query(st[v], ed[v]) * k;
    }
    for (int i = 1; i <= q; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}