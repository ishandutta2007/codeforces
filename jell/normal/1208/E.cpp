#ifdef DEBUG
    #define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("Ofast")
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>
#include <chrono>

#define stdin_filepath "stdin.txt"
#define stdout_filepath "stdout.txt"
#define stderr_filepath "stderr.txt"
#define iostream_untie true
#define __precision__ 10

#define rep(i, n) for(int_fast64_t i = 0; i < int_fast64_t(n); ++i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcountll

using namespace std;
using i64 = int_fast64_t;
using pii = pair<int, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)2 - (T)1123456;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

namespace execution {
    std::chrono::system_clock::time_point start_time, end_time;
    void print_elapsed_time() {
        end_time = std::chrono::system_clock::now();
        std::cerr << "\n----- Exec time : ";
        std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cerr << " ms -----\n";
    }
    struct setupper {
        setupper() {
            if(iostream_untie) {
                ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
                // std::cout.tie(nullptr);
                // std::cerr.tie(nullptr);
            }
            std::cout << std::fixed << std::setprecision(__precision__);
            std::cerr << std::fixed << std::setprecision(__precision__);
    #ifdef LOCAL
            if(!freopen(stdout_filepath, "wt", stdout)) {
                freopen("CON", "wt", stdout);
                std::cerr << "Failed to open the stdout file\n";
            }
            if(!freopen(stdin_filepath, "rt", stdin)) {
                freopen("CON", "rt", stdin);
                std::cerr << "Failed to open the stdin file\n";
            }
            if(!freopen(stderr_filepath, "wt", stderr)) {
                freopen("CON", "wt", stderr);
                std::cerr << "Failed to open the stderr file\n";
            }
    #endif
    #if defined(LOCAL) || defined(DEBUG)
            atexit(print_elapsed_time);
            start_time = std::chrono::system_clock::now();
    #endif
        }
    } __setupper;
}

struct myclock_t {
    std::chrono::system_clock::time_point built_pt, last_pt;
    int built_ln, last_ln;
    string built_func, last_func;
    std::ostream &os;
    bool is_built;

    myclock_t(std::ostream &_os = std::cerr) : os(_os), is_built(false) {}

    void build(int crt_ln, const string &crt_func) {
        is_built = true;
        last_pt = built_pt = std::chrono::system_clock::now();
        last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    
    void set(int crt_ln, const string &crt_func) {
        if(is_built) {
            last_pt = std::chrono::system_clock::now();
            last_ln = crt_ln, last_func = crt_func;
        } else {
            cerr << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::set failed (yet to be built clock!)\n";
        }
    }

    void get(int crt_ln, const string &crt_func) {
        if(is_built) {
            std::chrono::system_clock::time_point crt_pt(chrono::system_clock::now());
            int64_t diff = std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt - last_pt).count();
            os << diff << " ms elapsed from" << " [ " <<  last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) os << " (when built)";
            os << " to" << " [ " << crt_ln << " : " << crt_func << " ]" << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        } else {
            cerr << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::get failed (yet to be built clock!)\n";
        }
    }
};
#if defined(LOCAL) || defined(DEBUG)
    myclock_t myclock(std::cerr);
    #define build_clock() myclock.build(__LINE__, __func__)
    #define set_clock() myclock.set(__LINE__, __func__)
    #define get_clock() myclock.get(__LINE__, __func__)
#else
    #define build_clock()
    #define set_clock()
    #define get_clock()
#endif

namespace std {
    template <class RAitr> void rsort(RAitr __first, RAitr __last) { sort(__first, __last, greater<>()); }
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T,U>> { size_t operator()(pair<T,U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class ...T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
}

template <class T, class U> istream &operator>> (istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
template <class T, class U> ostream &operator<< (ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
template <class T> istream &operator>> (istream &s, vector<T> &v) { for(T &e : v) { s >> e; }   return s; }
template <class T> ostream &operator<< (ostream &s, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); ++i) { s << (i ? " " : "") << v[i]; }   return s;
}
template <class tuple_t, size_t index>
struct tupleos {
    static ostream &apply(ostream &s, const tuple_t &t) {
        tupleos<tuple_t,index - 1>::apply(s,t);
        return s << " " << get<index>(t);
    }
};
template <class tuple_t>
struct tupleos<tuple_t, 0> {
    static ostream &apply(ostream &s, const tuple_t &t) {
        return s << get<0>(t);
    }
};
template <class ...T> ostream &operator<< (ostream &s, const tuple<T...> &t) {
    return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(s,t);
}
template <> ostream &operator<< (ostream &s, const tuple<> &t) { return s; }
#if defined(LOCAL) || defined(DEBUG)
    #define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ", dump_func(__VA_ARGS__)
#else
    #define dump(...)
#endif
template <class T> void dump_func(const T &x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(const T &x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T> void write(const T &x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(const T &x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(const T &x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
template <class P> void read(P __first, P __second) { for(P i = __first; i != __second; ++i) cin >> *i; }

template <class T> bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
template <class T> bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
template <class T> constexpr T minf(const T &x, const T &y) { return min(x,y); }
template <class T> constexpr T maxf(const T &x, const T &y) { return max(x,y); }
constexpr bool odd(int_fast64_t n) { return n & 1; }
constexpr bool even(int_fast64_t n) { return (int)odd(n) ^ 1; }
constexpr bool bit(int_fast64_t n, int e) { return (n >> e) & 1; }
constexpr int_fast64_t mask(int_fast64_t n, int e) { return n & ((1 << e) - 1); }
constexpr int_fast64_t ilog(int_fast64_t x, int_fast64_t b = 2) { return x ? 1 + ilog(x / b, b) : -1; }
constexpr int_fast64_t gcd(int_fast64_t x, int_fast64_t y) {
    x = x > 0 ? x : -x, y = y > 0 ? y : -y;
    while(y) x ^= y ^= (x %= y) ^= y;
    return x;
}
constexpr int_fast64_t lcm(int_fast64_t x, int_fast64_t y) { return x ? x / gcd(x, y) * y : 0; }
int_fast64_t binry(int_fast64_t ok, int_fast64_t ng, const function<bool(int_fast64_t)> &fn) {
    while (abs(ok - ng) > 1) {
        int_fast64_t mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array, (T*)(array + N), val); }
template <class A, size_t N> void init(A (&array)[N]) { memset(array, 0, sizeof(array)); }
template <class T> vector<int> cmprs(const vector<T> &v) {
    vector<T> tmp = v; vector<int> ret;
    sort(begin(tmp),end(tmp));
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(const T &i : v) ret.emplace_back(lower_bound(begin(tmp),end(tmp),i) - begin(tmp));
    return ret;
}
template <class T> vector<int> cmprs(const T *__first, const T *__last) { return cmprs(vector<T>(__first, __last)); }
void for_subset(int_fast64_t s, const function<void(int_fast64_t)> &fn) { int_fast64_t t = s; do { fn(t); } while((--t &= s) != s); }


/* The main code follows. */


signed main()
{
    void solve();
    void input();
    void init();

    int t = 1;

    #ifdef LOCAL
        t = 1;
        // cin >> t;
    #endif

    // cin >> t;

    while(t--)
    {
        init();
        input();
        solve();
    }
}

int n,w;
int len[1<<20];
vector<vector<i64>> a,lft,rgt;

void init()
{}

void input()
{
    cin>>n>>w;
    a.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>len[i]; a[i].resize(len[i]);
        for(int j=0; j<len[i]; j++)
        {
            cin>>a[i][j];
        }
    }
    lft=rgt=a;
    for(int i=0; i<n; i++)
    {
        deque<int> stk;
        for(i64 j=0; j<len[i]; j++)
        {
            while(!stk.empty() and a[i][stk.back()]<=a[i][j])
            {
                stk.pop_back();
            }
            stk.emplace_back(j);
            lft[i][j]=a[i][stk.front()];
            if(stk.front()==j+len[i]-w)
            {
                stk.pop_front();
            }
        }
        deque<int> stk2;
        for(i64 j=len[i]-1; j>=0; j--)
        {
            while(!stk2.empty() and a[i][stk2.back()]<=a[i][j])
            {
                stk2.pop_back();
            }
            stk2.emplace_back(j);
            rgt[i][j]=a[i][stk2.front()];
            if(stk2.front()==j-len[i]+w)
            {
                stk2.pop_front();
            }
        }
    }
}

void solve()
{
    vector<vector<pll>> upd(w);
    vector<i64> now(n,0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<len[i]; j++)
        {
            i64 now=lft[i][j];
            if(j<w-len[i])
            {
                now=max(now,0LL);
            }
            upd[j].emplace_back(i,now);
        }
        for(int j=max(len[i],w-len[i]); j<w; j++)
        {
            i64 now=rgt[i][j+len[i]-w];
            if(j>=len[i])
            {
                now=max(now,0LL);
            }
            upd[j].emplace_back(i,now);
        }
        if(w>len[i]*2 and *max_element(all(a[i]))<0)
        {
            upd[len[i]].emplace_back(i,0);
        }
    }

    i64 ans=0;
    for(int j=0; j<w; j++)
    {
        if(j)
        {
            cout << " ";
        }
        for(auto &pr : upd[j])
        {
            int r; i64 nx; tie(r,nx)=pr;
            ans=ans-now[r]+nx;
            now[r]=nx;
        }
        cout << ans;
    }
    cout << "\n";
}