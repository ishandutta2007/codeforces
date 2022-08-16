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
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 998244353 ;
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

void solve(){
    int n;
    cin >> n;
    vector<long long> a(n, 1);

    cin >> a;


    long long s = 0;
    for(auto e: a){
    	s += e;
    }

    long long allow = (s - 1) >> 1;


    auto cntr = [&] (const vector<long long>& a){

    	int k = a.size();
    	mint tot = 0;
    	// trace(k);
    	mint pc = 0, cp = 0, pp = 0, cc = 0;
    	for(int j = 0; j < (1LL << k); ++j){
    		vector<int> c, p;
    		long long s = 0;

    		for(int z = 0; z < k; ++z){

    			if (j & (1LL << z)){
    				p.push_back(z);
    			}
    			else{
    				s += a[z];
    				c.push_back(z);
    			}
    		}
    		if (s > allow){
    			continue;
    		}
    		bool f = true;

    		for(int i = 1; i +  1 < c.size(); ++i){
    			if (c[i] - c[i - 1] > c[i + 1] - c[i]){
    				f = false;
    			}
    			
    		}
    		for(int i = 1; i + 1 < p.size(); ++i){
    			if (p[i] - p[i - 1] < p[i + 1] - p[i]){
    				f = false;
    			}
    		}
    		if (f){
    			if (c.size() > 0){
    				if (p[0] == 0 && c.back() == k - 1){
    					pc += 1;
    				}
    				else if (p[0] == 0 && p.back() == k -1){
    					pp += 1;
    				}
    				else if (c[0] == 0 && p.back() == k - 1){
    					cp += 1;
    				}
    				else{
    					cc += 1;
    				}
    			}
    			else{
    				pp += 1;

    			}
    			// trace(p, c);
    			// trace(s);
    			tot += 1;
    		}
    	}
    	trace(cc, cp, pc, pp);
    	return tot;
    };

    mint ways = 0;

    vector<long long> p1(n + 1), p2(n + 1);

    map<string, mint> dp;




    for(int i = 1; i <= n; ++i){
    	p1[i] = p1[i - 1] + a[i - 1];
    	p2[i] = a[i - 1];
    	if (i >= 2){
    		p2[i] += p2[i - 2];
    	}
    	if (p1[i] >= (s - allow)){
    		ways += 1;
    	}
    }



    ordered_set<pair<long long, int>> od, ev;

    // CCCCCPCPCPCPCPPPPPPPC, all c not possible.
    for(int i = n - 2; i >= 1; --i){
    	if (i & 1){
    		od.insert({p2[i], i});
    	}
    	else{
    		ev.insert({p2[i], i});
    	}

    	long long cur = p1[i] - p2[i] + a[n - 1];
    	cur = allow - cur;
    	if (i & 1){
    		dp["cc"] += od.order_of_key({cur, n + 10});
    	}
    	else{
    		dp["cc"] += ev.order_of_key({cur, n + 10});
    	}
    }
    od.clear();
    ev.clear();
    // CCCCCCPCPCPCPPPPPP
    for(int i = n - 1; i >= 1; --i){
    	if (i & 1){
    		od.insert({p2[i], i});
    	}
    	else{
    		ev.insert({p2[i], i});
    	}
    	long long cur = p1[i] - p2[i];
    	cur = allow - cur;
    	if (i & 1){
    		dp["cp"] += od.order_of_key({cur, n + 10});
    	}
    	else{
    		dp["cp"] += ev.order_of_key({cur, n + 10});
    	}
    }
    od.clear();
    ev.clear();

	// PPPPPPPPP, PCPCPCPCPCPCPPPPP, PCCCCPCPCPCPCPPPPPPP 
    dp["pp"] = 1;
    for(int k = 2; k < n; k += 2){
    	if (p2[k] <= allow)
    		dp["pp"] += 1;
    }
    for(int k = n - 1; k >= 3; --k){
    	if (k & 1){
    		od.insert({p2[k], k});
    	}
    	else{
    		ev.insert({p2[k], k});
    	}

    	long long cur = p1[k] - p1[1] - p2[k];
    	cur = allow - cur;
    	if (k & 1){
    		dp["pp"] += od.order_of_key({cur, n + 10});
    	}
    	else{
    		dp["pp"] += ev.order_of_key({cur, n + 10});
    	}
    }
    od.clear();
    ev.clear(); 

    // reverse(all(a));

    // for(int i = 1; i <= n; ++i){
    // 	p1[i] = p1[i - 1] + a[i - 1];
    // 	p2[i] = a[i - 1];
    // 	if (i >= 2){
    // 		p2[i] += p2[i - 2];
    // 	}
    // }




    // PCCCCCCCPCPCPCPCPCPPPPPC , PPPPPPPCCCCCCCCCCCCCCCCCCC
    long long allow2 = s - allow;
    for(int i = n - 2; i >= 2; --i){
    	if (i & 1){
    		od.insert({p2[i], i});
    	}
    	else{
    		ev.insert({p2[i], i});
    	}
    	long long cur = p1[i] - p1[1] - p2[i] + a[n - 1];
    	// cur = allow2 - cur;
    	cur = allow - cur;
    	if (i & 1){
    		// dp["pc"] += od.size() - od.order_of_key({cur, -1});
    		dp["pc"] += od.order_of_key({cur, n + 10});
    	}
    	else{
    		// dp["pc"] += ev.size() - ev.order_of_key({cur, -1});
    		dp["pc"] += ev.order_of_key({cur, n + 10});
    	}
    }
    for(int k = 1; k < n; ++k){
    	if (p1[n] - p1[k] <= allow){
    		dp["pc"] += 1;
    	}
    }
    od.clear();
    ev.clear();




    cout << dp["pc"] + dp["cc"] + dp["pp"] + dp["cp"] << endl;
    return;
    trace(dp);
    // trace(cc, pc, cp, pp);

    reverse(all(a));
    trace(a);
    trace(ways);
    trace(cntr(a));
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