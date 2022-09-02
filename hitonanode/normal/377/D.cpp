#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

// StarrySkyTree: segment tree for Range Minimum Query & Range Add Query
// Complexity: (N)$ (construction), (\log N)$ (add / get / prod)
// - RangeAddRangeMin(std::vector<Tp> data_init) : Initialize array x by data_init.
// - add(int begin, int end, Tp vadd) : Update x[i] <- x[i] + vadd for all begin <= i < end.
// - get(int pos) : Get x[pos].
// - prod(int begin, int end) : Get min(x[begin], ..., x[end - 1]).
template <typename Tp, Tp defaultT = std::numeric_limits<Tp>::max() / 2> struct RangeAddRangeMin {
    int N, head;
    std::vector<Tp> range_min, range_add;
    static inline Tp f(Tp x, Tp y) noexcept { return std::max(x, y); }

    inline void _merge(int pos) {
        range_min[pos] = f(range_min[pos * 2] + range_add[pos * 2], range_min[pos * 2 + 1] + range_add[pos * 2 + 1]);
    }
    void initialize(const std::vector<Tp> &data_init) {
        N = data_init.size(), head = 1;
        while (head < N) head <<= 1;
        range_min.assign(head * 2, defaultT);
        range_add.assign(head * 2, 0);
        std::copy(data_init.begin(), data_init.end(), range_min.begin() + head);
        for (int pos = head; --pos;) _merge(pos);
    }
    RangeAddRangeMin() = default;
    RangeAddRangeMin(const std::vector<Tp> &data_init) { initialize(data_init); }
    void _add(int begin, int end, int pos, int l, int r, Tp vadd) noexcept {
        if (r <= begin or end <= l) return;
        if (begin <= l and r <= end) {
            range_add[pos] += vadd;
            return;
        }
        _add(begin, end, pos * 2, l, (l + r) / 2, vadd);
        _add(begin, end, pos * 2 + 1, (l + r) / 2, r, vadd);
        _merge(pos);
    }
    // Add `vadd` to (x_begin, ..., x_{end - 1})
    void add(int begin, int end, Tp vadd) noexcept { return _add(begin, end, 1, 0, head, vadd); }
    Tp _get(int begin, int end, int pos, int l, int r) const noexcept {
        if (r <= begin or end <= l) return defaultT;
        if (begin <= l and r <= end) return range_min[pos] + range_add[pos];
        return f(_get(begin, end, pos * 2, l, (l + r) / 2), _get(begin, end, pos * 2 + 1, (l + r) / 2, r)) + range_add[pos];
    }
    // Return f(x_begin, ..., x_{end - 1})
    Tp get(int pos) const noexcept { return prod(pos, pos + 1); }
    Tp prod(int begin, int end) const noexcept { return _get(begin, end, 1, 0, head); }
};


int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> L(N), V(N), R(N);
    int maxi = 0;
    REP(i, N) cin >> L[i] >> V[i] >> R[i], maxi = max({maxi, L[i], V[i], R[i]});
    maxi += 3;
    vector<vector<int>> lv2q(maxi);
    constexpr int INF = 1 << 30;
    REP(i, N) lv2q[L[i]].push_back(i), lv2q[V[i] + 1].push_back(-INF + i);

    lint ret = 0, retr = -1, retl = -1;

    vector<lint> stinit(maxi);
    iota(stinit.begin(), stinit.end(), 0);

    constexpr lint B = 1 << 20;
    RangeAddRangeMin<lint, -B * B> seg(stinit);

    REP(l, lv2q.size()) {
        auto qs = lv2q[l];
        if (qs.empty()) continue;
        for (auto q : qs) {
            if (q >= 0) {
                seg.add(V[q], stinit.size(), B);
                seg.add(R[q] + 1, stinit.size(), -B);
            } else {
                q += INF;
                seg.add(V[q], stinit.size(), -B);
                seg.add(R[q] + 1, stinit.size(), B);
            }
        }
        auto val = seg.prod(0, stinit.size());
        if (ret < val) ret = val, retl = l, retr = ret % B;
    }

    vector<int> retseq;
    REP(q, N) {
        if (L[q] <= retl and V[q] >= retl and V[q] <= retr and R[q] >= retr) retseq.emplace_back(q);
    }
    cout << retseq.size() << '\n';
    for (auto q : retseq) cout << q + 1 << ' ';
    cout << '\n';
}