#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind
{
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) {
        iota(par.begin(), par.end(), 0);
    }
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

void impossible()
{
    puts("IMPOSSIBLE");
    exit(0);
}

constexpr int INF = 1e9 + 10;

// StarrySkyTree: segment tree for Range Minimum Query & Range Add Query
// Complexity: O(N) (construction), O(lg N) (add / get)
template <typename Tp>
struct RangeAddRangeMax
{
    int N, head;
    Tp defaultMin;
    std::vector<Tp> range_min, range_add;
    static inline Tp f(Tp x, Tp y) noexcept
    {
        return std::max(x, y);
    }

    inline void _merge(int pos)
    {
        range_min[pos] = f(range_min[pos * 2] + range_add[pos * 2], range_min[pos * 2 + 1] + range_add[pos * 2 + 1]);
    }
    void initialize(const std::vector<Tp> &data_init, Tp default_min)
    {
        N = data_init.size(), head = 1;
        while (head < N) head <<= 1;
        defaultMin = default_min;
        range_min.assign(head * 2, defaultMin);
        range_add.assign(head * 2, 0);
        std::copy(data_init.begin(), data_init.end(), range_min.begin() + head);
        for (int pos = head; --pos;) _merge(pos);
    }
    RangeAddRangeMax() = default;
    RangeAddRangeMax(const std::vector<Tp> &data_init, Tp default_min)
    {
        initialize(data_init, default_min);
    }
    void _add(int begin, int end, int pos, int l, int r, Tp vadd) noexcept
    {
        if (r <= begin or end <= l) return;
        if (begin <= l and r <= end)
        {
            range_add[pos] += vadd;
            return;
        }
        _add(begin, end, pos * 2, l, (l + r) / 2, vadd);
        _add(begin, end, pos * 2 + 1, (l + r) / 2, r, vadd);
        _merge(pos);
    }
    // Add `vadd` to (x_begin, ..., x_{end - 1})
    void add(int begin, int end, Tp vadd) noexcept
    {
        return _add(begin, end, 1, 0, head, vadd);
    }
    Tp _get(int begin, int end, int pos, int l, int r) const noexcept
    {
        if (r <= begin or end <= l) return defaultMin;
        if (begin <= l and r <= end) return range_min[pos] + range_add[pos];
        return f(_get(begin, end, pos * 2, l, (l + r) / 2), _get(begin, end, pos * 2 + 1, (l + r) / 2, r)) + range_add[pos];
    }
    // Return f(x_begin, ..., x_{end - 1})
    Tp get(int begin, int end) const noexcept
    {
        return _get(begin, end, 1, 0, head);
    }
};

int main()
{
    int t, T;
    int N, M;
    cin >> t >> T >> N >> M;
    vector<int> L(N), R(N);
    REP(i, N)
    {
        cin >> L[i] >> R[i];
        chmin(R[i], T);
        if (L[i] > R[i]) impossible();
        R[i]++;
    }

    vector<int> zaatsu = L;
    zaatsu.insert(zaatsu.end(), R.begin(), R.end());
    zaatsu.insert(zaatsu.end(), {0, 1, t, t + 1, T - 1, T, T + 1, T + 2});

    sort(zaatsu.begin(), zaatsu.end());
    zaatsu.erase(unique(zaatsu.begin(), zaatsu.end()), zaatsu.end());

    UnionFind uf(N * 2);
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.unite(a, b + N);
        uf.unite(b, a + N);
    }
    REP(i, N)
    {
        if (uf.same(i, i + N)) impossible();
    }

    vector<pint> lr;
    vector<vector<int>> nodes;
    vector<int> belong(N, -1);

    vector<int> teki;

    {
        map<int, vector<int>> r2is;
        REP(i, N) r2is[uf.find(i)].emplace_back(i);

        int id_ = 0;
        for (auto [r, v] : r2is)
        {
            pint plr(-INF, INF);
            for (auto x : v)
            {
                belong[x] = id_;
                chmax(plr.first, L[x]);
                chmin(plr.second, R[x]);
            }
            lr.emplace_back(plr);
            nodes.emplace_back(v);

            id_++;
        }

        for (auto v : nodes)
        {
            int tmp = -1;
            int i = v[0];
            int r = uf.find(i + N);
            if (r2is.count(r))
            {
                tmp = belong[r2is[r][0]];
            }
            teki.emplace_back(tmp);
        }
    }
    // dbg(zaatsu);
    // dbg(lr);
    // dbg(nodes);
    // dbg(belong);
    // dbg(teki);

    constexpr int ADD = 1, REMOVE = 2;
    std::vector<tuple<int, int, int>> query;
    REP(i, lr.size())
    {
        query.emplace_back(lr[i].first, i, ADD);
        query.emplace_back(lr[i].second, i, REMOVE);
    }
    query.emplace_back(0, -1, 0);
    query.emplace_back(1, -1, 0);
    query.emplace_back(T - 1, -1, 0);
    query.emplace_back(T, -1, 0);

    sort(query.begin(), query.end());

    RangeAddRangeMax<int> sst;
    sst.initialize(vector<int>(zaatsu.size()), 0);

    vector<pint> zlr = lr;
    for (auto &p : zlr)
    {
        p.first = lower_bound(zaatsu.begin(), zaatsu.end(), p.first) - zaatsu.begin();
        p.second = lower_bound(zaatsu.begin(), zaatsu.end(), p.second) - zaatsu.begin();
    }

    REP(i, lr.size())
    {
        if (teki[i] == -1)
        {
            sst.add(zlr[i].first, zlr[i].second, 1);
        }
    }

    int K = lr.size();
    vector<int> own(K);

    int it = 0, itmax = 0;
    for (auto x : teki) itmax += (x >= 0);
    itmax /= 2;

    int kari = 0;

    vector<int> xxxx;
    for (auto [x, i, TYPE] : query)
    {
        xxxx.emplace_back(x);
    }
    xxxx.emplace_back(T + 1);
    sort(xxxx.begin(), xxxx.end());
    xxxx.erase(unique(xxxx.begin(), xxxx.end()), xxxx.end());

    REP(iq, query.size())
    {
        auto [x, i, TYPE] = query[iq];
        int xnxt = *upper_bound(xxxx.begin(), xxxx.end(), x);
        if (TYPE == ADD)
        {
            own[i] = 1;
            if (teki[i] == -1)
            {
                sst.add(zlr[i].first, zlr[i].second, -1);
                kari++;
            }
            else
            {
                int j = teki[i];
                if (own[j])
                {
                    sst.add(zlr[j].first, zlr[i].first, 1);
                    if (lr[i].second >= lr[j].second)
                    {
                    }
                    else
                    {
                        sst.add(zlr[i].second, zlr[j].second, 1);
                    }
                }
                else
                {
                    sst.add(zlr[j].first, zlr[j].second, 1);
                    it++;
                }
            }
        }
        if (TYPE == REMOVE)
        {
            own[i] = 0;
            if (teki[i] == -1)
            {
                sst.add(zlr[i].first, zlr[i].second, 1);
                kari--;
            }
            else
            {
                int j = teki[i];
                if (own[j])
                {
                    sst.add(zlr[i].second, zlr[j].second, -1);
                    if (lr[i].first <= lr[j].first)
                    {
                    }
                    else
                    {
                        sst.add(zlr[j].first, zlr[i].first, -1);
                    }
                }
                else
                {
                    sst.add(zlr[j].first, zlr[j].second, -1);
                }
            }
        }

        if (it == itmax)
        {
            int xh = xnxt - 1;
            int ylo = max(t - xh, 0);
            int yhi = max(T - x, 0);
            int zl = upper_bound(zaatsu.begin(), zaatsu.end(), ylo) - zaatsu.begin() - 1;
            chmax(zl, 0);
            int zr = upper_bound(zaatsu.begin(), zaatsu.end(), yhi) - zaatsu.begin();

            int tmp = sst.get(zl, zr);
            // dbg((vector<int>{x, zl, zr, xh, ylo, yhi, K, tmp, kari, it}));
            if (K == tmp + kari + it)
            {
                cout << "POSSIBLE\n";
                while (zr - zl > 1)
                {
                    int c = (zr + zl) / 2;
                    if (sst.get(zl, c) == tmp) zr = c;
                    else zl = c;
                }

                pint xrange1(x, xh); // []
                pint xrange2(zaatsu[zl], zaatsu[zl + 1] - 1);  // []
                lint t1 = x, t2 = zaatsu[zl];
                // dbg(t1);
                // dbg(t2);
                // dbg(xrange1);
                if (t1 + t2 < t)
                {
                    lint req = t - t1 - t2;
                    // dbg(req);

                    lint add1 = min<lint>(xh - x, req);
                    req -= add1;
                    t1 += add1;
                    t2 += req;
                }
                cout << t1 << ' ' << t2 << '\n';
                string ret(N, '0');
                REP(i, lr.size())
                {
                    if (teki[i] == -1)
                    {
                        if (lr[i].first <= t1 and t1 < lr[i].second) for (auto x : nodes[i]) ret[x] = '1';
                        else for (auto x : nodes[i]) ret[x] = '2';
                    }
                    else
                    {
                        int j = teki[i];
                        if (lr[i].first <= t1 and t1 < lr[i].second and lr[j].first <= t2 and t2 < lr[j].second)
                        {
                            for (auto x : nodes[i]) ret[x] = '1';
                            for (auto x : nodes[j]) ret[x] = '2';
                        }
                        else
                        {
                            for (auto x : nodes[i]) ret[x] = '2';
                            for (auto x : nodes[j]) ret[x] = '1';
                        }
                        
                    }
                }
                cout << ret << '\n';
                return 0;
            }
        }
    }
    impossible();
}