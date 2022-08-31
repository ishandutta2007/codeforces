/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

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
    size_t operator()(pair<int64_t,int64_t> Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}

#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 T){
    const static long long N = (1'000'000'000'000'000'000);
    if (T < 0){
        os << '-';
        T *= -1;
    }

    unsigned long long b = T%N;
    T /= N;
    if (T == 0)
        return os << b ;
    unsigned long long a = T % N;
    T /= N;
    if (T == 0){
        os << a;
        __int128 mul = 10;
        int cnt = 0;
        while( mul*b < N && cnt < 17){
            os << '0';
            mul *= 10;
            ++cnt;
        }
        return os << b;
    }
    os << ((long long) T);
    
     __int128 mul = 10;
      int cnt = 0;
    while( mul*a < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
    }
    os << a;
    mul = 10;
    cnt = 0;
    while( mul*b < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
    }
    return os << b;

}
istream& operator >> (istream& is, __int128& T){
    string U;
    is >> U;
    T = 0;
    size_t pos = 0;
    int mul = 1;
    if (U[pos] == '-'){
        ++pos;
        mul *= -1;
    }
    for(; pos < U.size(); ++pos){
        T *= 10;
        T += (U[pos] - '0');
    }
    T *= mul;

    return is;
}
#endif
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, ordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l,long long r){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
inline int64_t random_long(){
    uniform_int_distribution<int64_t> generator(LLONG_MIN,LLONG_MAX);
    return generator(rng);
}


/*/---------------------------Defines----------------------/*/
typedef vector<int> vi;
typedef pair<int,int> pii;

#define For(i,n) for(int i = 0; i < (int) n; ++i)
#define Rep(i,n) for(int i = 1; i <= (int) n; ++i)
#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/

const int mod = 998244353;
template<const int MOD>
struct modular_int{
    int x;
    static vector<int> inverse_list ;
    const static int inverse_limit;
    const static bool is_prime;
    modular_int(){
        x = 0;
    }
    template<typename T>  
    modular_int(const T z){
        x = (z%MOD);
        if (x < 0) x += MOD;     
    }
    modular_int(const modular_int<MOD>* z){
        x = z->x;
    }
    modular_int(const modular_int<MOD>& z){
        x = z.x;
    }
    modular_int operator - (const modular_int<MOD>& m) const{
        modular_int<MOD> U;
        U.x = x - m.x;
        if (U.x < 0) U.x += MOD;
        return U;
    }
    modular_int operator + (const modular_int<MOD>& m) const{
        modular_int<MOD> U;
        U.x = x + m.x;
        if (U.x >= MOD) U.x -= MOD;
        return U;
    }
    modular_int& operator -= (const modular_int<MOD>& m){
        x -= m.x;
        if (x < 0) x += MOD;
        return *this;
    }    
    modular_int& operator += (const modular_int<MOD>& m){
        x += m.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }    
    modular_int operator * (const modular_int<MOD>& m) const{
        modular_int<MOD> U;
        U.x = (x* 1ull * m.x) %MOD;
        return U;
    }
    modular_int& operator *= (const modular_int<MOD>& m){
        x = (x * 1ull * m.x)%MOD;
        return *this;
    }
    template<typename T>
    friend modular_int operator + (const T &l, const modular_int<MOD>& p){
        return (modular_int<MOD>(l) + p);
    }
    template<typename T>
    friend modular_int operator - (const T &l, const modular_int<MOD>& p){
        return (modular_int<MOD>(l) - p);
    }
    template<typename T>
    friend modular_int operator * (const T &l, const modular_int<MOD>& p){
        return (modular_int<MOD>(l) * p);
    }
    template<typename T>
    friend modular_int operator / (const T &l, const modular_int<MOD>& p){
        return (modular_int<MOD>(l) / p);
    }

    int value() const{
        return x;
    }

    modular_int operator ^ (const modular_int<MOD>& cpower) const{
        modular_int<MOD> ans;
        ans.x = 1;
        modular_int<MOD> curr(this);
        int power = cpower.x;

        if (curr.x <= 1){
            if (power == 0) curr.x = 1;
            return curr;
        }
        while( power > 0){
            if (power&1){
                ans *= curr;
            }
            power >>= 1;
            if (power) curr *= curr;
        }
        return ans;
    }


    modular_int operator ^ (long long power) const{
        modular_int<MOD> ans;
        ans.x = 1;
        modular_int<MOD> curr(this);
        if (curr.x <= 1){
            if (power == 0) curr.x = 1;
            return curr;
        }
        // Prime Mods
        if (power >= MOD && is_prime){
            power %= (MOD - 1);
        }

        while( power > 0){
            if (power&1){
                ans *= curr;
            }
            power >>= 1;
            if (power) curr *= curr;

        }
        return ans;
    }

    modular_int operator ^ (int power) const{
        modular_int<MOD> ans;
        ans.x = 1;
        modular_int<MOD> curr(this);
        
        if (curr.x <= 1){
            if (power == 0) curr.x = 1;
            return curr;
        }
        while( power > 0){
            if (power&1){
                ans *= curr;
            }
            power >>= 1;
            if (power) curr *= curr;

        }
        return ans;
    }
    
    template<typename T>
    modular_int& operator ^= (T power) {
        modular_int<MOD> res = (*this)^power;
        x = res.x;
        return *this;
    }


    template<typename T>
    modular_int pow(T x){
        return (*this)^x;
    }

    
    pair<long long,long long> gcd(const int a, const int b) const {
        if (b==0) return {1,0}; 
        pair<long long,long long> c = gcd(b , a%b);
        return { c.second , c.first - (a/b)*c.second}; 
    }

    inline void init_inverse_list() const {
        
        vector<int>& dp = modular_int<MOD>::inverse_list;
        dp.resize(modular_int<MOD>::inverse_limit + 1);
        int n = modular_int<MOD>::inverse_limit;
        dp[0] = 1;
        if (n > 1) dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = (dp[MOD%i] * 1ull *(MOD - MOD/i))%MOD;
        }
    
    }
    modular_int<MOD> get_inv() const {
        if (modular_int<MOD>::inverse_list.size() < modular_int<MOD>::inverse_limit + 1) init_inverse_list();

        if (this->x <= modular_int<MOD>::inverse_limit){
            return modular_int<MOD>::inverse_list[this->x];
        }
        pair<long long,long long> G = gcd(this->x,MOD);
        return modular_int<MOD>(G.first);
    }
    modular_int<MOD> operator - () const {
        modular_int<MOD> v(0);
        v -= (*this);
        return v;
    }
    modular_int operator / (const modular_int<MOD>& m) const{
        modular_int<MOD> U(this);
        U *= m.get_inv();
        return U;
    }
    modular_int& operator /= (const modular_int<MOD>& m){
        (*this) *= m.get_inv();
        return *this;
    }
    bool operator==(const modular_int<MOD>& m) const{
        return x == m.x;
    }

    bool operator < (const modular_int<MOD>& m) const {
        return x < m.x;
    }


    template<typename T>
    bool operator == (const T& m) const{
        return (*this)== (modular_int<MOD>(m));
    }

    template<typename T>
    bool operator < (const T& m) const {
        return x < (modular_int<MOD>(m)).x;
    }
    template<typename T>
    bool operator > (const T& m) const {
        return x > (modular_int<MOD>(m)).x;
    }
    template<typename T>
    friend bool operator == (const T& x, const modular_int<MOD>& m) {
        return (modular_int<MOD>(x)).x == m.x;
    }
    template<typename T> 
    friend bool operator < (const T& x, const modular_int<MOD>& m){
        return (modular_int<MOD>(x)).x < m.x;
    }
    template<typename T> 
    friend bool operator > (const T& x, const modular_int<MOD>& m){
        return (modular_int<MOD>(x)).x > m.x;
    }

    friend istream& operator >> (istream& is, modular_int<MOD>& p){
        int64_t val;
        is >> val;
        p.x = (val%MOD);
        if (p.x < 0) p.x += MOD;
        return is;
    }
    friend ostream& operator << (ostream& os, const modular_int<MOD>& p) {return os<<p.x;}



};



using mint = modular_int<mod>;
template<const int MOD>
vector<int> modular_int<MOD>::inverse_list ;
template<const int MOD>
const int modular_int<MOD>::inverse_limit = -1;
template<const int MOD>
const bool modular_int<MOD>::is_prime = true;
// template<>   //-> useful if computing inverse fact = i_f[i-1] / i;
// const int modular_int<mod>::inverse_limit = 100000;



/*/-----------------------------Code begins----------------------------------/*/
const int N = 1600;
int arr[N][N];
inline bool cmp(const pair<int,int>& A, const pair<int,int>& B){
	return arr[A.first][A.second] < arr[B.first][B.second];
}

int dsu[N], sz[N], cnt[N];
vector<mint> dp[N];

inline int Find(int n){
    return (n == dsu[n]) ? n : dsu[n] = Find(dsu[n]);
}

void Merge(int x, int y){
    x = Find(x);
    y = Find(y);

    if (x == y){
        --cnt[x];
        if (cnt[x] == 0){
            dp[x][1] += 1;
        }
        return;
    }

    if (sz[x] < sz[y]){
        swap(x, y);
    }

    cnt[x] += cnt[y] + sz[x] * sz[y] - 1;
    dsu[y] = x;
    sz[x] += sz[y];

   
    vector<mint> new_ans(sz[x] + 1, 0);

    for(int i = 0; i < dp[x].size(); ++i){
        for(int j = 0; j < dp[y].size(); ++j){
            new_ans[i + j] += dp[x][i] * dp[y][j];
        }
    }

    if (cnt[x] == 0){
        new_ans[1] += 1;
    }

    dp[y].clear();
    dp[x].clear();
    swap(dp[x], new_ans);



}



void solve(){
	int n;
	cin >> n;

	
	vector<pair<int,int>> moves;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> arr[i][j];
			if (i < j){
				moves.push_back({i, j});
			}
		}
	}
    sort(all(moves), cmp);
    for(int i = 1;  i <= n; ++i){
        dsu[i] = i;
        sz[i] = 1;
        cnt[i] = 0;
        dp[i].push_back(0);
        dp[i].push_back(1);
    }

    for(auto e: moves){
        Merge(e.first, e.second);
    }

    for(int i = 1; i <= n; ++i){
        if (Find(i) == i){
            for(int j = 1; j <= n; ++j){
                cout << dp[i][j] << " "; 
            }
            cout << endl;
        }
    }


	
}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    //cin >> t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}