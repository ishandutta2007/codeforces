#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) (x)
#define dbgif(cond, x) 0
#endif

vector<int> pending_ids;

template <class S, class F, S (*op)(S, S), S (*reversal)(S), S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
class lazy_linkcuttree {
public:
    struct Node {
        Node *l, *r, *p;
        S d, sum;
        F lz;
        bool is_reversed;
        int sz;
        Node(S val)
            : l(nullptr), r(nullptr), p(nullptr), d(val), sum(val), lz(id()), is_reversed(false), sz(1) {}
        bool is_root() const { return !p || (p->l != this and p->r != this); }
        template <class OStream> friend OStream &operator<<(OStream &os, const Node &n) {
            os << '[';
            if (n.l) os << *(n.l) << ',';
            os << n.d << ',';
            if (n.r) os << *(n.r);
            return os << ']';
        }
    };

protected:
    void update(Node *t) {
        if (t == nullptr) return;
        t->sz = 1;
        t->sum = t->d;
        if (t->l) {
            t->sz += t->l->sz;
            t->sum = op(t->l->sum, t->sum);
        }
        if (t->r) {
            t->sz += t->r->sz;
            t->sum = op(t->sum, t->r->sum);
        }
    }
    void all_apply(Node *a, F b) {
        a->d = mapping(b, a->d);
        a->sum = mapping(b, a->sum);
        a->lz = composition(b, a->lz);
    }
    void _toggle(Node *t) {
        auto tmp = t->l;
        t->l = t->r, t->r = tmp;
        t->sum = reversal(t->sum);
        t->is_reversed ^= true;
    }

    void push(Node *&t) {
        if (t->lz != id()) {
            if (t->l) all_apply(t->l, t->lz);
            if (t->r) all_apply(t->r, t->lz);
            t->lz = id();
        }
        if (t->is_reversed) {
            if (t->l) _toggle(t->l);
            if (t->r) _toggle(t->r);
            t->is_reversed = false;
        }
    }

    void _rot_r(Node *t) {
        Node *x = t->p, *y = x->p;
        if ((x->l = t->r)) t->r->p = x;
        t->r = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
            update(y);
        }
    }
    void _rot_l(Node *t) {
        Node *x = t->p, *y = x->p;
        if ((x->r = t->l)) t->l->p = x;
        t->l = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
            update(y);
        }
    }

    void _splay(Node *t) {
        push(t);
        while (!t->is_root()) {
            Node *q = t->p;
            if (q->is_root()) {
                push(q), push(t);
                if (q->l == t)
                    _rot_r(t);
                else
                    _rot_l(t);
            } else {
                Node *r = q->p;
                push(r), push(q), push(t);
                if (r->l == q) {
                    if (q->l == t)
                        _rot_r(q), _rot_r(t);
                    else
                        _rot_l(t), _rot_r(t);
                } else {
                    if (q->r == t)
                        _rot_l(q), _rot_l(t);
                    else
                        _rot_r(t), _rot_l(t);
                }
            }
        }
    }

public:
    [[nodiscard]] Node *make_node(S val) { return new Node(val); }

    void evert(Node *t) { expose(t), _toggle(t), push(t); }

    Node *expose(Node *t) {
        Node *rp = nullptr;
        for (Node *cur = t; cur; cur = cur->p) {
            pending_ids.push_back(cur->d.id_);
            _splay(cur);
            cur->r = rp;
            update(cur);
            rp = cur;
        }
        _splay(t);
        return rp;
    }

    void link(Node *chi, Node *par) {
        evert(chi);
        expose(par);
        chi->p = par;
        par->r = chi;
        update(par);
    }

    void cut(Node *chi) {
        expose(chi);
        Node *par = chi->l;
        chi->l = nullptr;
        update(chi);
        par->p = nullptr;
    }

    void cut(Node *u, Node *v) { evert(u), cut(v); }

    Node *lca(Node *u, Node *v) { return expose(u), expose(v); }

    void set(Node *t, S x) { expose(t), t->d = x, update(t); }

    S get(Node *t) { return expose(t), t->d; }

    void apply(Node *u, Node *v, const F &x) {
        evert(u);
        expose(v);
        all_apply(v, x);
        push(v);
    }

    S prod(Node *u, Node *v) {
        evert(u);
        expose(v);
        return v->sum;
    }

    Node *kth_parent(Node *t, int k) {
        expose(t);
        while (t) {
            push(t);
            if (t->r and t->r->sz > k) {
                t = t->r;
            } else {
                if (t->r) k -= t->r->sz;
                if (k == 0) return t;
                k--;
                t = t->l;
            }
        }
        return nullptr;
    }

    bool is_connected(Node *u, Node *v) {
        expose(u), expose(v);
        return u == v or u->p;
    }
};


// Add/erase ranges on \mathbb{Z}
// Basic implementation idea: https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
template <typename Int> struct integer_segments {
    const Int INVALID = -1;
    Int _sz;
    std::map<Int, Int> mp;
    integer_segments() : _sz(0) {}

    // Get the range [l, r] that satisfies l <= x <= r, or [INVALID, INVALID] otherwise
    std::pair<Int, Int> get(Int x) const {
        auto itr = mp.upper_bound(x);
        if (itr == mp.begin() or (--itr)->second < x) return std::make_pair(INVALID, INVALID);
        return *itr;
    }

    bool contains(Int x) const { return lower_bound(x) == x; }

    // Find the min. y in the set that satisfies x <= y
    Int lower_bound(Int x) const {
        auto itr = mp.upper_bound(x);
        if (itr != mp.begin() and std::prev(itr)->second >= x) return x;
        if (itr != mp.end()) return itr->first;
        return INVALID;
    }

    // Find the max. y in the set that satisfies y <= x
    Int inv_lower_bound(Int x) const {
        auto itr = mp.upper_bound(x);
        if (itr == mp.begin()) return INVALID;
        if ((--itr)->second >= x) return x;
        return itr->second;
    }

    void _mp_upd(Int l, Int r) {
        if (mp.count(l)) _sz -= mp[l] - l + 1;
        mp[l] = r, _sz += r - l + 1;
    }

    // Add {l, l + 1, ..., r} and return the merged segment which [l, r] belongs to
    std::pair<Int, Int> insert(Int l, Int r) {
        auto itl = mp.upper_bound(l), itr = mp.upper_bound(r + 1);
        if (itl != mp.begin() and (--itl)->second < l - 1) { ++itl; }
        if (itl != itr) {
            l = std::min(l, itl->first), r = std::max(r, std::prev(itr)->second);
            for (auto i = itl; i != itr; i++) _sz -= i->second - i->first + 1;
            mp.erase(itl, itr);
        }
        if (mp.count(l)) _sz -= mp[l] - l + 1;
        _mp_upd(l, r);
        return std::make_pair(l, r);
    }

    // Remove {l, l + 1, ..., r}
    void remove(Int l, Int r) {
        auto itl = mp.upper_bound(l), itr = mp.upper_bound(r);
        if (itl != mp.begin() and (--itl)->second < l) { ++itl; }
        if (itl == itr) { return; }
        Int tl = std::min(l, itl->first), tr = std::max(r, std::prev(itr)->second);
        for (auto i = itl; i != itr; i++) _sz -= i->second - i->first + 1;
        mp.erase(itl, itr);
        if (tl < l) _mp_upd(tl, l - 1);
        if (r < tr) _mp_upd(r + 1, tr);
    }

    Int count() const { return _sz; }

    // O((# of segments))
    Int find_by_order(Int k) const {
        if (mp.empty()) return -1;
        Int hi = mp.begin()->first - 1;
        for (const auto &p : mp) {
            const Int l = p.first, r = p.second;
            hi = std::max(hi, l - 1);
            Int add = std::max(Int(0), r - hi);
            if (add >= k + 1) return hi + k + 1;
            k -= add;
            hi = std::max(hi, r);
        }
        return -1;
    }

    // Count elements strictly less than x, O((# of segments))
    Int order_of_key(Int x) const {
        Int ret = 0;
        for (auto p : x) {
            if (p.first >= x) break;
            ret += std::min(x - 1, p.second) - p.first + 1;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const integer_segments &x) {
        os << '{';
        for (auto &&p : x.mp) os << '[' << p.first << ',' << p.second << "],";
        return os << '}';
    }
};


constexpr lint INF = 1LL << 60;
struct S {
    int id_;
    lint last_departure;
};
S op(S l, S r) { return l; }
S reversal(S x) { return x; }
using F = lint;
S mapping(F f, S x) {
    chmax(x.last_departure, f);
    return x;
}
F composition(F f, F g) { return max(f, g); }
F id() { return -INF; }
using LCT = lazy_linkcuttree<S, F, op, reversal, mapping, composition, id>;

template <typename T, T INF = std::numeric_limits<T>::max() / 2, int INVALID = -1> struct ShortestPath {
    int V, E;
    bool single_positive_weight;
    T wmin, wmax;
    std::vector<std::vector<std::pair<int, T>>> to;

    ShortestPath(int V = 0) : V(V), E(0), single_positive_weight(true), wmin(0), wmax(0), to(V) {}
    void add_edge(int s, int t, T w) {
        assert(0 <= s and s < V);
        assert(0 <= t and t < V);
        to[s].emplace_back(t, w);
        E++;
        if (w > 0 and wmax > 0 and wmax != w) single_positive_weight = false;
        wmin = std::min(wmin, w);
        wmax = std::max(wmax, w);
    }

    std::vector<T> dist;
    std::vector<int> prev;

    // Dijkstra algorithm
    // Complexity: O(E log E)
    void Dijkstra(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        dist[s] = 0;
        prev.assign(V, INVALID);
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            T d;
            int v;
            std::tie(d, v) = pq.top();
            pq.pop();
            if (dist[v] < d) continue;
            for (auto nx : to[v]) {
                T dnx = d + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    pq.emplace(dnx, nx.first);
                }
            }
        }
    }

    // Dijkstra algorithm, O(V^2 + E)
    void DijkstraVquad(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        dist[s] = 0;
        prev.assign(V, INVALID);
        std::vector<char> fixed(V, false);
        while (true) {
            int r = INVALID;
            T dr = INF;
            for (int i = 0; i < V; i++) {
                if (!fixed[i] and dist[i] < dr) r = i, dr = dist[i];
            }
            if (r == INVALID) break;
            fixed[r] = true;
            int nxt;
            T dx;
            for (auto p : to[r]) {
                std::tie(nxt, dx) = p;
                if (dist[nxt] > dist[r] + dx) dist[nxt] = dist[r] + dx, prev[nxt] = r;
            }
        }
    }

    // Bellman-Ford algorithm
    // Complexity: O(VE)
    bool BellmanFord(int s, int nb_loop) {
        assert(0 <= s and s < V);
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        for (int l = 0; l < nb_loop; l++) {
            bool upd = false;
            for (int v = 0; v < V; v++) {
                if (dist[v] == INF) continue;
                for (auto nx : to[v]) {
                    T dnx = dist[v] + nx.second;
                    if (dist[nx.first] > dnx) dist[nx.first] = dnx, prev[nx.first] = v, upd = true;
                }
            }
            if (!upd) return true;
        }
        return false;
    }

    // Bellman-ford algorithm using queue (deque)
    // Complexity: O(VE)
    // Requirement: no negative loop
    void SPFA(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        prev.assign(V, INVALID);
        std::deque<int> q;
        std::vector<char> in_queue(V);
        dist[s] = 0;
        q.push_back(s), in_queue[s] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop_front(), in_queue[now] = 0;
            for (auto nx : to[now]) {
                T dnx = dist[now] + nx.second;
                int nxt = nx.first;
                if (dist[nxt] > dnx) {
                    dist[nxt] = dnx;
                    if (!in_queue[nxt]) {
                        if (q.size() and dnx < dist[q.front()]) { // Small label first optimization
                            q.push_front(nxt);
                        } else {
                            q.push_back(nxt);
                        }
                        prev[nxt] = now, in_queue[nxt] = 1;
                    }
                }
            }
        }
    }

    void ZeroOneBFS(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        std::deque<int> que;
        que.push_back(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop_front();
            for (auto nx : to[v]) {
                T dnx = dist[v] + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    if (nx.second) {
                        que.push_back(nx.first);
                    } else {
                        que.push_front(nx.first);
                    }
                }
            }
        }
    }

    // Retrieve a sequence of vertex ids that represents shortest path [s, ..., goal]
    // If not reachable to goal, return {}
    std::vector<int> retrieve_path(int goal) const {
        assert(int(prev.size()) == V);
        assert(0 <= goal and goal < V);
        if (dist[goal] == INF) return {};
        std::vector<int> ret{goal};
        while (prev[goal] != INVALID) {
            goal = prev[goal];
            ret.push_back(goal);
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    void solve(int s) {
        if (wmin >= 0) {
            if (single_positive_weight) {
                ZeroOneBFS(s);
            } else {
                if ((long long)V * V < (E << 4)) {
                    DijkstraVquad(s);
                } else {
                    Dijkstra(s);
                }
            }
        } else {
            BellmanFord(s, V);
        }
    }

    // Warshall-Floyd algorithm
    // Complexity: O(E + V^3)
    std::vector<std::vector<T>> dist2d;
    void WarshallFloyd() {
        dist2d.assign(V, std::vector<T>(V, INF));
        for (int i = 0; i < V; i++) {
            dist2d[i][i] = 0;
            for (auto p : to[i]) dist2d[i][p.first] = std::min(dist2d[i][p.first], p.second);
        }
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                if (dist2d[i][k] == INF) continue;
                for (int j = 0; j < V; j++) {
                    if (dist2d[k][j] == INF) continue;
                    dist2d[i][j] = std::min(dist2d[i][j], dist2d[i][k] + dist2d[k][j]);
                }
            }
        }
    }

    void dump_graphviz(std::string filename = "shortest_path") const {
        std::ofstream ss(filename + ".DOT");
        ss << "digraph{\n";
        for (int i = 0; i < V; i++) {
            for (const auto &e : to[i]) ss << i << "->" << e.first << "[label=" << e.second << "];\n";
        }
        ss << "}\n";
        ss.close();
        return;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    ShortestPath<lint> ssp(N), ssp1(N);
    vector<tuple<int, int, int>> edges;

    vector<int> chid(N, -1);
    vector<int> par(N, -1);
    REP(e, N - 1) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        edges.emplace_back(u, v, d);
        ssp.add_edge(u, v, d);
        ssp1.add_edge(u, v, 1);
        chid[u] = v;
        par[v] = u;
    }
    ssp.solve(0);
    ssp1.solve(0);

    LCT tree;
    vector<LCT::Node *> vs;
    REP(i, N) vs.push_back(tree.make_node({i, -INF}));

    vector<vector<int>> d2eid(N);
    REP(eid, edges.size()) {
        auto [u, v, w] = edges[eid];
        d2eid[ssp1.dist[u]].push_back(eid);
    }
    dbg(d2eid);

    IREP(d, d2eid.size()) {
        for (auto eid : d2eid[d]) {
            auto [u, v, w] = edges[eid];
            tree.link(vs[v], vs[u]);
            tree.expose(vs[v]);
        }
    }

    integer_segments<lint> seg;
    vector<plint> scheduling;

    while (M--) {
        int s;
        lint t;
        cin >> s >> t;
        s--;
        if (s == 0) continue;

        pending_ids.clear();
        tree.expose(vs[s]);
        auto ps = pending_ids;
        reverse(ps.begin(), ps.end());
        ps.pop_back();
        for (auto i : ps) {
            int dd = ssp1.dist[s] - ssp1.dist[i] - 1;
            int u = tree.kth_parent(vs[s], dd)->d.id_;
            if (chid[i] == u) continue;
            chid[i] = u;

            lint lo = max(0LL, ssp.dist[i] + tree.get(vs[i]).last_departure) + 1;
            lint hi = ssp.dist[i] + t;
            scheduling.emplace_back(hi, lo);
        }
        tree.apply(vs[0], vs[par[s]], t);
    }

    sort(scheduling.begin(), scheduling.end());

    lint highest = 0;
    int ret = 0;
    REP(i, scheduling.size()) {
        auto [hi, lo] = scheduling[i];
        if (chmax(highest, hi)) ret = i;
        auto [l, r] = seg.get(lo);
        lint t = (l < 0 ? lo : r + 1);
        if (t > hi) {
            cout << highest << ' ' << ret << '\n';
            return 0;
        } else {
            seg.insert(t, t);
        }
    }
    cout << "-1 " << seg.count() << '\n';
}