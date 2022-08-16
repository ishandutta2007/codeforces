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

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
istream& operator >> (istream &is, T_container &v) { 
   for(T &x : v) is >> x; return is;
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

template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) { 
   return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator << (ostream &os, const T_container &v) { 
   os << '{'; string sep; 
   for (const T &x : v) os << sep << x, sep = ", "; 
   return os << '}'; 
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
    out << "{"; string sep;
    while(!U.empty()){
        out << sep << U.front(); sep = ", "; U.pop();
    }
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
         int count_open = 0, len = 1;
         for(int k = 1; ; ++k){
            char cur = *(names + k);
            count_open += (cur == '(' ? 1 : (cur == ')' ? -1: 0));
            if (cur == ',' && count_open == 0){
               const char* comma = names + k;
               cerr.write(names, len) << " : " << arg1 << " | ";
               __f(comma + 1, args...);
               return;
            }
            len = (cur == ' ' ? len : k + 1);
         }
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
    static uint64_t splitmix64(uint64_t x) { // http://xorshift.di.unimi.it/splitmix64.c
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
#define endl "\n"
#define all(v) (v).begin(),(v).end()
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


namespace NumberTheory{
	template<const size_t N>
	struct sieve{
		static array<int, N + 1> lp;
		static vector<int> primes;
		sieve() {
			if (primes.empty()){
				for(int i = 2; i <= N; ++i)
					lp[i] = 0;
				lp[1] = 1;
				for(int i = 2; i <= N; ++i){
					if (lp[i] == 0){
						lp[i] = i;
						sieve<N>::primes.push_back(i);
					}
					for(int j = 0; j < static_cast<int>(primes.size()) && primes[j] <= lp[i]; ++j){
						int x = i * primes[j];
						if (x > N)
							break;
						lp[x] = primes[j];
					}
				}	
				assert (!primes.empty());
			}
		}
		template<typename T>
		bool isPrime(T x) const {
			return (x > 1 && static_cast<T>(lp[x]) == x);
		}

		template<typename T>
		vector<T> divisors (T x) const {
			vector<T> ans = {1};
			while (x > 1){
				int v = lp[x], cnt = 0;
				while (lp[x] == v){
					x /= v;
					++cnt;
				}
				int n = ans.size() * cnt;

				for(int i = 0; i < n; ++i){
					ans.push_back(ans[i] * v);
				}
			}
			return ans;
		}
		template<typename T>
		vector<array<T, 2>> factorisation (T x) const {
			vector<array<T, 2>> f;
			while (x > 1){
				int v = lp[x], cnt = 0;
				while(lp[x] == v){
					x /= v;
					++cnt;
				}
				f.push_back({static_cast<T>(v), static_cast<T>(cnt)});
			}
			return f;
		}
		template<typename T>
		T num_divisors (T x) const {
			T ans = 1;
			while (x > 1){
				int v = lp[x], cnt = 0;
				while(lp[x] == v){
					x /= v;
					++cnt;
				}
				ans *= (cnt + 1);
			}
			return ans;
		}

		template<typename T>
		T phi(T x) const {
			static int phi[N + 1] = {0};
			static bool processed = false;
			if (!processed){
				phi[1] = 1;
				for(int i = 2; i <= N; ++i){
					int t = i / lp[i];
					if (lp[t] == lp[i]){
						phi[i] = phi[t] * lp[i];
					}
					else{
						phi[i] = phi[t] * (lp[i] - 1);
					}
				}
				processed = true;
			}
			return phi[x];
		}
	};

	template<const size_t N>
	array<int, N + 1> sieve<N>::lp;

	template<const size_t N>
	vector<int> sieve<N>::primes;


	uint32_t mod_mul(uint32_t a, uint32_t b, uint32_t c) { 
		return static_cast<uint32_t>((a * 1ull * b) % c);
	}

	uint64_t mod_mul(uint64_t a, uint64_t b, uint64_t c) { // unsafe, requires a, b in [0, c], c < 7e18 if 1.L is 80bits.
		static_assert(sizeof(1.L) > 8);
		int64_t ret = a * b - c * uint64_t(1.L/c * a * b);
		return ret + c * (ret < 0) - c * (ret >= (int64_t)c);
	}
	#ifdef __SIZEOF_INT128__
	__uint128_t mod_mul(__uint128_t a, __uint128_t b, __uint128_t c) { // no guarantees!!
		__int128_t ret = a * b - c * __uint128_t(__float128(1) / c * a * b);
		return ret + c * (ret < 0) - c * (ret >= (__int128_t) c);
	}
	#endif

	template<typename P, typename Q>
	P fpow(P a, Q b, P p) { // requires a in [0, p);
		P ans = 1;
		while (b > 0){
			if (b & 1){
				ans = mod_mul(a, ans, p);
			}
			a = mod_mul(a, a, p);
			b >>= 1;
		}
		return ans;
	}
	template<const size_t N>
	struct primality{ // Copied squfof from https://codeforces.com/contest/1033/submission/44009089, improved miller rabin
		static sieve<N> helper;	
	private:

		template<typename Q, typename T>
		bool miller_rabin(Q p, const T& b) const{
			Q base = b % p;
			if (base == 0)
				return true;

			Q x = p - 1;
			Q d = x / (x ^ (x & (x - 1)));
			Q a = fpow(base, d, p);

			if (a == 1 || a == x){
				return true;
			}

			d <<= 1;
			while (d < x){
				d <<= 1;
				a = mod_mul(a, a, p);
				if (a == x)
					return true;
				if (a <= 1)
					return false;
			}
			return false;
		}

		template<typename Q, typename T, typename... S>
		bool miller_rabin(Q p, const T& b, const S&... bases) const{
			if (!miller_rabin(p, b))
				return false;
			return miller_rabin(p, bases...);
		}

		template<typename T>
		T safe_sqrt(T x) const {
			T z = static_cast<T> (sqrtl(x));
			while (z * z < x)
				++z;
			while (z * z > x)
				--z;
			return z;
		}

		template<typename T>
		T safe_cbrt(T x) const {
			T z = static_cast<T> (cbrt(x));
			while (z * z * z < x)
				++z;
			while (z * z * z > x)
				--z;
			return z;
		}


	    uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div) const{
	    	static vector<uint16_t> saved;
	        if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
	        saved.clear();
	        uint64_t scaledn = k*x;
	        if(scaledn>>62) return 1;
	        uint32_t sqrtn = safe_sqrt(scaledn);
	        uint32_t cutoff = safe_sqrt(2*sqrtn)/cutoff_div;
	        uint32_t q0 = 1;
	        uint32_t p1 = sqrtn;
	        uint32_t q1 = scaledn-p1*p1;
	 
	        if(q1 == 0){
	            uint64_t factor = __gcd(x, (uint64_t)p1);
	            return factor==x ? 1:factor;
	        }
	 
	        uint32_t multiplier = 2*k;
	        uint32_t coarse_cutoff = cutoff * multiplier;
	 
	        uint32_t i, j;
	        uint32_t p0 = 0;
	        uint32_t sqrtq = 0;
	 
	        for(i=0;i<it_max;++i){
	            uint32_t q, bits, tmp;
	 
	            tmp = sqrtn + p1 - q1;
	            q = 1;
	            if (tmp >= q1)
	                q += tmp / q1;
	 
	            p0 = q * q1 - p1;
	            q0 = q0 + (p1 - p0) * q;
	 
	            if (q1 < coarse_cutoff) {
	                tmp = q1 / __gcd(q1, multiplier);
	 
	                if (tmp < cutoff) {
	                    saved.push_back((uint16_t)tmp);
	                }
	            }
	 
	            bits = 0;
	            tmp = q0;
	            while(!(tmp & 1)) {
	                bits++;
	                tmp >>= 1;
	            }
	            if (!(bits & 1) && ((tmp & 7) == 1)) {
	 
	                sqrtq = (uint32_t)safe_sqrt(q0);
	 
	                if (sqrtq * sqrtq == q0) {
	                    for(j=0;j<saved.size();++j){
	                        if(saved[j] == sqrtq) break;
	                    }
	                    if(j == saved.size()) break;
	                }
	            }
	            tmp = sqrtn + p0 - q0;
	            q = 1;
	            if (tmp >= q0)
	                q += tmp / q0;
	 
	            p1 = q * q0 - p0;
	            q1 = q1 + (p0 - p1) * q;
	 
	            if (q0 < coarse_cutoff) {
	                tmp = q0 / __gcd(q0, multiplier);
	 
	                if (tmp < cutoff) {
	                    saved.push_back((uint16_t) tmp);
	                }
	            }
	        }
	 
	        if(sqrtq == 1) { return 1;}
	        if(i == it_max) { return 1;}
	 
	        q0 = sqrtq;
	        p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
	        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
	 
	        for(j=0;j<it_max;++j) {
	            uint32_t q, tmp;
	 
	            tmp = sqrtn + p1 - q1;
	            q = 1;
	            if (tmp >= q1)
	                q += tmp / q1;
	 
	            p0 = q * q1 - p1;
	            q0 = q0 + (p1 - p0) * q;
	 
	            if (p0 == p1) {
	                q0 = q1;
	                break;
	            }
	 
	            tmp = sqrtn + p0 - q0;
	            q = 1;
	            if (tmp >= q0)
	                q += tmp / q0;
	 
	            p1 = q * q0 - p0;
	            q1 = q1 + (p0 - p1) * q;
	 
	            if (p0 == p1)
	                break;
	        }
	        if(j==it_max) {cerr << "RNG\n"; return 1;} // random fail
	 
	        uint64_t factor = __gcd((uint64_t)q0, x);
	        if(factor == x) factor=1;
	        return factor;
	    }
		uint64_t squfof(uint64_t x) const {
			static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};

			{
				auto y = safe_sqrt(x);
				if (y * y == x)
					return y;
			}
			{
				auto y = safe_cbrt(x);
				if (y * y * y == x)
					return y;
			}
 
	        //uint32_t iter_lim = isqrt(isqrt(x))+10;
	        uint32_t iter_lim = 300;
	        for(uint32_t iter_fact = 1; iter_fact < 20000; iter_fact *= 4){
	            for(uint32_t const&k : multipliers){
	                if(numeric_limits<uint64_t>::max()/k <= x) //would overflow
	                	continue; 
	                uint32_t const it_max = iter_fact*iter_lim;
	                uint64_t factor = squfof_iter_better(x, k, it_max, 1);
	                if( factor == 1 || factor == x) 
	                	continue;
	                return factor;
	            }
	        }
	        cerr << "failed to factor: " << x << "\n";
	        assert(false);
	        
	        return 1;
		}
	public:
		template<typename T>
		bool isPrime(T x,typename enable_if<!is_signed_v<T>, nullptr_t>::type = nullptr) const { // Checked https://www.spoj.com/problems/PON/, weak cases? mod_mul could overflow?
			// Miller rabin bases cover 2^64: if WA, likely mod_mul fails
			if (x <= N)
				return helper.isPrime(x);
			if (~x & 1)
				return false;

			if (x < 1'050'535'501)
				return miller_rabin((uint32_t)x, 336'781'006'125ull, 9'639'812'373'923'155ull);
			if (x < 350'269'456'337ull)
				return miller_rabin((uint64_t)x, 4230279247111683200ull, 14694767155120705706ull, 16641139526367750375ull);
			if (x < 21'652'684'502'221ull)		
				return miller_rabin((uint64_t)x, 2, 1215, 34862, 574237825);
			return miller_rabin(x, 2, 325, 9375, 28178, 450775, 9780504, 1795265022);
		}

		bool isPrime(long long x) const {
			assert (x > 0);
			return isPrime<uint64_t>(static_cast<uint64_t>(x));
		}


		template<typename T, const int M = 5405>
		vector<array<T, 2>> factorisation (T x) const { 
			assert (x > 0);
			// O(ans) for x <= N, O(max(x^1/4, pi(M)))  -> for M = 5405, 712 primes. Keep M  such that M^5 (5405^5 > 2^62) > max(x) atleast.
			if (x <= N)
				return helper.factorisation(x);
			vector<array<T, 2>> f;
			for(int p: helper.primes){
				if (p > M || x <= N)
					break;
				int c = 0;
				while ((x % p) == 0){
					x /= p; ++c;
				}
				if (c > 0)
					f.push_back({static_cast<T>(p), static_cast<T>(c)});
			}
			
			static stack<T> process;
			if (x > 1){
				process.push(x);
				while (!process.empty()){
					x = process.top();
					process.pop();

					if (x <= N){
						for(const auto& v: helper.factorisation(x)){
							f.push_back(v);
						}
					}
					else if (isPrime(x)){
						f.push_back({x, 1});
					}
					else{
						T factor = squfof(x);
						assert (factor != x && factor != 1);
						process.push(factor);
						process.push(x / factor);
					}
				}

				sort(all(f));

				int id = 0;
				for(int i = 1; i < static_cast<int>(f.size()); ++i){
					if (f[i][0] == f[id][0]){
						f[id][1] += f[i][1];
					}
					else{
						++id;
						swap(f[i], f[id]);
					}
				}
				f.resize(id + 1);
			}
			return f;
		}

		template<typename T>
		vector<T> divisors(T x) const {
			if (x <= N){
				return helper.divisors(x);
			}
			vector<array<T, 2>> f = factorisation(x);

			vector<T> ans = {1};

			for(const auto& [p, cnt]: f){
				int n = ans.size() * cnt;
				for(int i = 0; i < n; ++i){
					ans.push_back(ans[i] * p);
				}
			}
			return ans;
		}

		template<typename T>
		T num_divisors(T x) const {
			if (x <= N)
				return helper.num_divisors(x);
			T ans = 1;


			for(const auto& [p, c]: factorisation(x)){
				ans *= (c + 1);				
			}
			return ans;
		}

		template<typename T>
		T phi(T x) const {
			if (x <= N)
				return helper.phi(x);
			T ans = x;
			for (const auto& [p, c]: factorisation(x)){
				ans /= p;
				ans *= (p - 1);
			}
			return ans;
		}

		template<typename T>
		T primitive_root_generator (T p, typename enable_if<!is_signed_v<T>, nullptr_t>::type = nullptr) const {
			T phi_ = phi(p); 
			vector<array<T, 2>> fact = factorisation(phi_);
			for (T res = 2; res <= p; ++res) { 
				if(__gcd(res, p) != 1)
					continue;   
				bool ok = true;
				for (size_t i = 0; i < fact.size() && ok; ++i)
						ok &= fpow(res, phi_ / fact[i][0], p) != 1;
				if (ok)  
					return res;
			} 
			return 0;
		}
		uint64_t primitive_root_generator(long long x){
			assert (x > 0);
			return primitive_root_generator<uint64_t>(x);
		}


		//Prime gaps: can likely find a prime b/w n and n + log^2 n
		//f(1,294,268,491) = 288 (1e9)
		//f(18'361'375'334'787'046'697) = 1550 (1e19)
		template<typename T>
		T next_prime(T n) const { // return minimum prime y > x, will do ~ ((ans - n) / 4.4) prime checks.
			//untested, copied from https://codegolf.stackexchange.com/questions/10701/fastest-code-to-find-the-next-prime/10702#10702
			static vector<int> indices = {1, 11, 13, 17, 19, 23, 29, 31, 37, 41, \
				43, 47, 53, 59, 61, 67, 71, 73, 79, 83,\
   				89, 97,101,103,107,109,113,121,127,131,\
  				137,139,143,149,151,157,163,167,169,173,\
  				179,181,187,191,193,197,199,209};

  			static vector<int> offsets = { 10, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6,\
   				6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4,\
   				2, 4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 6,\
   				4, 2, 4, 6, 2, 6, 4, 2, 4, 2,10, 2};

			if (n < helper.primes.back()){
				return *upper_bound(all(helper.primes), n);
			}
			n = (n + 1) | 1;
			int x = n % 210;

			int m = lower_bound(indices.begin(), indices.end(), x) - indices.begin();
			n += indices[m] - x;

			for(int z = m; z < offsets.size(); ++z){
				if (isPrime(n)){
					return n;
				}
				n += offsets[z];
			}
			while (true){
				for(const auto&z: offsets){
					if (isPrime(n)){
						return n;
					}
					n += z;
				}
			}

		}
	};

	template<const size_t N>
	sieve<N> primality<N>::helper;

	template<typename T>
	struct ex_gcd{ 
		T x,y,d;
		ex_gcd(T x,T y,T d): x(x),y(y),d(d){}  
	};

	template<typename T, typename Q>
	ex_gcd<Q> Gcd(T a, T b){
		if(b == 0) 
			return ex_gcd<Q>(1, 0, a); 	
		ex_gcd<Q> c = Gcd(b, a % b);
		return ex_gcd<Q>(c.y, c.x - (a / b) * c.y, c.d); 
	}

	template<typename P, typename Q>
	array<long long, 2> CRT(const vector<P>& remainders, const vector<Q>& mods){ // likely correct, untested after copying.
		assert (remainders.size() == mods.size());
		long long lcm = mods[0], ans = remainders[0];
		for(int i = 1; i < static_cast<int>(mods.size()); ++i){
			ex_gcd curr = Gcd<long long>(lcm, mods[i]);

			if ((ans - remainders[i]) % curr.d != 0) 
				return {-1,-1};

			ans = ans + (((curr.x * (remainders[i] - ans)/ curr.d)) % (mods[i] / curr.d)) * lcm;
			lcm = (lcm * (mods[i]/curr.d)); 
			ans %= lcm;
			if (ans < 0)
				ans += lcm;
		}
		return {ans, lcm};
	}
	
};

const int __N = 2e5 + 10;

NumberTheory::primality<__N> NT;


/*/-----------------------------Code begins----------------------------------/*/

const int M = 2e5 + 10;
vector<array<int, 3>> adj[M];

int fact[M];
int tot[M];

void dfs(int n, int p){
	for(auto [u, x, y]: adj[n]){
		if (u == p)
			continue;


		auto v2 = NT.factorisation(x);
		auto v1 = NT.factorisation(y);

		for(auto [p, cnt]: v1){
			tot[p] -= cnt;
		}
		for(auto [p, cnt]: v2){
			tot[p] += cnt;
			fact[p] = max(fact[p], tot[p]);
		}

		dfs(u, n);

		for(auto [p, cnt]: v1){
			tot[p] += cnt;
		}
		for(auto [p, cnt]: v2){
			tot[p] -= cnt;
		}
	}
}

mint calc(int n, int p, mint cur){

	mint ans = cur;
	for(auto [u, x, y]: adj[n]){
		if (u == p)
			continue;
		ans += calc(u, n, (cur * y) / x);
	}

	return ans;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		adj[i].clear();
		fact[i] = 0;
		tot[i] = 0;
	}	
	for(int i = 1; i < n; ++i){
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		int g = __gcd(x, y);
		x /= g; y /= g;
		adj[u].push_back({v, x, y});
		adj[v].push_back({u, y, x});
	}

	dfs(1, 0);

	mint denom = 1;
	for(int i = 1; i <= n; ++i){
		if (fact[i] > 0){
			denom *= mint(i) ^ fact[i];
		}
	}

	cout << calc(1, 0, denom) << endl;

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