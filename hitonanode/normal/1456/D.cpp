#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

// UnionFind Tree (0-indexed), based on size of each disjoint set
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

constexpr lint INF = 1e15;

lint calc_req(lint x, lint lo, lint hi) {
    if (lo > hi) return INF;
    if (x < lo) return lo - x;
    if (hi < x) return x - hi;
    return 0;
}

int main()
{
    int N;
    cin >> N;
    vector<lint> T(N + 1), X(N + 1);
    REP(i, N) cin >> T[i + 1] >> X[i + 1];

    UnionFind uf(N + 1);
    REP(i, N) {
        if (T[i + 1] - T[i] >= abs(X[i + 1] - X[i])) uf.unite(i, i + 1);
    }

    vector<lint> lo(N + 1, INF), hi(N + 1, -INF);
    vector<int> ok_just(N + 1);

    lo[0] = hi[0] = 0;
    REP(i, N) {

        {
            const lint dt = T[i + 1] - T[i];
            lint req_mv = calc_req(X[i + 1], lo[i], hi[i]);
            if (req_mv <= dt) {
                lint yo = dt - req_mv;
                chmin(lo[i + 1], X[i + 1] - yo);
                chmax(hi[i + 1], X[i + 1] + yo);
            }
            FOR(j, i + 2, N + 1) {
                lint d = calc_req(X[j], lo[i], hi[i]);
                if (d + abs(X[j] - X[i + 1]) <= dt and uf.same(i + 1, j - 1)) {
                    ok_just[j - 1] = 1;
                }
            }
        }

        if (ok_just[i] and i + 2 <= N) {
            const lint dt = T[i + 2] - T[i];
            lint req_mv = max(calc_req(X[i + 2], X[i], X[i]), T[i + 1] - T[i]);
            if (req_mv <= dt) {
                lint yo = dt - req_mv;
                chmin(lo[i + 2], X[i + 2] - yo);
                chmax(hi[i + 2], X[i + 2] + yo);
            }

            FOR(j, i + 3, N + 1) {
                lint d = calc_req(X[j], X[i], X[i]);
                if (max(d, T[i + 1] - T[i]) + abs(X[j] - X[i + 2]) <= dt and uf.same(i + 2, j - 1)) {
                    ok_just[j - 1] = 1;
                }
            }
        }
    }
    cout << (lo.back() <= hi.back() or ok_just[N - 1] ? "YES" : "NO") << '\n';
}