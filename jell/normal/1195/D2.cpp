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

template <int32_t mod>
struct modint {
    int x;
    constexpr modint() : x(0) {}
    constexpr modint(int_fast64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    constexpr operator bool() const { return x != 0; }

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

const int mod=998244353;
int n;
i64 a[1<<17][11];
i64 ten[19];
modint<mod> aa[1<<17][11];
modint<mod> tten[22];
modint<mod> ans,cnt[20];
int d[1<<17][11];

void solve() {
    ten[0]=1;
    rep(i,18) ten[i+1]=ten[i]*10,cnt[i]=0;

    tten[0]=1;
    rep(i,20) {
        tten[i+1]=tten[i]*modint<mod>(10);
    }

    rep(ii,n) {
        int x=a[ii][0];
        for(int i=0; i<=10; ++i){
            d[ii][i]=x%10;
            x/=10;
        } 
    }

    rep(i,n) {
        for(int d=1; d<=10; ++d) {
            if(d==10) {
                aa[i][10]=aa[i][9];
                continue;
            }
            if(d<10) a[i][d]=a[i][d-1]%ten[d*2-1]+(a[i][d-1]/ten[d*2-1])*ten[d*2];
            else a[i][d]=a[i][d-1]%ten[d*2-1]%mod+(a[i][d-1]/ten[d*2-1]%mod)*tten[d*2];
            aa[i][d]=modint<mod>(a[i][d]);
            //dump(i,d,a[i][d],aa[i][d]);
        }

        for(int j=0; j<19; ++j) {
            if(ten[j]>a[i][0]) {
                cnt[j]+=1; break;
            }
        }
    }

    

    rep(i,n) {
        modint<mod> tmp;
        
        rep(j,11) {
            ans+=cnt[j]*aa[i][j];
        }

        for(int d=1; d<=10; ++d) {
            if(d<10) a[i][d]=a[i][d-1]%ten[d*2-2]+(a[i][d-1]/ten[d*2-2])*ten[d*2-1],aa[i][d]=a[i][d];
            else aa[i][10]=modint<mod>(a[i][d-1]%ten[d*2-2])+modint<mod>(a[i][d-1]/ten[d*2-2])*tten[d*2-1];
            //dump(i,d,a[i][d],aa[i][d]);
        }

        rep(j,11) {
            ans+=cnt[j]*aa[i][j];
        }
    }
    //cout<<tten[19]<<endl;
    writeln(ans);
}

signed main() {
    // i64 x=716070898;
    // cout<<x*10%mod<<endl;
    
    cin>>n;
    rep(i,n) cin>>a[i][0];
    solve();
}