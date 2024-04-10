#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }

struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};


int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, Q, S, D;
    cin >> N >> Q >> S >> D;
    S--;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    vector<tuple<int, int, int>> kiqs;
    REP(q, Q) {
        int i, k;
        cin >> i >> k;
        i--;
        kiqs.emplace_back(k, i, q);
    }
    UnionFind uf(N);
    vector<tuple<int, int, int>> w2ij_use;

    set<pint> aset;
    REP(i, N) aset.emplace(A[i], i);
    constexpr int INF = 1e8;
    aset.emplace(-INF, -1), aset.emplace(INF, -1);

    while (uf.count(0) < N) {
        vector<int> roots(N);
        REP(i, N) roots[i] = uf.find(i);
        roots = sort_unique(roots);
        vector<vector<int>> r2id(roots.size());
        REP(i, N) r2id[arglb(roots, uf.find(i))].push_back(i);
        for (const auto &vec : r2id) {
            for (auto i : vec) aset.erase(pint(A[i], i));
            int lowest = INF / 2, arglo = -1, argloi = -1;
            for (auto i : vec) {
                for (auto tgt : {A[i] + D, A[i] - D}) {
                    auto itr = aset.lower_bound(pint(tgt, -INF));
                    if (itr != aset.end() and chmin(lowest, abs(itr->first - tgt))) arglo = itr->second, argloi = i;
                    if (itr != aset.begin()) {
                        itr--;
                        if (chmin(lowest, abs(itr->first - tgt))) arglo = itr->second, argloi = i;
                    }
                }
            }
            w2ij_use.emplace_back(lowest, arglo, argloi);
            uf.unite(arglo, argloi);
            for (auto i : vec) aset.emplace(A[i], i);
        }
    }
    w2ij_use = sort_unique(w2ij_use);

    int ne = 0;
    uf = UnionFind(N);
    vector<int> ret(Q);
    sort(kiqs.begin(), kiqs.end());
    for (auto [k, i, q] : kiqs) {
        while (ne < int(w2ij_use.size()) and get<0>(w2ij_use[ne]) <= k) {
            auto [w, i, j] = w2ij_use[ne++];
            uf.unite(i, j);
        }
        ret[q] = uf.same(i, S);
    }
    for (auto x : ret) cout << (x ? "Yes" : "No") << '\n';
}