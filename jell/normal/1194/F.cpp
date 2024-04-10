#ifndef LOCAL
    #pragma GCC optimize("Ofast")
#endif
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>

using namespace std;
using i64 = int_fast64_t;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)2 - (T)123456;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832;
constexpr long double Golden = 1.61803398874989484820;

#define iostream_untie true
#define stdout_precision 10
#define stderr_precision 10
#define itrep(i,v) for(auto i = begin(v); i != end(v); ++i)
#define ritrep(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
#define rep(i,n) for(int_fast64_t i = 0; i < (int_fast64_t)(n); ++i)
#define rrep(i,n) for(int_fast64_t i = (int_fast64_t)(n) - 1; i >= 0; --i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define fir first
#define sec second
#define u_map unordered_map
#define u_set unordered_set
#define l_bnd lower_bound
#define u_bnd upper_bound
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcount

namespace setup {
    struct setupper {
        setupper() {
            if(iostream_untie) {
                ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
                std::cout.tie(nullptr);
                std::cerr.tie(nullptr);
            }
            std::cout << std::fixed << std::setprecision(stdout_precision);
            std::cerr << std::fixed << std::setprecision(stderr_precision);
    #ifdef LOCAL
            if(!freopen("stderr.txt","wt",stderr)) {
                freopen("CON","wt",stderr);
                std::cerr << "Failed to open the stderr file\n";
            }
            if(!freopen("stdout.txt","wt",stdout)) {
                freopen("CON","wt",stdout);
                std::cerr << "Failed to open the stdout file\n";
            }
            if(!freopen("stdin.txt","rt",stdin)) {
                freopen("CON","rt",stdin);
                std::cerr << "Failed to open the stdin file.\n";
            }
            // auto print_atexit = []() {
            //     std::cerr << "Exec time : " << clock() / (double)CLOCKS_PER_SEC * 1000.0 << "ms\n";
            //     std::cerr << "------------\n";
            // };
            // atexit((void(*)())print_atexit);
    #endif
        }
    } __setupper;
}

namespace std {
    template <class RAitr> void rsort(RAitr __first, RAitr __last) {
        sort(__first, __last, greater<>());
    }
    template <class T> void hash_combine(size_t &seed, T const &key) {
        seed ^= hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    template <class T, class U> struct hash<pair<T,U>> {
        size_t operator()(pair<T,U> const &pr) const
        {
            size_t seed = 0;
            hash_combine(seed,pr.first);
            hash_combine(seed,pr.second);
            return seed;
        }
    };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct hashval_calc {
        static void apply(size_t& seed, tuple_t const& t) {
            hashval_calc<tuple_t, index - 1>::apply(seed, t);
            hash_combine(seed,get<index>(t));
        }
    };
    template <class tuple_t>
    struct hashval_calc<tuple_t, 0> {
        static void apply(size_t& seed, tuple_t const& t) {
            hash_combine(seed,get<0>(t));
        }
    };
    template <class ...T> struct hash<tuple<T...>> {
        size_t operator()(tuple<T...> const& t) const
        {
            size_t seed = 0;
            hashval_calc<tuple<T...>>::apply(seed,t);
            return seed;
        }
    };
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
#define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ";\
dump_func(__VA_ARGS__)
template <class T> void dump_func(T x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(T x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T> void write(T x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
template <class P> void read(P __first, P __second) {
    for(P i = __first; i != __second; ++i) cin >> *i;
}

namespace updater {
    template <class T> static void add(T &x, const T &y) { x += y; }
    template <class T> static void ext_add(T &x, const T &y, size_t w) { x += y * w; }
    template <class T> static void mul(T &x, const T &y) { x *= y; }
    template <class T> static void ext_mul(T &x, const T &y, size_t w) { x *= (T)pow(y,w); }
    template <class T> static bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
    template <class T> static bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
};
using updater::add;
using updater::chmax;
using updater::chmin;

template <class T> constexpr T minf(const T &x, const T &y) { return min(x,y); }
template <class T> constexpr T maxf(const T &x, const T &y) { return max(x,y); }
constexpr bool bit(i64 n, int e) { return (n >> e) & 1; }
constexpr int_fast64_t mask(int_fast64_t n, int e) { return n & ((1 << e) - 1); }
constexpr int ilog(int_fast64_t x, int_fast64_t b = 2) { return x ? 1 + ilog(x / b, b) : -1; }
int_fast64_t binry(int_fast64_t ok, int_fast64_t ng, const function<bool(int_fast64_t)> &fn) {
    while (abs(ok - ng) > 1) {
        int_fast64_t mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array,(T*)(array + N),val); }
template <class T> vector<int> cmprs(const vector<T> &v) {
    vector<T> tmp = v; vector<int> ret;
    sort(begin(tmp),end(tmp));
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(T i : v) ret.emplace_back(lower_bound(begin(tmp),end(tmp),i) - begin(tmp));
    return ret;
}
template <class T> vector<int> cmprs(const T *__first, const T *__last) {
    return cmprs(vector<T>(__first, __last));
}
void for_subset(int_fast64_t s, const function<void(int_fast64_t)> &fn) {
    int_fast64_t tmp = s;
    do { fn(tmp); } while((--tmp &= s) != s);
}



/* The main code follows. */

/* The snippet starts here. */
namespace Calcfn {
    constexpr int mod = 1e9 + 7;

    template <int32_t mod>
    struct modint {
        int x;
        constexpr modint() : x(0) {}
        constexpr modint(int_fast64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

        // constexpr operator bool() const { return x != 0; }

        constexpr modint &operator+=(const modint &p) {
            if((x += p.x) >= mod) x -= mod;
            return *this;
        }

        constexpr modint &operator++() { return ++x,*this; }

        constexpr modint operator++(int) {
            modint t = *this;
            return ++x,t;
        }

        constexpr modint &operator-=(const modint &p) {
            if((x += mod - p.x) >= mod) x -= mod;
            return *this;
        }

        constexpr modint &operator--() { return --x, *this; }

        constexpr modint operator--(int) {
            modint t = *this;
            return --x,t;
        }

        constexpr modint &operator*=(const modint &p) {
            x = (int) (1LL * x * p.x % mod);
            return *this;
        }

        constexpr modint &operator/=(const modint &p) {
            *this *= inverse(p);
            return *this;
        }

        constexpr modint operator-() { return modint(-x); }

        constexpr modint operator+(const modint &p) { return modint(*this) += p; }

        constexpr modint operator-(const modint &p) { return modint(*this) -= p; }

        constexpr modint operator*(const modint &p) { return modint(*this) *= p; }

        constexpr modint operator/(const modint &p) { return modint(*this) /= p; }

        constexpr bool operator==(const modint &p) { return x == p.x; }

        constexpr bool operator!=(const modint &p) { return x != p.x; }

        constexpr bool operator!() { return !x; }

        constexpr bool operator>(const modint &p) { return x > p.x; }

        constexpr bool operator<(const modint &p) { return x <  p.x; }

        constexpr bool operator>=(const modint &p) { return x >= p.x; }

        constexpr bool operator<=(const modint &p) { return x <= p.x; }

        constexpr static modint inverse(const modint &p) {
            int a = p.x, b = mod, u = 1, v = 0;
            while(b > 0) {
                int t = a / b;
                a -= t * b;
                a ^= b ^= a ^= b;
                u -= t * v;
                u ^= v ^= u ^= v;
            }
            return modint(u);
        }

        constexpr static modint pow(modint p, int_fast64_t e) {
            if(!e) return 1;
            if(e < 0) e = (e % (mod - 1) + mod - 1) % (mod - 1);
            return pow(p * p, e >> 1) * (e & 1 ? p : 1);
        }

        friend ostream &operator<<(ostream &s, const modint &p) { return s << p.x; }

        friend istream &operator>>(istream &s, modint &p) {
            uint_fast64_t x;
            p = modint((s >> x,x));
            return s;
        }
    };

    constexpr static int N = 2e5 + 2e4, N_max = 2e6 + 2e5;

    struct impl {
        int_fast64_t fact_[N + 1], invfact_[N + 1], inv_[N + 1];

        constexpr impl() : fact_(),invfact_(),inv_() {
            fact_[0] = 1;
            for(int i = 1; i <= N; ++i) fact_[i] = fact_[i - 1] * i % mod;
            inv_[1] = 1;
            for(int i = 2; i <= N && i < mod; ++i) inv_[i] = mod - inv_[mod % i] * (mod / i) % mod;
            invfact_[0] = 1;
            for(int i = 1; i <= N && i < mod; ++i) invfact_[i] = invfact_[i - 1] * inv_[i] % mod;
        }
    };
    constexpr static impl impl_exe;

    int_fast64_t _dyn_fact[N_max + 1];
    int_fast64_t _dyn_inv[N_max + 1];
    int_fast64_t _dyn_invfact[N_max + 1];

    static int_fast64_t dyn_fact(int x) {
        assert(x <= N_max);
        if(x < 0) return 0;
        static size_t _size = 1;
        for(size_t &i = _size; i <= x; ++i) {
            if(i <= N) _dyn_fact[i] = impl_exe.fact_[i];
            else _dyn_fact[i] = _dyn_fact[i - 1] * i % mod;
        }
        return _dyn_fact[x];
    }

    static int_fast64_t dyn_invfact(int x) {
        assert(x <= N_max && x < mod);
        if(x < 0)  return 0;
        static size_t _size = 1;
        for(size_t &i = _size; i <= x; ++i) {
            if(i <= N) {
                _dyn_inv[i] = impl_exe.inv_[i];
                _dyn_invfact[i] = impl_exe.invfact_[i];
            } else {
                _dyn_inv[i] = mod - _dyn_inv[mod % i] * (mod / i) % mod;
                _dyn_invfact[i] = _dyn_invfact[i - 1] * _dyn_inv[i] % mod;
            }
        }
        return _dyn_invfact[x];
    }

    static modint<mod> fact(int x) {
        if(x > N) return dyn_fact(x);
        return x >= 0 ? impl_exe.fact_[x] : 0;
    }

    static modint<mod> invfact(int x) {
        assert(x < mod);
        if(x > N) return dyn_invfact(x);
        return x >= 0 ? impl_exe.invfact_[x] : 0;
    }

    static modint<mod> binom(int x, int y) {
        return fact(x) * invfact(y) * invfact(x - y);
    }

    static modint<mod> perm(int x, int y) {
        return binom(x, y) * fact(y);
    }

    constexpr static int_fast64_t gcd(int_fast64_t a, int_fast64_t b) {
        if(!b) return a > 0 ? a : -a; return gcd(b, a % b);
    }

    constexpr static int_fast64_t lcm(int_fast64_t a, int_fast64_t b) {
        if(a | b) return a / gcd(a, b) * b; return 0;
    }

    constexpr static int_fast64_t ext_gcd(int_fast64_t a, int_fast64_t b, int_fast64_t &x, int_fast64_t &y) {
        int_fast64_t d = a;
        if (b) d = ext_gcd(b, a % b, y, x), y -= (a / b) * x;
        else x = 1, y = 0;
        return d;
    }
}
using Calcfn::mod;
using Calcfn::modint;
using Calcfn::fact;
using Calcfn::invfact;
using Calcfn::perm;
using Calcfn::binom;
/* The snippet ends here. */

i64 n,T;
i64 t[1<<18];
modint<mod> ans;

void solve() {
    cin>>n>>T;
    rep(i,n) cin>>t[i];
    i64 tot=0;
    modint<mod> ipw=1,bins=1;
    bool flag=false;
    for(int i=0,xi=0; i<n; ++i) {
        ipw/=2;
        tot+=t[i];
        if(tot+i+1<=T) {
            ans++;
            xi++;
            bins*=2;
        } else {
            flag=true;
            if(T-tot<0) {
                break;
            }
            while(xi>T-tot) {
                bins-=binom(i,xi);
                xi--;
            }
            bins=bins*modint<mod>(2)-binom(i,xi);
            ans+=ipw*bins;
        }
    }
    cout<<ans<<"\n";
}

signed main() {
    solve();
}