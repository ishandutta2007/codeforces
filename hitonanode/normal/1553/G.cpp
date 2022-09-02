#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

struct Sieve {
    std::vector<int> minfactor;
    std::vector<int> primes;
    Sieve(int maxN) : minfactor(maxN + 1) {
        for (int d = 2; d <= maxN; d++) {
            if (!minfactor[d]) {
                minfactor[d] = d;
                primes.emplace_back(d);
            }
            for (const auto &p : primes) {
                if (p > minfactor[d] or d * p > maxN) break;
                minfactor[d * p] = p;
            }
        }
    }

    std::vector<int> prime_factors(int x) {
        std::vector<int> ret;
        while (x > 1) {
            ret.push_back(minfactor[x]);
            x /= minfactor[x];
        }
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};
Sieve sieve(1010101);

struct UndoUnionFind {
    using pint = std::pair<int, int>;
    std::vector<int> par, cou;
    std::stack<std::pair<int, pint>> history;
    UndoUnionFind(int N) : par(N), cou(N, 1) { std::iota(par.begin(), par.end(), 0); }
    int find(int x) const { return (par[x] == x) ? x : find(par[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (cou[x] < cou[y]) std::swap(x, y);
        history.emplace(y, pint(par[y], cou[x]));
        return x != y ? par[y] = x, cou[x] += cou[y], true : false;
    }
    void undo() {
        cou[par[history.top().first]] = history.top().second.second;
        par[history.top().first] = history.top().second.first;
        history.pop();
    }
    void reset() {
        while (!history.empty()) undo();
    }
    int count(int x) const { return cou[find(x)]; }
    bool same(int x, int y) const { return find(x) == find(y); }
};


int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    vector<vector<int>> pfs, pfsaug;
    pfs.reserve(N), pfsaug.reserve(N);
    for (auto a : A) {
        pfs.emplace_back(sieve.prime_factors(a));
        pfsaug.emplace_back(sieve.prime_factors(a + 1));
    }

    vector<int> primes;
    for (auto ps : pfs) for (auto p : ps) primes.push_back(p);
    for (auto ps : pfsaug) for (auto p : ps) primes.push_back(p);
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    const int K = primes.size();

    vector<int> p2id(1010101, -1);
    for (int k = 0; k < K; k++) p2id[primes[k]] = N + k;

    UndoUnionFind uf(N + K);
    for (int i = 0; i < N; i++) {
        for (auto p : pfs[i]) {
            uf.unite(i, p2id[p]);
        }
    }
    vector<int> roots;
    for (int i = 0; i < N + K; i++) roots.push_back(uf.find(i));
    sort(roots.begin(), roots.end());
    roots.erase(unique(roots.begin(), roots.end()), roots.end());

    vector<vector<int>> edges;
    vector<vector<int>> r2e(N + K);
    for (int i = 0; i < N; i++) {
        vector<int> vs;
        for (auto p : pfs[i]) vs.push_back(uf.find(p2id[p]));
        for (auto p : pfsaug[i]) vs.push_back(uf.find(p2id[p]));
        sort(vs.begin(), vs.end());
        edges.push_back(vs);
        for (auto r : vs) r2e[r].push_back(i);
    }

    vector<int> ret(Q, 2);
    vector<vector<pair<int, int>>> r2q(N + K);

    for (int q = 0; q < Q; q++) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        s = uf.find(s), t = uf.find(t);
        if (s == t) {
            ret[q] = 0;
        } else {
            r2q[t].emplace_back(q, s);
        }
    }

    for (auto r : roots) {
        for (auto eid : r2e[r]) {
            for (auto x : edges[eid]) uf.unite(r, x);
        }
        for (auto [q, s] : r2q[r]) {
            if (uf.same(s, r)) ret[q] = 1;
        }
        for (auto eid : r2e[r]) {
            for (auto x : edges[eid]) uf.undo();
        }
    }

    for (auto x : ret) cout << x << '\n';
}