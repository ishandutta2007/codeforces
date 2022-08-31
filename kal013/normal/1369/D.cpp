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
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
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
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
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

#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/

const int mod=1e9+7;
template<const int MOD>
struct modular_int{
	int x;
	static vector<int> inverse_list ;
	const static int inverse_limit;
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
		// Prime Mods
		if (power >= MOD){
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
// template<>   //-> useful if computing inverse fact = i_f[i-1] / i;
// const int modular_int<mod>::inverse_limit = 100000;



/*/-----------------------------Code begins----------------------------------/*/


const int N = 2e6 + 100;
mint f[N];

mint cnt[N];


mint tot[N][3];

void pre(){
	f[0] = 0;
	f[1] = 0;
	f[2] = 0;
	f[3] = 4;
	f[4] = 4;
	f[5] = 12;
	// f[6] = 24;
	for(int i = 6; i<N; i ++){
		// f[i] = 4 + 4*f[i-3] + f[i-2];
		f[i] = 4 + 4*f[i-4] + 4*f[i-3] + f[i-2];
		f[i] = max(f[i],f[i-1] + 2*f[i-2]); 
		// f[i] = 3*f[i-2] + 2*f[i-3];
		// f[i] = max(4 + 4*f[i-3] + f[i-2], 3*f[i-2] + 2*f[i-3]);
		// f[i] = 3*f[i-2] + 2*f[i-3];
		// f[i+1] = 3*f[i-1] + 2*f[i-2];
		// f[i+2] = 4 + 4*f[i-1] + f[i];
		// f[i+3] = 4 + 4*f[i] + f[i+1];

		// trace(i,f[i]);
	}

	cnt[0] = 0;
	cnt[1] = 1;
	mint c1 = 1, c2 = 0;

	for(int i = 2; i<100 ;++i){
		cnt[i] = cnt[i-1] + c1 + 2*c2;
		mint tmp = 2*c2;

		c2 = c1;
		c1 = tmp + c1;
	}

	tot[1][0] = 1;
	tot[1][1] = 0;
	tot[1][2] = 0;


	int iter = 1;


	for(int i = 2; i< 10 ; ++i){
		for(int z = i - 1; z >= iter; --z){
			tot[z+1][0] += 2*tot[z][1] + tot[z][0];
			tot[z][2] += tot[z][1];
			tot[z][1] = tot[z][0];
			tot[z][0] = 0;

		}

		while(iter <= i && tot[iter][0] == 0 && tot[iter][1] == 0){
			++iter;
		}



		// trace(i,":",iter-1);
		// for(int cur = 1; cur<=i;++cur){
		// 	trace(cur,tot[cur][0],tot[cur][1],tot[cur][2]);
		// }

	}

	// for(int z = 1; z< 50; ++z){
	// 	trace(z,tot[z][2]);
	// }
}
void solve(){

	int n;
	cin>>n;
	cout<<f[n]<<endl;
    
}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    cin>>t;
    pre();
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}