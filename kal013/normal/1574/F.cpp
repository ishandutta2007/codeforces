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


template<typename T>
using fast_set = gp_hash_table<T, null_type, custom_hash>;

template<typename L, typename R>
using fast_map = gp_hash_table<L, R, custom_hash>;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n);
    vector<bool> block(k), once(k);

    int filler = k;
    vector<vector<int>> adj(k);

    for(int i = 0; i < n; ++i){
    	int c;
    	cin >> c;
    	a[i].resize(c);
    	cin >> a[i];    	
    }

    sort(all(a), [&] (const vector<int>& x, const vector<int>& y){
    	return x.size() < y.size();
    });


    {
    	vector<vector<int>> b;
    	for(int i = 0; i < n; ++i){
    		for(auto &e: a[i])
    			--e;

    		gp_hash_table<int, null_type, custom_hash> cur;
    		for(auto &e: a[i]){
    			cur.insert(e);
    			once[e] = true;
    		}
    		if (cur.size() != a[i].size()){
    			for(auto &e: a[i])
    				block[e] = true;
    		}
    		else{
    			for(auto &e: a[i]){
    				adj[e].push_back(b.size());
    			}
    			b.push_back(a[i]);
    		}
    	}
    	swap(a, b);
    	n = a.size();
    }


    auto is_subarray = [] (const vector<int>& a, fast_map<int, int>& b){
    	// O(|a|).
    	if (a.size() > b.size()){
    		assert (false);
    	}
    	int n = a.size();
    	vector<int> t;
    	for(int i = 0; i < n; ++i){
    		if (b.find(a[i]) == b.end())
    			return false;
    		t.push_back(b[a[i]]);
    	}
    	for(int i = 1; i < n; ++i){
    		if (t[i] != t[i - 1] + 1)
    			return false;
    	}
    	return true;
    };


    vector<bool> ignore(n);
    vector<bool> care_of(n);


    auto merge_arrays = [] (const vector<int>& a, const vector<int>& b, vector<int>& ans) -> bool{
    	assert (a.size() <= b.size());
    	fast_map<int, int> t;
    	for(int z = 0; z < b.size(); ++z){
    		t[b[z]] = z;
    	}
    	assert (t.size() == b.size());
    	vector<array<int, 2>> common;
    	for(int i = 0; i < a.size(); ++i){
    		if (t.find(a[i]) != t.end())
    			common.push_back({i, t[a[i]]});
    	}
    	assert (common.size() > 0);

    	for(int k = 1; k < common.size(); ++k){
    		if (common[k][0] - common[k - 1][0] != 1)
    			return false;
    		if (common[k][1] - common[k - 1][1] != 1)
    			return false;
    	}


    	if (common[0][0] == 0 && common.back()[1] + 1 == b.size()){
    		ans = b;
    		for(int j = common.size(); j < a.size(); ++j){
    			ans.push_back(a[j]);
    		}
    	}
    	else if (common.back()[0] + 1 == a.size() && common[0][1] == 0){
    		ans = a;
    		for(int j = common.size();  j < b.size(); ++j){
    			ans.push_back(b[j]);
    		}
    	}
    	else{
    		return false;
    	}
    	return true;
    };


    	vector<int> dsu(n, -1);

    	auto Find = [&] (const auto& self, int x) -> int{
    		return dsu[x] < 0 ? x : dsu[x] = self(self, dsu[x]);
    	};
    	auto Merge = [&] (int x, int y){
    		x = Find(Find, x);
    		y = Find(Find, y);
    		if (x == y)
    			return false;
    		if (dsu[x] > dsu[y])
    			swap(x, y);
    		dsu[x] += dsu[y];
    		dsu[y] = x;
    		return true;
    	};
    {
    	



    	vector<fast_map<int, int>> pos(n);
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < a[i].size(); ++j){
    			pos[i][a[i][j]] = j;
    		}
    	} 
    	

    	auto add_vector = [&] (const vector<int>& p){
    		a.push_back(p);
    		++n;
    		fast_map<int, int> cur;
    		for(int j = 0; j < p.size(); ++j){
    			cur[p[j]] = j;
    		}
    		pos.push_back(cur);
    		dsu.push_back(-1);
    		ignore.push_back(false);
    		care_of.push_back(false);
    		return n - 1;
    	};

    	for(int z = 0; z < k; ++z){
    		if (adj[z].empty())
    			continue;
    		// assert (pos.size() == n && a.size() == n && dsu.size() == n);
    		assert (once[z]);

	
			set<array<int, 2>> arrs;

			bool all_break = false;	

			for(auto j: adj[z]){
				int J = Find(Find, j);
				if (ignore[J])
					all_break = true;
				arrs.insert({a[J].size(), J});
			}    	

			while (arrs.size() > 1 && !all_break){
				auto x1 = *arrs.begin();
				arrs.erase(x1);
				auto x2 = *arrs.begin();
				arrs.erase(x2);

				if (is_subarray(a[x1[1]], pos[x2[1]])){
					care_of[x1[1]] = true;

					assert (dsu[x1[1]] == -1);
					dsu[x1[1]] = x2[1];
					arrs.insert(x2);
					continue;
				}
				vector<int> nw;
				if (merge_arrays(a[x1[1]], a[x2[1]], nw)){
					int new_idx = add_vector(nw);
					care_of[x1[1]] = true;
					care_of[x2[1]] = true;
					a[x1[1]].clear(); a[x1[1]].shrink_to_fit();
					a[x2[1]].clear(); a[x2[1]].shrink_to_fit();

					dsu[x1[1]] = new_idx; dsu[x2[1]] = new_idx;
					arrs.insert({a[new_idx].size(), new_idx});
				}
				else{
					arrs.insert(x1);
					arrs.insert(x2);
					all_break = true;
					break;
				}
			}

			if (all_break){
				for(auto &e: arrs){
					ignore[e[1]] = true;
				}
			}

    	}



    }

    {

    	for(int i = 0; i < n; ++i){
    		if (ignore[i]){
    			for(auto &e: a[i])
    				block[e] = true;
    		}
    	}


    	vector<int> bfs;
    	for(int i = 0; i < k; ++i){
    		if (block[i])
    			bfs.push_back(i);
    	}

    	for(int j = 0; j < bfs.size(); ++j){
    		for(auto z: adj[bfs[j]]){
    			z = Find(Find, z);
    			if (ignore[z])
    				continue;
    			ignore[z] = true;

    			for(auto e: a[z]){
    				if (block[e])
    					continue;
    				block[e] = true;
    				bfs.push_back(e);
    			}
    		}
    	}
    	vector<vector<int>> cur;
    	for(int i = 0; i < n; ++i){
    		if (ignore[i] || care_of[i])
    			continue;
    		cur.push_back(a[i]);
    	}
    	swap(a, cur);
    	n = a.size();
  		sort(all(a), [&] (const vector<int>& x, const vector<int>& y){
  			return x.size() < y.size();
  		});
    }


    vector<array<int, 2>> transitions;
    mint mult;

    {
    	vector<int> lens;
	    int filler = k;
	    for(int i = 0; i < k; ++i)
	    	filler -= once[i];
	    mult = filler;

	    for(auto &e: a){
	    	lens.push_back(e.size());
	    }

	    sort(all(lens));
	    int cnt = 0, prv = -1;
	    for(auto &e: lens){
	    	if (e == prv)
	    		++cnt;
	    	else{
	    		if (cnt > 0)
	    			transitions.push_back({prv, cnt});
	    		cnt = 1;
	    		prv =e ;
	    	}
	    }
	    if (cnt > 0)
	    	transitions.push_back({prv, cnt});
    }

	vector<mint> dp(m + 1);
	dp[0] = 1;

	for(int i = 1; i <= m; ++i){
		dp[i] = dp[i - 1] * mult;
		for(auto &e: transitions){
			if (e[0] > i)
				break;
			dp[i] += dp[i - e[0]] * e[1];
		} 
	}    
	cout << dp[m] << endl;
}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}