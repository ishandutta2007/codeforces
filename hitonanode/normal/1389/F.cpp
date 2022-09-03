#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template <typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template <typename V, typename T> void ndfill(V &x, const T &val) { x = val; }
template <typename V, typename T> void ndfill(vector<V> &vec, const T &val) { for (auto &v : vec) ndfill(v, val); }
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif


// StarrySkyTree: segment tree for Range Minimum Query & Range Add Query
// Complexity: O(N) (construction), O(lg N) (add / get)
template <typename Tp>
struct RangeAddRangeMin
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
    RangeAddRangeMin() = default;
    RangeAddRangeMin(const std::vector<Tp> &data_init, Tp default_min)
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
    void update(int pos, Tp val) noexcept
    {
        Tp vold = get(pos, pos + 1);
        if (val > vold) add(pos, pos + 1, val - vold);
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> L(N), R(N), T(N);
    REP(i, N) cin >> L[i] >> R[i] >> T[i];
    REP(i, N) R[i]++;
    vector<int> Z = L;
    Z.insert(Z.end(), R.begin(), R.end());
    Z.emplace_back(-1);
    Z.emplace_back(1e9 + 5);
    Z.emplace_back(1e9 + 10);
    Z = srtunq(Z);

    vector<vector<pint>> l2rc(Z.size());
    REP(i, N)
    {
        int l = lower_bound(ALL(Z), L[i]) - Z.begin();
        int r = lower_bound(ALL(Z), R[i]) - Z.begin();
        l2rc[l].emplace_back(r, T[i]);
    }
    RangeAddRangeMin<int> sst1(vector<int>(Z.size(), 0), 0);
    RangeAddRangeMin<int> sst2(vector<int>(Z.size(), 0), 0);

    dbg(Z);
    vector<pint> pu1, pu2;
    vector<int> padd1, padd2;
    dbg(l2rc);

    for (auto &vec : l2rc) sort(vec.begin(), vec.end());

    REP(l, l2rc.size())
    {
        int t1 = sst1.get(0, l + 1), t2 = sst2.get(0, l + 1);
        int t = max(t1, t2);

        int upd1 = 0;
        int upd2 = 0;

        for (auto [r, c] : l2rc[l])
        {
            if (c == 1)
            {
                // sst1.add(r, Z.size(), 1);
                padd1.emplace_back(r);
                upd1++;
                pu1.emplace_back(r, upd1 + max(t, sst1.get(0, r)));
            }

            if (c == 2)
            {
                // sst2.add(r, Z.size(), 1);
                padd2.emplace_back(r);
                upd2++;
                pu2.emplace_back(r, upd2 + max(t, sst2.get(0, r)));
            }
        }
        for (auto r : padd1) sst1.add(r, Z.size(), 1);
        for (auto r : padd2) sst2.add(r, Z.size(), 1);
        padd1.clear();
        padd2.clear();
        for (auto [r, upd] : pu1) sst1.update(r, upd);
        for (auto [r, upd] : pu2) sst2.update(r, upd);
        pu1.clear();
        pu2.clear();
        dbg((vector<int>{l, t1, t2, upd1, upd2}));
    }
    cout << max(sst1.get(0, Z.size()), sst2.get(0, Z.size())) << '\n';
}