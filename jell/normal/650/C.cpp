#line 2 "Library\\gcc_option.hpp"
#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#else
    #pragma GCC optimize("O3")
    #pragma GCC target("avx,avx2")
    #pragma GCC optimize("unroll-loops")
#endif
#line 2 "Library\\gcc_builtin.hpp"
#include <cstdint>
namespace workspace {
constexpr int clz32(const uint32_t &n) noexcept { return __builtin_clz(n); }
constexpr int clz64(const uint64_t &n) noexcept{ return __builtin_clzll(n); }
constexpr int ctz(const uint64_t &n) noexcept { return __builtin_ctzll(n); }
constexpr int popcnt(const uint64_t &n) noexcept { return __builtin_popcountll(n); }
} // namespace workspace
#line 3 "codeforces-workspace\\contest\\650\\c\\c.cpp"
#include <bits/extc++.h>
#line 5 "Library\\config.hpp"
namespace config {
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
unsigned cases(void), caseid = 1;
template <class C> void main() { for(const unsigned total = cases(); caseid <= total; ++caseid) C(); }
} // namespace config
#line 5 "Library\\utils\\binary_search.hpp"
namespace workspace {
// binary search on discrete range.
template <class iter_type, class pred_type, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<pred_type, iter_type>, bool>, std::nullptr_t> = nullptr>
iter_type binary_search(iter_type ok, iter_type ng, pred_type pred)
{
    assert(ok != ng);
    intmax_t dist(ng - ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(ok + dist / 2);
        if(pred(mid)) ok = mid, dist -= dist / 2;
        else ng = mid, dist /= 2;
    }
    return ok;
}
// binary search on real numbers.
template <class real_type, class pred_type, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>, std::nullptr_t> = nullptr>
real_type binary_search(real_type ok, real_type ng, const real_type eps, pred_type pred)
{
    assert(ok != ng);
    while(std::abs(ok - ng) > eps)
    {
        real_type mid{(ok + ng) / 2};
        (pred(mid) ? ok : ng) = mid;
    }
    return ok;
}
} // namespace workspace
#line 3 "Library\\utils\\casefmt.hpp"
namespace workspace {
std::ostream &casefmt(std::ostream& os) { return os << "Case #" << config::caseid << ": "; }
} // namespace workspace
#line 3 "Library\\utils\\chval.hpp"
namespace workspace {
template <class T, class Comp = std::less<T>> bool chle(T &x, const T &y, Comp comp = Comp()) { return comp(y, x) ? x = y, true : false; }
template <class T, class Comp = std::less<T>> bool chge(T &x, const T &y, Comp comp = Comp()) { return comp(x, y) ? x = y, true : false; }
} // namespace workspace
#line 3 "Library\\utils\\fixed_point.hpp"
namespace workspace {
// specify the return type of lambda.
template <class lambda_type>
class fixed_point
{
    lambda_type func;
public:
    fixed_point(lambda_type &&f) : func(std::move(f)) {}
    template <class... Args> auto operator()(Args &&... args) const { return func(*this, std::forward<Args>(args)...); }
};
} // namespace workspace
#line 2 "Library\\utils\\sfinae.hpp"
#include <type_traits>
template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;
template <class Container>
using element_type = std::remove_const_t<std::remove_reference_t<decltype(*std::begin(std::declval<Container&>()))>>;
#line 7 "Library\\utils\\hash.hpp"
namespace workspace {
template <class T, class = void>
struct hash : std::hash<T> {};
template <class Unique_bits_type>
struct hash<Unique_bits_type, enable_if_trait_type<Unique_bits_type, std::has_unique_object_representations>>
{
    size_t operator()(uint64_t x) const
    {
        static const uint64_t m = std::random_device{}();
        x ^= x >> 23;
        // x *= 0x2127599bf4325c37ULL;
        x ^= m;
        x ^= x >> 47;
        return x - (x >> 32);
    }
};
template <class Key>
size_t hash_combine(const size_t &seed, const Key &key)
{
    return seed ^ (hash<Key>()(key) + 0x9e3779b9 /* + (seed << 6) + (seed >> 2) */ );
}
template <class T1, class T2>
struct hash<std::pair<T1, T2>>
{
    size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return hash_combine(hash<T1>()(pair.first), pair.second);
    }
};
template <class... T>
class hash<std::tuple<T...>>
{
    template <class Tuple, size_t index = std::tuple_size<Tuple>::value - 1> struct tuple_hash { static uint64_t apply(const Tuple &t) { return hash_combine(tuple_hash<Tuple, index - 1>::apply(t), std::get<index>(t)); } };
    template <class Tuple> struct tuple_hash<Tuple, size_t(-1)> { static uint64_t apply(const Tuple &t) { return 0; } };
public:
    uint64_t operator()(const std::tuple<T...> &t) const { return tuple_hash<std::tuple<T...>>::apply(t); }
};
/*
template <class Key, class Mapped>
struct hash_map : public __gnu_pbds::gp_hash_table<Key, Mapped, hash<Key>>
{
    using base = __gnu_pbds::gp_hash_table<Key, Mapped, hash<Key>>;
    size_t count(const Key &key) const { return base::find(key) != base::end(); }
    template <class... Args> auto emplace(Args&&... args) { return base::insert(typename base::value_type(args...)); }
};
template <class Key> using hash_set = hash_map<Key, __gnu_pbds::null_type>;
/*/
template <class Key, class Mapped> using hash_map = std::unordered_map<Key, Mapped, hash<Key>>;
template <class Key> using hash_set = std::unordered_set<Key, hash<Key>>;
/**/
} // namespace workspace
#line 3 "Library\\utils\\iostream_overload.hpp"
namespace std
{
    template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << ' ' << p.second; }
    template <class tuple_t, size_t index> struct tuple_is { static istream &apply(istream &is, tuple_t &t) { tuple_is<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tuple_is<tuple_t, SIZE_MAX> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t) { return tuple_is<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <class tuple_t, size_t index> struct tuple_os { static ostream &apply(ostream &os, const tuple_t &t) { tuple_os<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tuple_os<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class tuple_t> struct tuple_os<tuple_t, SIZE_MAX> { static ostream &apply(ostream &os, const tuple_t &t) { return os; } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { return tuple_os<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} // namespace std
#line 3 "Library\\utils\\read.hpp"
namespace workspace {
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
} // namespace workspace
#line 12 "codeforces-workspace\\contest\\650\\c\\c.cpp"
namespace workspace {
    constexpr char eol = '\n';
    using namespace std; using namespace __gnu_pbds; using namespace __gnu_cxx;
    using i64 = int_least64_t; using p32 = pair<int, int>; using p64 = pair<i64, i64>;
    using __gnu_pbds::priority_queue;
    struct solver;
}
int main() { config::main<workspace::solver>(); }
unsigned config::cases() {
    // return -1; // not specify
    // int t; std::cin >> t; return t; // given
    return 1;
}

#line 1 "Library\\graph\\directed\\strongly_connected_components.hpp"



#line 6 "Library\\graph\\directed\\strongly_connected_components.hpp"

class strongly_connected_components
{
    std::vector<std::vector<size_t>> graph, memb;
    std::vector<size_t> comp, low;
    size_t cnt;
    bool made;

public:
    strongly_connected_components(size_t n) : graph(n), comp(n), low(n), made() {}

    // add an edge from the vertex s to the vertex t.
    void add_edge(size_t src, size_t dst)
    {
        assert(src < size()); assert(dst < size());
        graph[src].emplace_back(dst);
        made = false;
    }

    // the number of the components.
    size_t count() { make(); return cnt; }

    size_t size() const { return graph.size(); }

    // the number of vertices in the i-th component.
    size_t size(size_t i) { make(); return memb[i].size(); }

    // vertices in the i-th component.
    const std::vector<size_t> &component(size_t i) { make(); return memb[i]; }

    // the component which the vertex v belongs to.
    size_t operator[](size_t v) { make(); return comp[v]; }

    // the directed acyclic graph consisting of the components.
    std::vector<std::vector<size_t>> make_dag()
    {
        make();
        std::vector<std::vector<size_t>> res(cnt);
        bool *apr = new bool[size()]{};
        size_t *stack_ptr = new size_t[size()];
        for(size_t i = 0; i != cnt; ++i)
        {
            size_t *itr = stack_ptr;
            apr[i] = true;
            for(size_t src : memb[i]) for(size_t dst : graph[src]) if(!apr[comp[dst]]) apr[comp[dst]] = true, *itr++ = comp[dst];
            res[i].resize(itr - stack_ptr);
            while(itr-- != stack_ptr) apr[res[i][itr - stack_ptr] = *itr] = false;
            apr[i] = false;
        }
        delete[] apr; delete[] stack_ptr;
        return res;
    }

protected:
    void make()
    {
        if(made) return;
        made = true, cnt = 0;
        fill(low.begin(), low.end(), -1);
        fill(comp.begin(), comp.end(), -1);
        size_t *itr = new size_t[size()];
        for(size_t v = 0, c = 0; v != size(); ++v) affix(v, c, itr);
        delete[] itr; memb.resize(cnt);
        for(size_t v = 0; v != size(); ++v) memb[comp[v] = cnt - 1 - comp[v]].emplace_back(v);
    }

    size_t affix(size_t src, size_t &c, size_t* &itr)
    {
        if(~low[src]) return ~comp[src] ? -1 : low[src];
        size_t idx = c++; low[src] = idx; *itr++ = src;
        for(size_t dst : graph[src]) low[src] = std::min(low[src], affix(dst, c, itr));
        if(low[src] == idx) { do { comp[*--itr] = cnt; } while(*itr != src); ++cnt; }
        return low[src];
    }
}; // class strongly_connected_components


#line 4 "Library\\data_structure\\union_find\\basic.hpp"
class union_find
{
    std::vector<int> link;

public:
    union_find(const unsigned n = 0) : link(n, -1) {}

    unsigned find(unsigned x)
    {
        assert(x < size());
        return link[x] < 0 ? x : (link[x] = find(link[x]));
    }

    unsigned size() const { return link.size(); }

    unsigned size(const unsigned x)
    {
        assert(x < size());
        return -link[find(x)];
    }

    bool same(const unsigned x, const unsigned y)
    {
        assert(x < size() && y < size());
        return find(x) == find(y);
    }

    bool unite(unsigned x, unsigned y)
    {
        assert(x < size() && y < size());
        x = find(x), y = find(y);
        if(x == y) return false;
        if(link[x] > link[y]) std::swap(x, y);
        link[x] += link[y];
        link[y] = x;
        return true;
    }
}; // class union_find
#line 28 "codeforces-workspace\\contest\\650\\c\\c.cpp"

struct workspace::solver { // start here!

solver()
{
    int n,m; cin>>n>>m;
    vector dat(n,vector<int>(m));
    for(auto &r: dat)
    {
        for(auto &e: r)
        {
            cin>>e;
        }
    }

    union_find uf(n*m);

    for(int i=0; i<n; ++i)
    {
        vector<int> id(m);
        iota(begin(id),end(id),0);
        sort(begin(id),end(id),[&](int x,int y){return dat[i][x]<dat[i][y];});
        auto v=[&](int j){ return i*m+j; };
        for(auto l=begin(id),r=l; l!=end(id); l=r)
        {
            while(r!=end(id) and dat[i][*l]==dat[i][*r]) r++;
            for(auto p=l; p+1!=r; ++p)
            {
                uf.unite(v(*p),v(*next(p)));
            }
        }
    }
    for(int i=0; i<m; ++i)
    {
        vector<int> id(n);
        iota(begin(id),end(id),0);
        sort(begin(id),end(id),[&](int x,int y){return dat[x][i]<dat[y][i];});
        auto v=[&](int j){ return i+j*m; };
        for(auto l=begin(id),r=l; l!=end(id); l=r)
        {
            while(r!=end(id) and dat[*l][i]==dat[*r][i]) r++;
            for(auto p=l; p+1!=r; ++p)
            {
                uf.unite(v(*p),v(*next(p)));
            }
        }
    }

    vector<int> in(n*m);
    vector<vector<int>> dag(n*m+1);
    for(int i=0; i<n; ++i)
    {
        vector<int> id(m);
        iota(begin(id),end(id),0);
        sort(begin(id),end(id),[&](int x,int y){return dat[i][x]<dat[i][y];});
        auto v=[&](int j){ return i*m+j; };
        int pv=n*m;
        for(auto l=begin(id),r=l; l!=end(id); l=r)
        {
            while(r!=end(id) and dat[i][*l]==dat[i][*r]) r++;
            int c=uf.find(v(*l));
            dag[pv].emplace_back(c);
            in[c]++;
            pv=c;
        }
    }
    for(int i=0; i<m; ++i)
    {
        vector<int> id(n);
        iota(begin(id),end(id),0);
        sort(begin(id),end(id),[&](int x,int y){return dat[x][i]<dat[y][i];});
        auto v=[&](int j){ return i+m*j; };
        int pv=n*m;
        for(auto l=begin(id),r=l; l!=end(id); l=r)
        {
            while(r!=end(id) and dat[*l][i]==dat[*r][i]) r++;
            int c=uf.find(v(*l));
            dag[pv].emplace_back(c);
            in[c]++;
            pv=c;
        }
    }

    vector<int> afx(n*m+1);
    afx.back()=0;
    queue<int> q;
    q.push(n*m);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(auto to: dag[now])
        {
            in[to]--;
            chge(afx[to],afx[now]+1);
            if(!in[to]) q.push(to);
        }
    }

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            dat[i][j]=afx[uf.find(i*m+j)];
        }
    }

    for(auto &r: dat)
    {
        cout<<r<<eol;
    }

}};