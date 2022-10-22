#line 1 "b.cpp"
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

#line 4 "C:/Users/euler/Documents/competitive_programming/Library/config.hpp"
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
#line 2 "C:/Users/euler/Documents/competitive_programming/Library/utils/iostream_overload.hpp"
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
#line 1 "C:/Users/euler/Documents/competitive_programming/Library/utils/fixed_point.hpp"
template <class lambda_type>
class fixed_point
{
    lambda_type func;
public:
    fixed_point(lambda_type &&f) : func(std::move(f)) {}
    template <class... Args> auto operator()(Args &&... args) const { return func(*this, std::forward<Args>(args)...); }
};
#line 1 "C:/Users/euler/Documents/competitive_programming/Library/utils/read.hpp"
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
#line 2 "C:/Users/euler/Documents/competitive_programming/Library/utils/chval.hpp"
template <class T, class Comp = std::less<T>> bool chle(T &x, const T &y, Comp comp = Comp()) { return comp(y, x) ? x = y, true : false; }
template <class T, class Comp = std::less<T>> bool chge(T &x, const T &y, Comp comp = Comp()) { return comp(x, y) ? x = y, true : false; }
#line 1 "C:/Users/euler/Documents/competitive_programming/Library/utils/binary_search.hpp"
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
#line 19 "b.cpp"

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
        i64 n,m; cin>>n>>m;
        if(n>m) swap(n,m);
        if(n>1)
        {
            if(n&1)
            {
                if(m&1)
                {
                    cout<<n*m-1<<endl;
                }
                else
                {
                    cout<<n*m<<endl;
                }
            }
            else
            {
                if(m&1)
                {
                    if(m==3) cout<<4<<endl;
                    else if(n==2 and m==7) cout<<12<<endl;
                    else cout<<n*m<<endl;
                }
                else
                {
                    if(m==2) cout<<0<<endl;
                    else cout<<n*m<<endl;
                }
            }
        }
        else
        {
            cout<<(m/6+(m+1)/6+(m+2)/6)*2<<endl;
        }
    }
};