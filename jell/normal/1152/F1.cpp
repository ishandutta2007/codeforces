#pragma GCC optimize("Ofast")
#include <cassert>
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
using ui64 = uint_fast64_t;
using db = long double;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
using pdi = pair<double, int>;
template <class T> using vct = vector<T>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)1024;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832795028841971;
constexpr long double Golden = 1.61803398874989484820;
constexpr long double eps = 1e-15;

#define iostream_untie true
#define mod 1000000007LL
#define stdout_precision 10
#define stderr_precision 5
#define itr(i,v) for(auto i = begin(v); i != end(v); ++i)
#define ritr(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define fir first
#define sec second
#define u_map unordered_map
#define u_set unordered_set
#define l_bnd lower_bound
#define u_bnd upper_bound
#define rsz resize
#define ers erase
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcount

struct setupper {
    setupper() {
        if(iostream_untie) {
            ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            std::cerr.tie(nullptr);
        }
        std::cout << fixed << setprecision(stdout_precision);
        std::cerr << fixed << setprecision(stderr_precision);
#ifdef LOCAL
        if(!freopen("input.txt","rt",stdin)) {
            cerr << "Failed to open the input file.\n"; exit(EXIT_FAILURE);
        }
        // if(!freopen("output.txt","wt",stdout)) {
        //     cerr << "Failed to open the output file.\n"; exit(EXIT_FAILURE);
        // }
        // std::cerr << "\n---stderr---\n";
        // auto print_atexit = []() {
        //     std::cerr << "Exec time : " << clock() / (double)CLOCKS_PER_SEC * 1000.0 << "ms\n";
        //     std::cerr << "------------\n";
        // };
        // atexit((void(*)())print_atexit);
        // atexit((void(*)())fclose(stdin));
#endif
    }
} __setupper;

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
    template <class Tup, size_t index = tuple_size<Tup>::value - 1> struct hashval_calc {
        static void apply(size_t& seed, Tup const& tup) {
            hashval_calc<Tup, index - 1>::apply(seed, tup);
            hash_combine(seed,get<index>(tup));
        }
    };
    template <class Tup> struct hashval_calc<Tup,0> {
        static void apply(size_t& seed, Tup const& tup) {
            hash_combine(seed,get<0>(tup));
        }
    };
    template <class ...T> struct hash<tuple<T...>> {
        size_t operator()(tuple<T...> const& tup) const
        {
            size_t seed = 0;
            hashval_calc<tuple<T...>>::apply(seed,tup);
            return seed;
        }
    };
}

template <class T, class U> istream &operator>> (istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
template <class T, class U> ostream &operator<< (ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
template <class T> ostream &operator<< (ostream &s, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); ++i) s << (i ? " " : "") << v[i]; return s;
}
#define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ";\
dump_func(__VA_ARGS__)
template <class T> void dump_func(T x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(T x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T = i64> T read() { T x; return cin >> x, x; }
template <class T> void write(T x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)

namespace updater {
    template <class T> static void add(T &x, const T &y) { x += y; }
    template <class T> static void ext_add(T &x, const T &y, size_t w) { x += y * w; }
    template <class T> static void mul(T &x, const T &y) { x *= y; }
    template <class T> static void ext_mul(T &x, const T &y, size_t w) { x *= (T)pow(y,w); }
    template <class T, class U> static bool chmax(T &x, const U &y) { return x < y ? x = y,true : false; }
    template <class T, class U> static bool chmin(T &x, const U &y) { return x > y ? x = y,true : false; }
};
using updater::add;
using updater::chmax;
using updater::chmin;

template <class T> T minf(const T &x, const T &y) { return min(x,y); }
template <class T> T maxf(const T &x, const T &y) { return max(x,y); }
bool bit(i64 n, int e) { return e >= 0 ? (n >> e) & 1 : 0; }
i64 mask(i64 n, int e) { return e >= 0 ? n & ((1 << e) - 1) : 0; }
int ilog(uint64_t x, uint64_t b = 2) { return x ? 1 + ilog(x / b,b) : -1; }
template <class F> i64 binry(i64 ok, i64 ng, const F &fn) {
    while (abs(ok - ng) > 1) {
        i64 mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array,(T*)(array + N),val); }
template <class A> void cmprs(A ary[], size_t n) {
    vector<A> tmp(ary,ary + n);
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(A *i = ary; i != ary + n; ++i) *i = l_bnd(all(tmp),*i) - begin(tmp);
}
template <class T> void cmprs(vector<T> &v) {
    vector<T> tmp = v; sort(begin(tmp),end(tmp));
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(auto i = begin(v); i != end(v); ++i) *i = l_bnd(all(tmp),*i) - begin(tmp);
}
template <class F> void for_subset(uint_fast64_t s, const F &fn) {
    uint_fast64_t tmp = s;
    do { fn(tmp); } while((--tmp &= s) != s);
}


/* The main code follows. */

/* The snippet starts here. */
namespace Calcfn {
    #ifndef mod
        #define mod 1000000007LL
    #endif
    struct modint {
        int x;
        constexpr modint() : x(0) {}
        constexpr modint(int_fast64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

        constexpr modint &operator+=(const modint &p) {
            if((x += p.x) >= mod) x -= mod;
            return *this;
        }

        constexpr modint &operator ++() { return ++x,*this; }

        constexpr modint operator ++(int) {
            modint t = *this; 
            return ++x,t;
        }

        constexpr modint &operator-=(const modint &p) {
            if((x += mod - p.x) >= mod) x -= mod;
            return *this;
        }

        constexpr modint &operator --() { return --x,*this; }

        constexpr modint operator --(int) {
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

        constexpr static modint pow(modint p, uint_fast64_t e) {
            if(!e) return 1;
            if(!p) return 0;
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
        int_fast64_t fact_[N + 1],invfact_[N + 1],inv_[N + 1];

        constexpr impl() : fact_(),invfact_(),inv_() {
            fact_[0] = 1;
            for(int i = 1; i <= N; ++i) fact_[i] = fact_[i - 1] * i % mod;
            inv_[1] = 1;
            for(int i = 2; i <= N; ++i) inv_[i] = mod - inv_[mod % i] * (mod / i) % mod;
            invfact_[0] = 1;
            for(int i = 1; i <= N; ++i) invfact_[i] = invfact_[i - 1] * inv_[i] % mod;
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
        assert(x <= N_max);
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

    static modint fact(int x) {
        if(x > N) return dyn_fact(x);
        return x >= 0 ? impl_exe.fact_[x] : 0;
    }

    static modint invfact(int x) {
        if(x > N) return dyn_invfact(x);
        return x >= 0 ? impl_exe.invfact_[x] : 0;
    }

    static modint comb(int x, int y) {
        return fact(x) * invfact(y) * invfact(x - y);
    }

    static modint perm(int x, int y) {
        return comb(x,y) * fact(y);
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
using Calcfn::modint;
using Calcfn::fact;
using Calcfn::perm;
using Calcfn::comb;
/* The snippet ends here. */

template <class T>
struct matrix {
    vector<vector<T>> mat;

    matrix() {}
    matrix(size_t h, size_t w, const T v = T()) { assign(h,w,v); }

    void resize(size_t h, size_t w, const T v = T()) { mat.resize(h,vector<T>(w,v)); }

    void assign(size_t h, size_t w, const T v = T()) { mat.assign(h,vector<T>(w,v)); }

    size_t height() const { return mat.size(); }

    size_t width() const { return mat.empty() ? 0 : mat[0].size(); }

    vector<T>& operator[](const size_t i) { return mat[i]; }

    static matrix identity(size_t n) {
        matrix ret(n,n);
        for(int i = 0; i < n; ++i) ret[i][i] = 1;
        return ret;
    }

    matrix operator-() const {
        matrix ret(*this);
        for(size_t i = 0; i != height(); ++i) {
            for(size_t j = 0; j != width(); ++j) {
                ret[i][j] = -mat[i][j];
            }
        }
        return ret;
    }

    matrix operator&(matrix &x) const { return matrix(*this) &= x; }

    matrix operator|(matrix &x) const { return matrix(*this) |= x; }

    matrix operator^(matrix &x) const { return matrix(*this) ^= x; }

    matrix operator+(matrix &x) const { return matrix(*this) += x; }

    matrix operator-(matrix &x) const { return matrix(*this) -= x; }

    matrix operator*(matrix &x) const { return matrix(*this) *= x; }

    matrix operator&=(matrix &x) {
        for(size_t i = 0; i != height(); ++i) {
            for(size_t j = 0; j != width(); ++j) {
                (*this)[i][j] &= x[i][j];
            }
        }
        return *this;
    }

    matrix operator|=(matrix &x) {
        for(size_t i = 0; i != height(); ++i) {
            for(size_t j = 0; j != width(); ++j) {
                (*this)[i][j] |= x[i][j];
            }
        }
        return *this;
    }

    matrix operator^=(matrix &x) {
        for(size_t i = 0; i != height(); ++i) {
            for(size_t j = 0; j != width(); ++j) {
                (*this)[i][j] ^= x[i][j];
            }
        }
        return *this;
    }

    matrix& operator+=(matrix &x) {
        for(size_t i = 0; i != height(); ++i) {
            for(size_t j = 0; j != width(); ++j) {
                (*this)[i][j] += x[i][j];
            }
        }
        return *this;
    }

    matrix& operator-=(matrix &x) {
        for(size_t i = 0; i != height(); ++i) {
            for(size_t j = 0; j != width(); ++j) {
                (*this)[i][j] -= x[i][j];
            }
        }
        return *this;
    }

    matrix& operator*=(matrix &x) {
        matrix tmp(height(),x.width());
        for(size_t i = 0; i != height(); ++i) {
            for(size_t j = 0; j != x.height(); ++j) {
                 for(size_t k = 0; k != x.width(); ++k) {
                     tmp[i][k] += (*this)[i][j] * x.mat[j][k];
                 }
            }
        }
        return *this = tmp;
    }

    friend istream &operator>>(istream &s, matrix &x) {
        for(size_t i = 0; i != x.height(); ++i) {
            for(size_t j = 0; j != x.width(); ++j) {
                s >> x[i][j];
            }
        }
        return s;
    }

    friend ostream &operator<<(ostream &s, matrix &x) {
        for(size_t i = 0; i != x.height(); ++i) {
            for(size_t j = 0; j != x.width(); ++j) {
                s << (j ? " " : "") << x[i][j];
            }
            s << '\n';
        }
        return s;
    }

    static matrix pow(matrix x, uint_fast64_t n) {
        matrix ret = identity(x.height());
        while(n) {
            if(n & 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};

int n,k,m;
modint dp[1<<17][17][15];

signed main() {
    cin>>n>>k>>m;

    matrix<modint> mat((1<<m)*(k+1),(1<<m)*(k+1));
    for(int j=0; j<1<<m; ++j) {
        for(int h=0; h<=k; ++h) {
            int jj=mask(j<<1,m);
            int nidx=jj+h*(1<<m);
            int idx=j+h*(1<<m);
            mat[nidx][idx]+=1;
            if(h==k) continue;
            jj++;
            nidx=jj+(h+1)*(1<<m);
            mat[nidx][idx]+=popcnt(j)+1;
        }
    }

    mat=matrix<modint>::pow(mat,n);
    modint ans;
    for(int i=(1<<m)*k;i<(1<<m)*(k+1);++i) {
        ans+=mat[i][0];
    }
    esc(ans);
}