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
#line 3 "codeforces-workspace\\contest\\650\\d\\d.cpp"
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
#line 12 "codeforces-workspace\\contest\\650\\d\\d.cpp"
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

struct workspace::solver { // start here!

solver()
{
    const int inf=1e9+1;
    int n,m; cin>>n>>m;
    vector<int> h(n); cin>>h;
    vector<vector<p32>> qry(n);
    vector<int> ans(m,-1);
    for(int i=0; i<m; i++)
    {
        int p,x; cin>>p>>x;
        --p;
        qry[p].emplace_back(x,i);
    }
    h.emplace_back(inf);

    vector<int> rlen(n+1);
    // from right
    {
        vector<int> dp(n+1,inf);
        dp[0]=-1e9;
        for(int i=n; i--; )
        {
            for(auto [x,qi]: qry[i])
            {
                auto it=lower_bound(begin(dp),end(dp),-x);
                ans[qi]+=it-begin(dp);
            }
            auto it=lower_bound(begin(dp),end(dp),-h[i]);
            *it=-h[i];
            rlen[i]=it-begin(dp);
        }
    }

    vector<multiset<int>> cand(n+1);
    cand[0].emplace(inf);
    for(int i=0; i<n; ++i)
    {
        cand[rlen[i]].emplace(h[i]);
    }
    const int lis=*max_element(begin(rlen),end(rlen));
    vector<int> excl(n);

    // from left
    {
        hash_set<int> lisp;
        vector<int> dp(n+1,inf);
        dp[0]=0;
        if(!cand[lis].empty()) lisp.emplace(lis);
        for(int i=0; i<n; ++i)
        {
            {
                const int nr=rlen[i];
                auto &ncnd=cand[nr];
                ncnd.erase(ncnd.lower_bound(h[i]));
                if(!ncnd.empty() and *ncnd.rbegin()>dp[lis-nr])
                {
                    lisp.emplace(nr);
                }
                else
                {
                    lisp.erase(nr);
                }
            }
            
            excl[i]=lis-lisp.empty();

            for(auto [x,qi]: qry[i])
            {
                auto it=lower_bound(begin(dp),end(dp),x);
                ans[qi]+=it-begin(dp);
            }
            auto it=lower_bound(begin(dp),end(dp),h[i]);
            *it=h[i];
            {
                const int nl=it-begin(dp);
                const int nr=lis-nl;
                auto &ncnd=cand[lis-nl];
                if(!ncnd.empty() and *ncnd.rbegin()>dp[nl])
                {
                    lisp.emplace(nr);
                }
                else
                {
                    lisp.erase(nr);
                }
            }
        }
    }

    for(int j=0; j<n; ++j)
    {
        for(auto [x,i]: qry[j])
        {
            chge(ans[i],excl[j]);
        }
    }
    for(auto e: ans)
    {
        cout<<e<<eol;
    }
}};