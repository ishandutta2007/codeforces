#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif


using Edges = vector<vector<pint>>;
// r
vector<int> tree_distance(int N, int r, Edges &e)
{
    vector<int> res(N); // res[r] = 0;
    queue<pint> q;
    q.push(pint(r, -1)); // (now, prev)
    while(!q.empty())
    {
        pint pa = q.front(); q.pop();
        if (pa.second >= 0) res[pa.first] = res[pa.second] + 1;
        for (auto [nx, d] : e[pa.first]) if (nx != pa.second) q.push(pint(nx, pa.first));
    }
    return res;
}
//  r
pint tree_diameter(int N, int r, Edges &e)
{
    vector<int> d = tree_distance(N, r, e);
    int s = max_element(d.begin(), d.end()) - d.begin();
    d = tree_distance(N, s, e);
    int t = max_element(d.begin(), d.end()) - d.begin();
    return make_pair(s, t);
}

template <typename TDATA, typename TLAZY, typename TRET, typename TQUERY>
struct LazySegmentTree
{
    TLAZY zero_lazy;
    TRET zero_ret;
    int N;
    int head;
    std::vector<TDATA> data;
    std::vector<TLAZY> lazy;

    // Here, you have to calculate data[pos] from children (data[l], data[r]),
    // Assumptions: `lazy[pos] = lazy[l] = lazy[r] = zero_lazy`
    virtual void merge_data(int pos) = 0;

    // Here, you must propagate lazy[pos] and update data[pos] by reflecting lazy[pos], without inconsistency
    // After this, lazy[pos] must be zero_lazy.
    virtual void reflect_lazy(int pos) = 0;

    // operate d to lazy[pos] (merge two TLAZY's)
    virtual void overlap_lazy(int pos, const TLAZY &d) = 0;

    // Assumption: `lazy[pos] = zero_lazy`
    virtual TRET data2ret(int pos, const TQUERY &query) = 0;

    virtual TRET merge_ret(const TRET &l, const TRET &r, const TQUERY &query) = 0;

    ////// general description //////
    LazySegmentTree() = default;
    void initialize(const std::vector<TDATA> &data_init, const TDATA &zero_data, const TLAZY &zero_lazy_, const TRET &zero_ret_)
    {
        N = data_init.size();
        head = 1;
        while (head < N) head <<= 1;
        zero_lazy = zero_lazy_;
        zero_ret = zero_ret_;
        data.assign(head * 2, zero_data);
        lazy.assign(head * 2, zero_lazy);
        std::copy(data_init.begin(), data_init.end(), data.begin() + head);
        for (int pos = head; --pos;) merge_data(pos);
    }

    void _update(int begin, int end, const TLAZY &delay, int pos, int l, int r)
    {
        // Operate `delay` to the node pos
        // After this, lazy[pos] MUST be zero so that merge_data() works correctly
        if (begin <= l and r <= end) { // Update whole [l, r) by delay
            overlap_lazy(pos, delay);
            reflect_lazy(pos);
        }
        else if (begin < r and l < end) { // Update somewhere in [l, r)
            reflect_lazy(pos);
            _update(begin, end, delay, pos * 2, l, (l + r) / 2);
            _update(begin, end, delay, pos * 2 + 1, (l + r) / 2, r);
            merge_data(pos);
        }
        else reflect_lazy(pos);
    }

    void update(int begin, int end, const TLAZY &delay) {
        _update(begin, end, delay, 1, 0, head);
    }

    TRET _get(int begin, int end, int pos, int l, int r, const TQUERY &query) // Get value in [begin, end)
    {
        reflect_lazy(pos);
        if (begin <= l and r <= end) return data2ret(pos, query);
        else if (begin < r and l < end) {
            TRET vl = _get(begin, end, pos * 2, l, (l + r) / 2, query);
            TRET vr = _get(begin, end, pos * 2 + 1, (l + r) / 2, r, query);
            return merge_ret(vl, vr, query);
        }
        else return zero_ret;
    }
    TRET get(int begin, int end, const TQUERY &query = NULL)
    {
        return _get(begin, end, 1, 0, head, query);
    }
};


using T = int;
struct LST : public LazySegmentTree<std::pair<T, pair<T, T>>, bool, pint, std::tuple<>> {
    using TDATA = std::pair<T, pair<T, T>>;
    using TLAZY = bool;
    using TRET = pint;
    using SegTree = LazySegmentTree<TDATA, TLAZY, TRET, std::tuple<>>;
    using SegTree::data;
    using SegTree::lazy;
    void merge_data(int i) override
    {
        data[i].second.first = std::min({ data[i].first, data[i * 2].second.first, data[i * 2 + 1].second.first });
        data[i].second.second = std::max({ data[i].first, data[i * 2].second.second, data[i * 2 + 1].second.second });
    };
    void reflect_lazy(int i) override
    {
        if (lazy[i])
        {
            if (i < SegTree::head) overlap_lazy(i * 2, lazy[i]), overlap_lazy(i * 2 + 1, lazy[i]);
            data[i].first *= -1;
            swap(data[i].second.first, data[i].second.second);
            data[i].second.first *= -1;
            data[i].second.second *= -1;
        }
        lazy[i] = false;
    }
    void overlap_lazy(int i, const TLAZY &p) override { lazy[i] = lazy[i] ^ p; }
    TRET data2ret(int i, const std::tuple<> &) override { return data[i].second; }
    TRET merge_ret(const TRET &l, const TRET &r, const std::tuple<> &) override { return make_pair(min(l.first, r.first), max(l.second, r.second)); }
    void update(int l, int r, T val) { SegTree::update(l, r, val); }
    TRET get(int l, int r) { return SegTree::get(l, r, {}); }
    LST(const std::vector<T> &seq) : SegTree::LazySegmentTree()
    {
        std::vector<TDATA> vec;
        for (const auto &x : seq) vec.emplace_back(x, pint(x, x));
        int INF = 1e9;
        SegTree::initialize(vec, TDATA(0, pint(INF, -INF)), false, TRET(INF, -INF));
    }
};

vector<pint> edges;
vector<vector<pint>> to;
vector<int> query;
vector<int> solve(int N, int U)
{
    vector<int> par(N, -1);
    vector<int> dinit(N, 0);
    vector<int> depth(N, 0);

    vector<int> vin(N);
    vector<int> vout(N);
    int cur = 0;
    vector<int> cur2i(N);

    auto dfs = [&](auto&& dfs, int now, int prv, int dnow, int D) -> void {
        par[now] = prv;
        dinit[now] = dnow;
        vin[now] = cur;
        cur2i[cur] = now;
        cur++;
        depth[now] = D;
        for (auto [nxt, d] : to[now]) {
            if (nxt != prv) {
                dfs(dfs, nxt, now, dnow ^ d, D + 1);
            }
        }
        vout[now] = cur;
    };

    dfs(dfs, U, -1, 0, 0);

    vector<int> v0;
    REP(t, N) {
        int i = cur2i[t];
        v0.emplace_back(dinit[i] == 0 ? depth[i] : -depth[i]);
    }
    LST st0(v0);

    vector<int> ret;
    int nq = 0;
    for (auto e : query) {
        nq++;
        e--;
        auto [a, b] = edges[e];
        int c = a;
        if (par[b] == a) c = b;
        const int L = vin[c], R = vout[c];
        st0.update(L, R, -1);
        ret.emplace_back(st0.get(0, N).second);
    }
    return ret;
}

int main()
{
    int N;
    cin >> N;
    edges.resize(N - 1);
    to.resize(N);
    vector<int> c(N - 1);
    REP(i, N - 1)
    {
        int u, v;
        cin >> u >> v >> c[i];
        u--, v--;
        edges[i] = make_pair(u, v);
        to[u].emplace_back(v, c[i]), to[v].emplace_back(u, c[i]);
    }

    const auto [U, V] = tree_diameter(N, 0, to);
    int Q;
    cin >> Q;
    query.resize(Q);
    cin >> query;
    vector<int> solve1 = solve(N, U);
    vector<int> solve2 = solve(N, V);
    REP(q, Q) cout << max(solve1[q], solve2[q]) << '\n';
}