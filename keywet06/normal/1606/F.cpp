#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 200005;

struct Fac {
    int64 b, a;
    Fac(int64 b, int64 a) : b(b), a(a) {}
    bool operator<(const Fac &p) const { return b * p.a < p.b * a; }
};

struct Fwk {
    int64 fen[N];
    void Update(int i, int64 x) {
        while (i <= 200000) {
            fen[i] += x;
            i += i & -i;
        }
    }
    int64 Query(int i) const {
        int64 r = 0;
        while (i) {
            r += fen[i];
            i -= i & -i;
        }
        return r;
    }
    int64 Query(int x, int y) const { return Query(y) - Query(x - 1); }
} f0, f1;

int n, q;
int St[N], Ed[N], Son[N];

vector<int> Edge[N];
vector<pair<Fac, int>> L;

void dfs(int x, int p, priority_queue<Fac> &pq) {
    static int ord = 0;
    St[x] = ++ord;
    for (int i : Edge[x]) {
        if (i == p) continue;
        ++Son[x];
        priority_queue<Fac> c;
        dfs(i, x, c);
        if (pq.size() < c.size()) swap(pq, c);
        while (!c.empty()) {
            pq.push(c.top());
            c.pop();
        }
    }
    Fac f = Fac(Son[x] - 1, 1);
    while (!pq.empty() && f < pq.top()) {
        f.b += pq.top().b;
        f.a += pq.top().a;
        L.emplace_back(pq.top(), -p);
        pq.pop();
    }
    pq.push(f);
    L.emplace_back(f, p);
    Ed[x] = ord;
}

int64 Ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        Edge[x].push_back(y);
        Edge[y].push_back(x);
    }
    priority_queue<Fac> c;
    dfs(1, 0, c);
    sort(L.begin(), L.end());
    cin >> q;
    vector<tuple<int, int, int>> Q;
    for (int i = 1; i <= q; ++i) {
        int v, k;
        cin >> v >> k;
        Q.emplace_back(k, v, i);
    }
    sort(Q.rbegin(), Q.rend());
    for (auto [k, v, i] : Q) {
        while (!L.empty() && Fac(k, 1) < L.back().first) {
            auto [f, x] = L.back();
            L.pop_back();
            if (x < 0) {
                f0.Update(St[-x], -f.b);
                f1.Update(St[-x], -f.a);
            } else if (x > 0) {
                f0.Update(St[x], f.b);
                f1.Update(St[x], f.a);
            }
        }
        Ans[i] = Son[v] + f0.Query(St[v], Ed[v]) - f1.Query(St[v], Ed[v]) * k;
    }
    for (int i = 1; i <= q; ++i) printf("%lld\n", Ans[i]);
    return 0;
}