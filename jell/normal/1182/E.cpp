#ifndef LOCAL
    #pragma GCC optimize("Ofast")
#endif
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
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
using pdi = pair<double, int>;
using pdd = pair<double, double>;
template <class T> using vct = vector<T>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)16;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832795028;
constexpr long double Golden = 1.61803398874989484820;
constexpr long double eps = 1e-15;

#define iostream_untie true
#define mod 1000000006LL
#define stdout_precision 10
#define stderr_precision 10
#define itrep(i,v) for(auto i = begin(v); i != end(v); ++i)
#define ritrep(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
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
                std::cerr << "Failed to open the stderr file\n";
                freopen("CON","wt",stderr);
            }
            if(!freopen("stdout.txt","wt",stdout)) {
                std::cerr << "Failed to open the stdout file\n";
                freopen("CON","wt",stdout);
            }
            if(!freopen("stdin.txt","rt",stdin)) {
                std::cerr << "Failed to open the stdin file.\n";
                freopen("CON","rt",stdin);
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
template <class T = i64> T read() { T x; return cin >> x, x; }
template <class T> void write(T x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
template <class T> void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)

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
        return pow(p * p, e >> 1) * (e & 1 ? p : 1);
    }

    friend ostream &operator<<(ostream &s, const modint &p) { return s << p.x; }

    friend istream &operator>>(istream &s, modint &p) {
        uint_fast64_t x;
        p = modint((s >> x,x));
        return s;
    }
};

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
        for(size_t i = 0; i < n; ++i) ret[i][i] = 1;
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

    static matrix pow(matrix x, int_fast64_t n) {
        if(n < 0) n = 0;
        matrix ret = identity(x.height());
        while(n) {
            if(n & 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};


i64 mpow(i64 r, i64 n, i64 m=1000000007) {
    if(!n) return 1;
    return mpow(r%m*r%m,n/2,m) * (n&1 ? r%m:1) %m;
}

i64 a,b,c,d,n;
i64 ans=1;

signed main() {

    cin>>n>>a>>b>>c>>d;
    a=a*d%1000000007;
    b=b*d%1000000007*d%1000000007;
    c=c*d%1000000007*d%1000000007*d%1000000007;

    matrix<modint> ma(3,3);
    ma[0]={1,1,1};
    ma[1]={1,0,0};
    ma[2]={0,1,0};
    ma=matrix<modint>::pow(ma,n-3);
    i64 ea=ma[0][2].x;
    i64 eb=ma[0][1].x;
    i64 ec=ma[0][0].x;
    ans=mpow(a,ea)*mpow(b,eb)%1000000007*mpow(c,ec)%1000000007;
    i64 dinv=mpow(d,1e9+5,1e9+7);
    ans=ans*mpow(dinv,n,1e9+7)%1000000007;
    cout<<ans<<endl;

}