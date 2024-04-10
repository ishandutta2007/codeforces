#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); };
} fast_ios_;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
//
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args>
void ndarray(vector<T>& vec, const V& val, int len, Args... args)
{
    vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T& m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T>
bool chmin(T& m, const T q) { return m > q ? (m = q, true) : false; }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T>
vector<T> srtunq(vector<T> vec) { return sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()), vec; }
template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
    return for_each(begin(vec), end(vec), [&](T& v) { is >> v; }), is;
}

// output
template <typename T, typename V>
ostream& dmpseq(ostream&, const T&, const string&, const string&, const string&);
#if __cplusplus >= 201703L
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tpl)
{
    return apply([&os](auto&&... args) { ((os << args << ','), ...); }, tpl), os;
}
#endif
//
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& x) { return dmpseq<vector<T>, T>(os, x, "[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& x) { return dmpseq<deque<T>, T>(os, x, "deq[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const set<T>& x) { return dmpseq<set<T>, T>(os, x, "{", ",", "}"); }
template <typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_set<T, TH>& x) { return dmpseq<unordered_set<T, TH>, T>(os, x, "{", ",", "}"); }
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& x) { return dmpseq<multiset<T>, T>(os, x, "{", ",", "}"); }
template <typename TK, typename T>
ostream& operator<<(ostream& os, const map<TK, T>& x) { return dmpseq<map<TK, T>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename TK, typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_map<TK, T, TH>& x) { return dmpseq<unordered_map<TK, T, TH>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename T, typename V>
ostream& dmpseq(ostream& os, const T& seq, const string& pre, const string& sp, const string& suf)
{
    return os << pre, for_each(begin(seq), end(seq), [&](V x) { os << x << sp; }), os << suf;
}
template <typename T>
void print(const vector<T>& x) { dmpseq<vector<T>, T>(cout, x, "", " ", "\n"); }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif


template <class CommutativeMonoid>
class union_find_tree_foldable_undoable {
    typedef typename CommutativeMonoid::value_type value_type;
    const CommutativeMonoid mon;
    std::vector<int> data;
    std::vector<value_type> value;
    std::vector<std::tuple<int, int, value_type> > history;

public:
    union_find_tree_foldable_undoable() = default;
    union_find_tree_foldable_undoable(std::size_t size, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_), data(size, -1), value(size, mon.unit()) {
    }
    template <class InputIterator>
    union_find_tree_foldable_undoable(InputIterator first, InputIterator last, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_), data(std::distance(first, last), -1), value(first, last) {
    }

    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { while (not is_root(i)) i = data[i]; return i; }
    int get_size(int i) { return - data[find_root(i)]; }
    void unite_trees(int i, int j) {
        i = find_root(i);
        j = find_root(j);
        if (get_size(i) < get_size(j)) std::swap(i, j);
        history.emplace_back(-1, 0, mon.unit());
        if (i != j) {
            history.emplace_back(i, data[i], value[i]);
            history.emplace_back(j, data[j], value[j]);
            data[i] += data[j];
            data[j] = i;
            value[i] = mon.mult(value[i], value[j]);
        }
    }
    bool is_connected(int i, int j) { return find_root(i) == find_root(j); }

    void tree_set(int i, value_type x) {
        i = find_root(i);
        history.emplace_back(-1, 0, mon.unit());
        history.emplace_back(i, data[i], value[i]);
        value[i] = x;
    }
    value_type tree_get(int i) {
        return value[find_root(i)];
    }
    /**
     * @note for unite_trees() and tree_set()
     */
    void undo() {
        while (true) {
            assert (not history.empty());
            auto [i, data_i, value_i] = history.back();
            history.pop_back();
            if (i == -1) break;
            value[i] = value_i;
            data[i] = data_i;
        }
    }
};

template <class Key>
struct reporting_segment_tree {
    int size;
    std::vector<std::vector<Key> > data;
    reporting_segment_tree() = default;
    explicit reporting_segment_tree(int size_) {
        size = 1; while (size < size_) size *= 2;
        data.resize(2 * size - 1);
    }

    /**
     * @arg key must be unique
     * @note $O(\log n)$
     */
    void add_segment(int l, int r, const Key & key) {
        assert (0 <= l and l <= r and r <= size);
        for (l += size, r += size; l < r; l /= 2, r /= 2) {  // 1-based
            if (l % 2 == 1) data[(l ++) - 1].push_back(key);
            if (r % 2 == 1) data[(-- r) - 1].push_back(key);
        }
    }

    /**
     * @note $O(\log n + k)$
     */
    template <class Callback>
    void list_segments(int i, Callback & callback) {
        static_assert (std::is_invocable_r<void, Callback, const Key &>::value, "");
        assert (0 <= i and i < size);
        for (i += size; i > 0; i /= 2) {  // 1-based
            for (const auto & key : data[i - 1]) {
                callback(key);
            }
        }
    }

    /**
     * @note $O(n + k)$
     * @arg remove can be implemented as undo
     * @arg report is called with all indices in increasing order
     */
    template <class Add, class Remove, class Report>
    void traverse_segments(Add & add, Remove & remove, Report & report) {
        static_assert (std::is_invocable_r<void, Add, const Key &>::value, "");
        static_assert (std::is_invocable_r<void, Remove, const Key &>::value, "");
        static_assert (std::is_invocable_r<void, Report, int>::value, "");
        std::function<void (int, int, int)> dfs = [&](int i, int l, int r) {
            for (const auto & key : data[i]) {
                add(key);
            }
            if (i >= size - 1) {
                report(i - size + 1);
            } else {
                dfs(2 * i + 1, l, (l + r) / 2);
                dfs(2 * i + 2, (l + r) / 2, r);
            }
            for (auto it = data[i].rbegin(); it != data[i].rend(); ++ it) {
                remove(*it);
            }
        };
        dfs(0, 0, size);
    }
};

template <class CommutativeMonoid>
class dynamic_connectivity_offline {
    typedef typename CommutativeMonoid::value_type value_type;
    enum query_tag {
        LINK,
        ADD,
    };
    struct query_type {
        query_tag tag;
        int l, r;
        int a;
        int64_t b;
    };

    const CommutativeMonoid mon;
    int size;
    int time;
    std::vector<query_type> set_queries;
    std::vector<std::pair<int, int> > get_queries;
    std::map<std::pair<int, int>, int> current_edges;
    std::vector<std::vector<std::pair<int, value_type> > > current_values;

    void flush_time() {
        if (not get_queries.empty() and get_queries.back().first == time) {
            ++ time;
        }
    }

public:
    /**
     * @arg size is the number of vertices
     */
    dynamic_connectivity_offline(int size_, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_) {
        size = size_;
        time = 0;
        current_values.resize(size);
    }
    void link(int x, int y) {
        flush_time();
        auto edge = std::minmax({ x, y });
        assert (not current_edges.count(edge));
        current_edges[edge] = time;
    }
    void cut(int x, int y) {
        flush_time();
        auto edge = std::minmax({ x, y });
        assert (current_edges.count(edge));
        set_queries.emplace_back((query_type) {
            LINK,
            current_edges[edge],
            time,
            edge.first,
            edge.second,
        });
        current_edges.erase(edge);
    }
    void point_set(int x, value_type value) {
        flush_time();
        while (not current_values[x].empty()) {
            auto [l, value_] = current_values[x].back();
            current_values[x].pop_back();
            set_queries.emplace_back((query_type) {
                ADD,
                l,
                time,
                x,
                value_,
            });
        }
        current_values[x].emplace_back(time, value);
    }
    void point_mult(int x, value_type value) {
        flush_time();
        current_values[x].emplace_back(time, value);
    }
    void component_get(int x) {
        get_queries.emplace_back(time, x);
    }

    /**
     * @note $O(Q \log Q)$
     */
    std::vector<value_type> run() {
        std::vector<value_type> results;
        auto it = get_queries.begin();

        // close half-open queries
        int current_size = set_queries.size();
        for (auto [edge, l] : current_edges) {
            set_queries.emplace_back((query_type) {
                LINK,
                l,
                time + 1,
                edge.first,
                edge.second,
            });
        }
        REP (x, size) {
            for (auto [l, value] : current_values[x]) {
                set_queries.emplace_back((query_type) {
                    ADD,
                    l,
                    time + 1,
                    x,
                    value,
                });
            }
        }

        // prepare undoable union-find tree
        union_find_tree_foldable_undoable<CommutativeMonoid> uft(size, mon);
        auto add = [&](int i) {
            auto & q = set_queries[i];
            if (q.tag == LINK) {
                uft.unite_trees(q.a, q.b);
            } else if (q.tag == ADD) {
                uft.tree_set(q.a, mon.mult(uft.tree_get(q.a), q.b));
            } else {
                assert (false);
            }
        };
        auto remove = [&](int i) {
            uft.undo();
        };
        auto report = [&](int t) {
            for (; it != get_queries.end() and it->first == t; ++ it) {
                int x = it->second;
                results.push_back(uft.tree_get(x));
            }
        };

        // use segment trees on time-axis for queries
        reporting_segment_tree<int> segtree(time + 1);
        REP (i, set_queries.size()) {
            auto & q = set_queries[i];
            segtree.add_segment(q.l, q.r, i);
        }
        segtree.traverse_segments(add, remove, report);

        // re-open closed queries
        set_queries.resize(current_size);

        assert (it == get_queries.end());
        return results;
    }
};

struct custom_hash {
    // <https://codeforces.com/blog/entry/62393>
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <class T>
struct plus_monoid {
    typedef T value_type;
    value_type unit() const { return value_type(); }
    value_type mult(value_type a, value_type b) const { return a + b; }
};

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, null_type, custom_hash> robust_hash_table; // fast unordered_set / unordered_map

constexpr int D = 20;
int main()
{
    int N, Q, K;
    cin >> N >> Q >> K;
    dynamic_connectivity_offline<plus_monoid<int64_t>> dycon(N);
    REP(i, N) dycon.point_set(i, 1);
    unordered_map<lint, int, custom_hash> edgeinfo;

    vector<vector<lint>> ae(500001);
    // ae.reserve(500001);
    int day = 0;
    while (Q--) {
        int qtp;
        cin >> qtp;
        if (qtp == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (x > y) swap(x, y);
            lint e = ((1LL * x) << D) + y;
            if (edgeinfo.count(e) == 0 or edgeinfo[e] <= day - K) {
                dycon.link(x, y);
            }
            edgeinfo[e] = day;
            ae[day].push_back(e);
        } else if (qtp == 2) {
            int z;
            cin >> z;
            z--;
            dycon.component_get(z);
        } else {
            day++;
            if (day - K >= 0) {
                ae[day - K] = srtunq(ae[day - K]);
                for (auto e : ae[day - K]) {
                    if (edgeinfo[e] == day - K) {
                        int x = e >> D, y = e & ((1LL << D) - 1);
                        dycon.cut(x, y);
                    }
                }
                ae[day - K].clear();
            }
        }
    }
    vector<int64_t> ret = dycon.run();
    for (auto x : ret) cout << x << '\n';
}