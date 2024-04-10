#line 1 "atcoder-workspace/kupc2019/h/h.cpp"
#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#else
    #pragma GCC optimize("O3")
    #pragma GCC target("avx,avx2")
    #pragma GCC optimize("unroll-loops")
#endif
// #define NDEBUG

#include <bits/stdc++.h>
#include <ext/rope>

#line 4 "Library/config.hpp"
namespace config
{
    const auto start_time{std::chrono::system_clock::now()};
    int64_t elapsed()
    {
        using namespace std::chrono;
        const auto end_time{system_clock::now()};
        return duration_cast<milliseconds>(end_time - start_time).count();
    }
    __attribute__((constructor)) void setup()
    {
        using namespace std;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
        #ifdef _buffer_check
            atexit([]{ ofstream cnsl("CON"); char bufc; if(cin >> bufc) cnsl << "\n\033[1;35mwarning\033[0m: buffer not empty.\n\n"; });
        #endif
    }
    unsigned cases(void);
    template <class C> void main() { for(unsigned t = cases(); t; --t) C(); }
}
struct solver; int main() { config::main<solver>(); }
#line 2 "Library/utils/iostream_overload.hpp"
namespace std
{
    template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << ' ' << p.second; }
    template <class tuple_t, size_t index> struct tupleis { static istream &apply(istream &is, tuple_t &t) { tupleis<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tupleis<tuple_t, SIZE_MAX> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t) { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
}
#line 1 "Library/utils/fixed_point.hpp"
template <class lambda_type>
class fixed_point
{
    lambda_type func;
public:
    fixed_point(lambda_type &&f) : func(std::move(f)) {}
    template <class... Args> auto operator()(Args &&... args) const { return func(*this, std::forward<Args>(args)...); }
};
#line 2 "Library/utils/read.hpp"
// read with std::cin.
template <class T = void>
struct read
{
    typename std::remove_const<T>::type value;
    template <class... types>
    read(types... args) : value(args...) { std::cin >> value; }
    operator T() const { return value; }
};
template <>
struct read<void>
{
    template <class T>
    operator T() const { T value; std::cin >> value; return value; }
};
#line 2 "Library/utils/chval.hpp"
template <class T, class Comp = std::less<T>> bool chle(T &x, const T &y, Comp comp = Comp()) { return comp(y, x) ? x = y, true : false; }
template <class T, class Comp = std::less<T>> bool chge(T &x, const T &y, Comp comp = Comp()) { return comp(x, y) ? x = y, true : false; }
#line 1 "Library/utils/binary_search.hpp"
// binary search on discrete range.
template <class iter_type, class pred_type>
iter_type binary(iter_type ok, iter_type ng, pred_type pred)
{
    assert(ok != ng);
    long long dist(ng - ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(ok + dist / 2);
        if(pred(mid)) ok = mid, dist -= dist / 2;
        else ng = mid, dist /= 2;
    }
    return ok;
}
// binary search on real numbers.
template <class pred_type>
long double binary(long double ok, long double ng, const long double eps, pred_type pred)
{
    assert(ok != ng);
    while(std::abs(ok - ng) > eps)
    {
        long double mid{(ok + ng) / 2};
        (pred(mid) ? ok : ng) = mid;
    }
    return ok;
}
#line 19 "atcoder-workspace/kupc2019/h/h.cpp"

#line 4 "Library/graph/directed/flow/base.hpp"
// the base class of flow algorithms.
template <class cap_t, class cost_t>
struct flow_base
{
    struct edge_t
    {
        size_t src, dst;
        cap_t cap; cost_t cost; edge_t *rev;
        edge_t() {}
        edge_t(size_t src, size_t dst, cap_t cap, edge_t *rev) : src(src), dst(dst), cap(cap), rev(rev) {}
        edge_t(size_t src, size_t dst, cap_t cap, cost_t cost, edge_t *rev) : src(src), dst(dst), cap(cap), cost(cost), rev(rev) {}
        void flow(cap_t f) { cap -= f, rev->cap += f; }
        bool avbl() const { return cap > 0; }
    }; // class edge_t

    class adj_type
    {
        friend flow_base;
        edge_t *fst, *lst, *clst;
        template <class ...Args>
        edge_t *emplace(Args&& ...args)
        {
            if(lst == clst)
            {
                size_t len(clst - fst);
                edge_t *nfst = new edge_t[len << 1];
                lst = nfst;
                for(edge_t *p{fst}; p != clst; ++p, ++lst) p->rev->rev = lst, *lst = *p;
                delete[] fst;
                fst = nfst;
                clst = lst + len;
            }
            *lst = edge_t(args...);
            return lst++;
        }
    public:
        adj_type() : fst(new edge_t[1]), lst(fst), clst(fst + 1) {}
        ~adj_type() { delete[] fst; }
        edge_t &operator[](size_t i) { assert(i < size()); return *(fst + i); }
        size_t size() const { return lst - fst; }
        edge_t *begin() const { return fst; }
        edge_t *end() const { return lst; }
    }; // class adj_type

    flow_base(size_t n = 0) : adjs(n) {}

    flow_base(const flow_base& other) : adjs(other.size())
    {
        for(size_t node{}; node != size(); ++node)
        {
            for(const auto &[src, dst, cap, cost, rev] : other[node])
            {
                if(src == node)
                {
                    edge_t *ptr = adjs[src].emplace(src, dst, cap, cost, nullptr);
                    ptr->rev = adjs[dst].emplace(dst, src, rev->cap, -cost, ptr);
                    rev->src = -1;
                }
                else rev->rev->src = node;
            }
        }
    }

    flow_base &operator=(const flow_base &rhs)
    {
        if(this != &rhs)
        {
            flow_base copy(rhs);
            std::swap(adjs, copy.adjs);
        }
        return *this;
    }

    size_t size() const { return adjs.size(); }

    adj_type &operator[](size_t node) { assert(node < size()); return adjs[node]; }
    const adj_type &operator[](size_t node) const { assert(node < size()); return adjs[node]; }

    void add_edge(size_t src, size_t dst, cap_t cap, cost_t cost)
    {
        assert(src < size()); assert(dst < size());
        if(!(cap > 0) || src == dst) return;
        edge_t *ptr = adjs[src].emplace(src, dst, cap, cost, nullptr);
        ptr->rev = adjs[dst].emplace(dst, src, 0, cost, ptr);
    }

protected:
    std::vector<adj_type> adjs;
}; // class flow_base
#line 3 "Library/graph/directed/flow/Dinic.hpp"
// compute the maximum flow.
template <class cap_t = int>
class Dinic : public flow_base<cap_t, bool>
{
    using base = flow_base<cap_t, bool>;
    using edge_t = typename base::edge_t;
    using base::adjs;

    std::vector<size_t> level;
    std::vector<edge_t*> itr;
    constexpr static size_t level_infty = -1;

    cap_t dfs(const size_t &src, const size_t &dst, cap_t bound)
    {
        if(src == dst || bound == 0) return bound;
        cap_t flow(0);
        for(edge_t* &e{itr[dst]}; e != adjs[dst].end(); ++e)
            if(e->rev->avbl() && level[e->dst] < level[dst])
                if(cap_t achv = dfs(src, e->dst, std::min(bound, e->rev->cap)); achv > 0)
                {
                    e->rev->flow(achv);
                    flow += achv, bound -= achv;
                    if(bound == 0) break;
                }
        return flow;
    }

public:
    using base::size;

    Dinic(size_t n = 0) : base::flow_base(n), level(n, level_infty), itr(n) {}

    Dinic(const Dinic &other) : base::flow_base(other), level(other.level), itr(other.itr)  {}

    Dinic &operator=(const Dinic &rhs)
    {
        if(this != &rhs) base::operator=(rhs), level = rhs.level, itr = rhs.itr;
        return *this;
    }

    void add_edge(size_t src, size_t dst, cap_t cap) { base::add_edge(src, dst, cap, false); }

    void add_undirected_edge(size_t src, size_t dst, cap_t cap) { base::add_undirected_edge(src, dst, cap, false); }

    cap_t max_flow(size_t src, size_t dst)
    {
        assert(src < size()); assert(dst < size());
        cap_t flow(0), bound(0);
        for(const edge_t &e : adjs[src]) bound += e.cap;
        for(std::vector<size_t> que(size()); ; std::fill(level.begin(), level.end(), level_infty))
        {
            level[que.front() = src] = 0;
            for(auto ql{que.begin()}, qr{std::next(ql)}; level[dst] == level_infty && ql != qr; ++ql)
                for(const edge_t &e : adjs[*ql])
                    if(e.avbl() && level[e.dst] == level_infty)
                        level[*qr++ = e.dst] = level[*ql] + 1;
            if(level[dst] == level_infty) break;
            for(size_t node{}; node != size(); ++node) itr[node] = adjs[node].begin();
            flow += dfs(src, dst, bound);
        }
        return flow;
    }
}; // class Dinic
#line 21 "atcoder-workspace/kupc2019/h/h.cpp"

#pragma region alias
using namespace std; using namespace __gnu_cxx;
using i32 = int_least32_t; using i64 = int_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;
#pragma endregion

unsigned config::cases()
{
    unsigned t = 1;
    // t = -1;
    // cin >> t;
    return t;
}

struct solver
{
    solver()
    {
        const int n=read(),m=read();
        auto in=[&](int i,int j){ return 2*(i*m+j);};
        auto out=[&](int i,int j){ return in(i,j)+1;};
        vector<string> g(n); cin>>g;
        Dinic dinic(n*m*2);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j]!='#') dinic.add_edge(in(i,j),out(i,j),1);
                if(i+1<n) dinic.add_edge(out(i,j),in(i+1,j),1e7);
                if(j+1<m) dinic.add_edge(out(i,j),in(i,j+1),1e7);
            }
        }
        cout<<dinic.max_flow(out(0,0),in(n-1,m-1))<<"\n";
    }
};