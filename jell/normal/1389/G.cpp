#pragma region preprocessor
#ifdef LOCAL
//*
    #define _GLIBCXX_DEBUG  // gcc
/*/
    #define _LIBCPP_DEBUG 0 // clang
//*/
    // #define __buffer_check__
#else
    #pragma GCC optimize("Ofast")
    // #define NDEBUG
#endif
#define __precision__ 15
#define __iostream_untie__ true
#include <bits/stdc++.h>
#include <ext/rope>

#ifdef LOCAL
    #include "dump.hpp"
    #define mesg(str) std::cerr << "[ " << __LINE__ << " : " << __FUNCTION__ << " ]  " << str << "\n"
#else
    #define dump(...) ((void)0)
    #define mesg(str) ((void)0)
#endif
#pragma endregion

#pragma region std-overload
namespace std
{
    // hash
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T, U>> { size_t operator()(pair<T, U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1> struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class... T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    // iostream
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
} // namespace std
#pragma endregion

#pragma region config
namespace config
{
    const auto start_time{std::chrono::system_clock::now()};
    int64_t elapsed()
    {
        using namespace std::chrono;
        const auto end_time{std::chrono::system_clock::now()};
        return duration_cast<milliseconds>(end_time - start_time).count();
    }
    __attribute__((constructor)) void setup()
    {
        using namespace std;
        if(__iostream_untie__) ios::sync_with_stdio(false), cin.tie(nullptr);
                cout << fixed << setprecision(__precision__);
        #ifdef DEBUG
                freopen("debug.out","w",stdout);
                freopen("debug.err","w",stderr);
                if(!freopen("debug.in","r",stdin))
                {
                    cerr << "error: \"./debug.in\" not found.\n";
                    exit(EXIT_FAILURE);
                }
        #endif
        #ifdef stderr_path
                freopen(stderr_path, "a", stderr);
        #endif
        #ifdef LOCAL
                cerr << fixed << setprecision(__precision__) << boolalpha << "\n----- stderr at LOCAL -----\n\n";
                atexit([]{ cerr << "\n----- Exec time : " << elapsed() << " ms -----\n\n"; });
        #endif
        #ifdef __buffer_check__
                atexit([]{ ofstream cnsl("CON"); char bufc; if(cin >> bufc) cnsl << "\n\033[1;35mwarning\033[0m: buffer not empty.\n\n"; });
        #endif
    }
} // namespace config
#pragma endregion

#pragma region utility
// lambda wrapper for recursive method.
template <class lambda_type>
class fixed_point
{
    lambda_type func;
public:
    fixed_point(lambda_type &&f) : func(std::move(f)) {}
    template <class... Args> auto operator()(Args &&... args) const { return func(*this, std::forward<Args>(args)...); }
};
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
// substitute y for x if x > y.
template <class T> inline bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
// substitute y for x if x < y.
template <class T> inline bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
// binary search on discrete range.
template <class iter_type, class pred_type>
iter_type binary(iter_type __ok, iter_type __ng, pred_type pred)
{
    assert(__ok != __ng);
    std::ptrdiff_t dist(__ng - __ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(__ok + dist / 2);
        if(pred(mid)) __ok = mid, dist -= dist / 2;
        else __ng = mid, dist /= 2;
    }
    return __ok;
}
// binary search on real numbers.
template <class pred_type>
long double binary(long double __ok, long double __ng, const long double eps, pred_type pred)
{
    assert(__ok != __ng);
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}
// trinary search on discrete range.
template <class iter_type, class comp_type>
iter_type trinary(iter_type __first, iter_type __last, comp_type comp)
{
    assert(__first < __last);
    std::ptrdiff_t dist(__last - __first);
    while(dist > 2)
    {
        iter_type __left(__first + dist / 3), __right(__first + dist * 2 / 3);
        if(comp(__left, __right)) __last = __right, dist = dist * 2 / 3;
        else __first = __left, dist -= dist / 3;
    }
    if(dist > 1 && comp(next(__first), __first)) ++__first;
    return __first;
}
// trinary search on real numbers.
template <class comp_type>
long double trinary(long double __first, long double __last, const long double eps, comp_type comp)
{
    assert(__first < __last);
    while(__last - __first > eps)
    {
        long double __left{(__first * 2 + __last) / 3}, __right{(__first + __last * 2) / 3};
        if(comp(__left, __right)) __last = __right;
        else __first = __left;
    }
    return __first;
}
// size of array.
template <class A, size_t N> size_t size(A (&array)[N]) { return N; }
// be careful that val is type-sensitive.
template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
#pragma endregion

#pragma region alias
using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;
using namespace __gnu_cxx;
#pragma endregion

#pragma region library



#pragma endregion

struct solver; template <class> void main_(); int main() { main_<solver>(); }
template <class solver> void main_()
{
    unsigned t = 1;
#ifdef LOCAL
    t = 1;
#endif
    // t = -1; // infinite loop
    // cin >> t; // case number given

    while(t--) solver();
}

struct solver
{
    struct edge
    {
        int to,cost;
    };

    const int n;
    vector<bool> ispe;
    vector<i64> coin,c2;
    vector<vector<edge>> G,tree;
    vector<int> low;
    vector<bool> ispe2;

    int dfs(int now, int par, int k, vector<int> &vlst)
    {
        int ord=low[now]=k++;
        vlst.push_back(now);
        vector<edge> ned;
        for(auto [to,w]: G[now])
        {
            if(to==par) continue;
            if(~low[to]) chmin(low[now],low[to]);
            else
            {
                k=dfs(to,now,k,vlst);
                if(low[to]>ord) ned.push_back({low[to],w});
                else chmin(low[now],low[to]);
            }
        }
        swap(G[now],ned);
        if(ord==low[now])
        {
            for(int v=-1; v!=now; vlst.pop_back())
            {
                v=vlst.back();
                low[v]=ord;
                c2[ord]+=coin[v];
                if(ispe[v]) ispe2[ord]=1;
                tree[ord].insert(end(tree[ord]),begin(G[v]),end(G[v]));
            }
        }
        return k;
    }

    vector<i64> dp,ans;

    void treedp(int now)
    {
        dp[now]=c2[now];
        for(auto &[to,w]: tree[now])
        {
            treedp(to);
            if(ispe2[to]) ispe2[now]=1;
            else w=0;
            if(dp[to]>w) dp[now]+=dp[to]-w;
        }
    }

    void reroot(int now,i64 add)
    {
        if(add<0) add=0;
        ans[now]=add+dp[now];
        add+=c2[now];
        vector<i64> lac{0};
        for(auto [to,w]: tree[now])
        {
            i64 ndp=lac.back()+max<i64>(0,dp[to]-w);
            lac.emplace_back(ndp);
        }
        reverse(begin(tree[now]), end(tree[now]));
        vector<i64> rac{0};
        for(auto [to,w]: tree[now])
        {
            i64 ndp=rac.back()+max<i64>(0,dp[to]-w);
            rac.emplace_back(ndp);
        }
        reverse(begin(tree[now]), end(tree[now]));
        reverse(begin(rac), end(rac));
        for(size_t i=0; i<tree[now].size(); i++)
        {
            auto [to,w]=tree[now][i];
            const i64 tmp=lac[i]+rac[i+1]-w;
            add+=tmp;
            reroot(to,add);
            add-=tmp;
        }
    }

    solver() : n(read<int>()),ispe(n),coin(n),c2(n),G(n),tree(n),low(n,-1),ispe2(n),dp(n),ans(n)
    {
        int root=-1;
        int m=read<int>();
        for(int k=read<int>(); k; k--)
        {
            int sv=read<int>();
            sv--;
            ispe[sv]=true;
            root=sv;
        }
        cin>>coin;
        vector<int> w(m); cin>>w;
        for(int a,b,i=0; i<m; i++)
        {
            cin>>a>>b;
            a--,b--;
            G[a].push_back({b,w[i]});
            G[b].push_back({a,w[i]});
        }
        vector<int> lst;
        dfs(root,-1,0,lst);
        treedp(0);
        reroot(0,0);
        for(int i=0; i<n; i++)
        {
            cout<<ans[low[i]]<<" ";
        }
        cout<<endl;
    }
};