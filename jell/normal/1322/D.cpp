/* preprocessor start */
#ifdef LOCAL
//*
    #define _GLIBCXX_DEBUG  // gcc
/*/
    #define _LIBCPP_DEBUG 0 // clang
//*/
    #define __clock__
    // #define __buffer_check__
#else
    #pragma GCC optimize("Ofast")
/*
    #define _GLIBCXX_DEBUG  // gcc
/*/
//    #define _LIBCPP_DEBUG 0 // clang
//*/
    // #define __buffer_check__
    // #define NDEBUG
#endif
#define __precision__ 10
#define iostream_untie true
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#define __all(v) std::begin(v), std::end(v)
#define __rall(v) std::rbegin(v), std::rend(v)
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)
/* preprocessor end */

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

namespace setting
{
    using namespace std;
    using namespace chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { cerr << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n\n"; }
    void buffer_check() { char bufc; if(cin >> bufc) cerr << "\n\033[1;35mwarning\033[0m: buffer not empty.\n"; }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) ios::sync_with_stdio(false), cin.tie(nullptr);
            cout << fixed << setprecision(__precision__);
    #ifdef stderr_path
            if(freopen(stderr_path, "a", stderr)) cerr << fixed << setprecision(__precision__);
    #endif
    #ifdef LOCAL
            cerr << boolalpha << "\n----- stderr at LOCAL -----\n\n";
    #endif
    #ifdef __buffer_check__
            atexit(buffer_check);
    #endif
    #ifdef __clock__
            start_time = system_clock::now();
            atexit(print_elapsed_time);
    #endif
        }
    } __setupper; // struct setupper
} // namespace setting

#ifdef __clock__
    #include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\clock.hpp"
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

#ifdef LOCAL
    #include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\dump.hpp"
#else
    #define dump(...) ((void)0)
#endif

/* function utility start */
template <class T, class... types> T read(types... args) noexcept { typename std::remove_const<T>::type obj(args...); std::cin >> obj; return obj; }
#define input(type, var, ...) type var{read<type>(__VA_ARGS__)}
// substitute y for x if x > y.
template <class T> inline bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
// substitute y for x if x < y.
template <class T> inline bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
// binary search on discrete range.
template <class iter_type, class pred_type>
iter_type binary(iter_type __ok, iter_type __ng, pred_type pred)
{
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
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}
// size of array.
template <class A, size_t N> size_t size(A (&array)[N]) { return N; }
// be careful that val is type-sensitive.
template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
/* functon utility end */

/* using alias start */
using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;
/* using alias end */

/* library start */

#include <cassert>
#include <vector>

template <class monoid>
class segment_tree
{
    using size_type = typename std::vector<monoid>::size_type;

    class unique_queue
    {
        size_type *que, *begin, *end;
        bool *in;

    public:
        unique_queue() : que(), begin(), end(), in() {}
        unique_queue(size_type n) : que(new size_type[n]), begin(que), end(que), in(new bool[n]{}) {}
        ~unique_queue() { delete[] que; delete[] in; }

        void clear() { begin = end = que; }
        bool empty() const { return begin == end; }
        bool push(size_type index)
        {
            if(in[index]) return false;
            return in[*end++ = index] = true;
        }
        size_type pop() { return in[*begin] = false, *begin++; }
    }; // struct unique_queue

    size_type size_orig, height, size_ext;
    std::vector<monoid> data;
    unique_queue que;

    void recalc(const size_type node) { data[node] = data[node << 1] + data[node << 1 | 1]; }

    void rebuild()
    {
        while(!que.empty())
        {
            const size_type index = que.pop() >> 1;
            if(index && que.push(index)) recalc(index);
        }
        que.clear();
    }

    template <class pred_type>
    size_type left_search_subtree(size_type index, const pred_type pred, monoid mono) const
    {
        assert(index);
        while(index < size_ext)
        {
            const monoid tmp = data[(index <<= 1) | 1] + mono;
            if(pred(tmp)) mono = tmp;
            else ++index;
        }
        return ++index -= size_ext;
    }

    template <class pred_type>
    size_type right_search_subtree(size_type index, const pred_type pred, monoid mono) const
    {
        assert(index);
        while(index < size_ext)
        {
            const monoid tmp = mono + data[index <<= 1];
            if(pred(tmp)) ++index, mono = tmp;
        }
        return (index -= size_ext) < size_orig ? index : size_orig;
    }

public:
    segment_tree(const size_type n = 0) : size_orig{n}, height(n > 1 ? 32 - __builtin_clz(n - 1) : 0), size_ext{1u << height}, data(size_ext << 1), que(size_ext << 1) {}

    segment_tree(const size_type n, const monoid &init) : segment_tree(n)
    {
        std::fill(std::next(std::begin(data), size_ext), std::end(data), init);
        for(size_type i{size_ext}; --i; ) recalc(i);
    }

    template <class iter_type, class value_type = typename std::iterator_traits<iter_type>::value_type>
    segment_tree(iter_type first, iter_type last)
        : size_orig(std::distance(first, last)), height(size_orig > 1 ? 32 - __builtin_clz(size_orig - 1) : 0), size_ext{1u << height}, data(size_ext << 1), que(size_ext << 1)
    {
        static_assert(std::is_constructible<monoid, value_type>::value, "monoid(iter_type::value_type) is not constructible.");
        for(auto iter{std::next(std::begin(data), size_ext)}; iter != std::end(data) && first != last; ++iter, ++first) *iter = monoid{*first};
        for(size_type i{size_ext}; --i; ) recalc(i);
    }

    template <class container_type, typename = typename container_type::value_type>
    segment_tree(const container_type &cont) : segment_tree(std::begin(cont), std::end(cont)) {}

    size_type size() const { return size_orig; }
    size_type capacity() const { return size_ext; }

    // reference to the element at the index.
    typename decltype(data)::reference operator[](size_type index)
    {
        assert(index < size_orig);
        que.push(index |= size_ext);
        return data[index];
    }

    // const reference to the element at the index.
    typename decltype(data)::const_reference operator[](size_type index) const
    {
        assert(index < size_orig);
        return data[index |= size_orig];
    }

    monoid fold(size_type first, size_type last)
    {
        assert(last <= size_orig);
        rebuild();
        monoid leftval{}, rightval{};
        first += size_ext, last += size_ext;
        while(first < last)
        {
            if(first & 1) leftval = leftval + data[first++];
            if(last & 1) rightval = data[--last] + rightval;
            first >>= 1, last >>= 1;
        }
        return leftval + rightval;
    }

    monoid fold() { return fold(0, size_orig); }

    template <class pred_type>
    size_type left_search(size_type right, const pred_type pred)
    {
        assert(right <= size_orig);
        rebuild();
        right += size_ext;
        monoid mono{};
        for(size_type left{size_ext}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = data[--right] + mono;
                if(!pred(tmp)) return left_search_subtree(right, pred, mono);
                mono = tmp;
            }
        }
        return 0;
    }

    template <class pred_type>
    size_type right_search(size_type left, const pred_type pred)
    {
        assert(left <= size_orig);
        rebuild();
        left += size_ext;
        monoid mono{};
        for(size_type right{size_ext << 1}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = mono + data[left];
                if(!pred(tmp)) return right_search_subtree(left, pred, mono);
                mono = tmp;
                ++left;
            }
        }
        return size_orig;
    }
}; // class segment_tree

/* library end */

/* The main code follows. */

template <class T> void _main();
struct solver;
int main() { _main<solver>(); }

template <class solver>
void _main()
{
    unsigned t;
#ifdef LOCAL
    t = 1;
#else
    t = 1; // single test case
#endif
    // t = -1; // infinite loop
    // cin >> t; // case number given

    while(t--) solver();
}

struct mono_type
{
    i64 val=-1e18;
    mono_type() {}
    mono_type(i64 v) : val(v) {}

    // binary operation
    mono_type operator+(const mono_type& rhs) const { return mono_type{*this} += rhs; }

    // operation assignment
    mono_type &operator+=(const mono_type &rhs)
    {
        chmax(val,rhs.val);
        return *this;
    }
};

struct solver
{

    solver()
    {
        const i64 inf=1e18;
        int n,m; cin>>n>>m;

        vector dp(m+n+1, vector<i64>(1+n,-inf));
        for(auto &v:dp) v[0]=0;
        vector dp2(m+n+1,0LL);

        vector<int> l(n),s(n),c(n+m); cin>>l>>s>>c;
        c.insert(begin(c),0);
        reverse(__all(l));
        reverse(__all(s));


        segment_tree<mono_type> seg(n+m+1);
        // vector<segment_tree<mono_type>> segs(n+m+1,n+1);
// return;

        for(int i=0;i<n;++i)
        {
            int agg=l[i];
            int cost=s[i];

            // i64 nxt=0;
            // // for(int i=agg;i<=n+m;++i)
            // // {
            // //     // chmax(nxt,segs[i].fold().val);
            // //     chmax(nxt,dp2[i]);
            // // }

            // for(int i=agg; i<=n+m; ++i)
            // {
            //     chmax(nxt,dp[i][0]);
            // }
            // nxt+=c[agg]-cost;

            // auto &nseg=segs[agg];
            for(int i=n;i--;)
            {
                i64 now=dp[agg][i]+c[agg]-cost;
                // auto now=nseg[i].val+c[agg]-cost;
                for(int ii=i,k=agg;;ii>>=1)
                {
                    if(ii&1)
                    {
                        now+=c[++k];
                    }
                    else break;
                }
                int k=0;
                for(int ii=i+1;ii;k++,ii>>=1)
                {
                    // chmax(dp2[k+agg],now);
                    chmax(dp[k+agg][ii],now);
                    // segs[k+agg][ii]+=now; // chmax
                }

                seg[k+agg]+=now; // chmax
            }

            for(int k=agg;k<=n+m;++k)
            {
                chmax(dp[k][0],seg.fold(0,k+1).val);
            }

            // segs[agg][0]+=nxt; // chmax
            // chmax(dp2[agg],nxt);
            // chmax(dp[agg][1],nxt);
        }

        // i64 ans=*max_element(__all(dp2));
        i64 ans=-inf;
        for(auto &v:dp)
        {
            for(auto e:v)
            {
                chmax(ans,e);
            }
        }
        cout << ans << "\n";
    }
};