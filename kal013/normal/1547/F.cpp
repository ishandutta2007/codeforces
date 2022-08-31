/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

/*/---------------------------IO(Debugging)----------------------/*/
template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
    return (out << "}");
}
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;



const int N = 2e5 + 100;
const int mlog = 20;



template< typename T, const int M , T (*Op)(const T& ,const  T&) = std::min<T> >
struct RMQ{
    // Tested : https://www.spoj.com/problems/RMQSQ/
    int offset;
    vector<T> rmq[M];
    static vector<int> log_2;
    void clear(){
        for(int i = 0 ; i < M ;++i) rmq[i].clear();
    }
    void init(vector<T>& V,int off = 0){
        offset = off;
        if (log_2.size() == 0) {log_2.push_back(0);log_2.push_back(0);}

        int n = V.size() - off;
        for(int i = 0; i < M; ++i){
            rmq[i].resize(n);
        }
        for(int i = 0; i < n; ++i){
            rmq[0][i] = V[i + off];
        }
        for(int j = 1; j < M; ++j){
            int powr = (1 << (j-1));
            for(int i = 0 ; i < n; ++i){
                if (i + powr >= n){
                    rmq[j][i] = rmq[j-1][i];
                }
                else{
                    rmq[j][i] = Op(rmq[j-1][i],rmq[j-1][i + powr]);
                }
            }
        }

        if (log_2.size() <= n){
            int k = log_2.size();
            log_2.reserve( n + 1);
            for(int i = k; i <= n; ++i){
                log_2.push_back(log_2[i / 2] + 1);
            }
        }
    }
    void init(T arr[], int N,int off = 0){
        offset = off;
        if (log_2.size() == 0) {log_2.push_back(0);log_2.push_back(0);}

        int n = N;
        for(int i = 0; i < M; ++i){
            rmq[i].resize(n);
        }
        for(int i = 0; i < n; ++i){
            rmq[0][i] = arr[i + off];
        }
        for(int j = 1; j < M; ++j){
            int powr = (1 << (j-1));
            for(int i = 0 ; i < n; ++i){
                if (i + powr >= n){
                    rmq[j][i] = rmq[j-1][i];
                }
                else{
                    rmq[j][i] = Op(rmq[j-1][i],rmq[j-1][i + powr]);
                }
            }
        }

        if (log_2.size() <= n){
            int k = log_2.size();
            log_2.reserve( n + 1);
            for(int i = k; i <= n; ++i){
                log_2.push_back(log_2[i / 2] + 1);
            }
        }
        assert(M > log_2[n]);
    }
    T query(int l,int r){
        assert(l <= r);
        l -= offset;
        r -= offset;
        int dist = log_2[r - l + 1];
        return Op(rmq[dist][l] , rmq[dist][r - (1ll << dist) + 1]);
    }


};


template<typename T, const int M , T (*Op)(const T& ,const  T&)  >
vector<int> RMQ<T,M,Op>::log_2 ;


int GCD (const int& a, const int& b){
	int c = __gcd(a, b);
	return c;
}
RMQ<int,mlog,GCD> device;



/*/-----------------------------Code begins----------------------------------/*/

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int g = 0;
    for(auto e: a){
    	g = __gcd(e, g);
    }
    device.clear();
    device.init(a);

    auto calc = [&] (int idx, int k){
    	int l = idx, r = idx + k;
    	int ans = 0;
    	if (r >= n){
    		ans = device.query(0, r - n);
    	}
    	ans = __gcd(ans, device.query(l, min(r, n - 1)));
    	return ans;
    };

    int steps = 0;
    for(int i = 0; i < n; ++i){

    	while(calc(i, steps) != g){
    		++steps;
    	}
    }
    cout << steps << endl;
}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}