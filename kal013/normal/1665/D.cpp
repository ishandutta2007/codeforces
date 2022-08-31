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



namespace NumberTheory{
	template<const size_t N>
	class sieve{

	public:
		array<int, N + 1> lp;
		vector<int> primes;
		sieve<N>() {
			if (primes.empty()){
				for(int i = 2; i <= N; ++i)
					lp[i] = 0;
				lp[1] = 1;
				for(int i = 2; i <= N; ++i){
					if (lp[i] == 0){
						lp[i] = i;
						primes.push_back(i);
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
		inline bool isPrime(T x) const {
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

	


	uint32_t mod_mul(uint32_t a, uint32_t b, uint32_t c) { 
		return static_cast<uint32_t>((a * 1ull * b) % c);
	}

	uint64_t mod_mul(uint64_t a, uint64_t b, uint64_t c) { // unsafe, requires a, b in [0, c], c < 7e18 if 1.L is 80bits.
		#ifdef __SIZEOF_INT128__
			return (__uint128_t(a) * b) % c;
		#else 
			static_assert(sizeof(1.L) > 8);
			int64_t ret = a * b - c * uint64_t(1.L/c * a * b);
			return ret + c * (ret < 0) - c * (ret >= (int64_t)c);
		#endif
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
	class primality{ // Copied squfof from https://codeforces.com/contest/1033/submission/44009089, improved miller rabin
	public:
		sieve<N> helper;	
	private:



		template<typename Q, typename T>
		bool miller_rabin(Q p, const T& b) const{
			Q base = b % p;
			if (base == 0)
				return true;

			uint8_t zeros = __builtin_ctz(p - 1);

			Q a = fpow(base, (p - 1) >> zeros, p);

			if (a == 1 || a == (p - 1)){
				return true;
			}

			while (--zeros){
				a = mod_mul(a, a, p);
				if (a == (p - 1))
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
		inline T safe_sqrt(T x) const {
			T z = static_cast<T> (sqrtl(x));
			while (z * z < x)
				++z;
			while (z * z > x)
				--z;
			return z;
		}
		template<typename T>
		inline T unsafe_sqrt(T x) const {
			return static_cast<T>(sqrtl(x) + 0.5);
		}
		template<typename T>
		inline T safe_cbrt(T x) const {
			T z = static_cast<T> (cbrt(x));
			while (z * z * z < x)
				++z;
			while (z * z * z > x)
				--z;
			return z;
		}
		template<typename T>
		inline T unsafe_cbrt(T x) const {
			return static_cast<T>(cbrt(x) + 0.5);
		}


	    uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div) const{
	    	static vector<uint16_t> saved;
	        if(__gcd((uint64_t)k, x) != 1) return __gcd(k, x);
	        saved.clear();
	        uint64_t scaledn = k*x;
	        if(scaledn >> 62) return 1;
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
	 
	        for(i = 0; i < it_max; ++i){
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
	 
	            bits = __builtin_ctzll(q0);
	            tmp = q0 >> bits;
	            
	            if (!(bits & 1) && ((tmp & 7) == 1)) {
	 
	                sqrtq = (uint32_t)unsafe_sqrt(q0);
	 
	                if (sqrtq * sqrtq == q0) {
	                    for(j = 0; j < saved.size(); ++j){
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
			constexpr static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
			{
				auto y = unsafe_sqrt(x);
				if (y * y == x)
					return y;
			}
			{
				auto y = unsafe_cbrt(x);
				if (y * y * y == x)
					return y;
			}
 
	        //uint32_t iter_lim = isqrt(isqrt(x))+10;
	        uint32_t iter_lim = 256;
	        for(uint32_t iter_fact = 1; iter_fact < 20000; iter_fact <<= 2){
	            for(uint32_t const&k : multipliers){
	                if(numeric_limits<uint64_t>::max()/k <= x) //would overflow
	                	break; 
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
		// From: https://github.com/NicholasPatrick/PaNic-CP-templates
		uint64_t brent_factor(uint64_t n) const {
			uint64_t r = sqrt(n) + 0.5;
			if (r * r == n){
				return r;
			}
			uint64_t g = n, ni = -n; for(uint8_t _ = 5; _--; ) ni *= 2 + ni * n;

			auto redc = [n, ni](__uint128_t x) -> uint64_t {
				return uint64_t(x) * ni * __uint128_t(n) + x >> 64;
			};
			auto f = [n, ni, redc](uint64_t x) {return redc(__uint128_t(x) * x + 1);};


			const uint64_t m = sqrt(r + 1000) / 20;
			for (uint64_t x0 = 0; g == n; ++x0) {
				uint64_t x, y = x0, q = g = 1, ys;
				for (uint64_t r = 1; g == 1; r <<= 1) {
					x = y;
					for (uint64_t _ = r; _--;) y = f(y);
					for (uint64_t k = 0; k < r && g == 1; k += m) {
						ys = y;
						for (uint64_t _ = min(m, r - k); _--;)
							y = f(y), q = redc(__uint128_t(max(x, y) - min(x, y)) * q);
						g = gcd(q, n);
					}
				}
				if (g == n) for (g = 1; g == 1;)
					ys = f(ys), g = gcd(max(x, ys) - min(x, ys), n);
			}
			return g;
		}
	public:
		template<typename T>
		inline bool isPrime(T x,typename enable_if<!is_signed_v<T>, nullptr_t>::type = nullptr) const { // Checked https://www.spoj.com/problems/PON/, weak cases? mod_mul could overflow?
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

		inline bool isPrime(long long x) const {
			assert (x > 0);
			return isPrime<uint64_t>(static_cast<uint64_t>(x));
		}

		template<typename T, const int M = 5405>
		inline vector<array<T, 2>> factorisation (T x) const { 
			assert (x > 0);
			// O(ans) for x <= N, O(max(x^1/4, pi(M)))  -> for M = 5405, 712 primes. Keep M  such that M^5 (5405^5 > 2^62) > max(x) atleast.
			if (x <= N)
				return helper.factorisation(x);
			vector<array<T, 2>> f;
			for(int p: (helper.primes)){
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
						// T factor = squfof(x);
						T factor = brent_factor(x);
						assert (factor != x && factor != 1);
						process.push(factor);
						process.push(x / factor);
					}
				}

				sort(f.begin(), f.end());

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


	template<typename T>
	struct ex_gcd{ 
		T x,y,d;
		ex_gcd(T x,T y,T d): x(x),y(y),d(d){}  
	};

	template<typename T, typename Q>
	ex_gcd<Q> Gcd(T a, T b){
		if(b == 0) 
			return ex_gcd<Q>(1, 0, a); 	
		ex_gcd<Q> c = Gcd<T, Q>(b, a % b);
		return ex_gcd<Q>(c.y, c.x - (a / b) * c.y, c.d); 
	}

	template<typename P, typename Q>
	array<long long, 2> CRT(const vector<P>& remainders, const vector<Q>& mods){ // likely correct, untested after copying.
		assert (remainders.size() == mods.size());
		long long lcm = mods[0], ans = remainders[0];
		for(int i = 1; i < static_cast<int>(mods.size()); ++i){
			ex_gcd<Q> curr = Gcd<long long, Q>(lcm, mods[i]);

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


const size_t N = 1e6 + 10;

/*/-----------------------------Code begins----------------------------------/*/

// #define LOCAL
void solve(){
	long long n = random_long(1, 1e9);
	vector<long long> mods = {4, 9, 5, 7, 11, 13, 17, 19, 23};
	long long z = 1;
	for(int x: mods){
		z *= x;
	}

	vector<long long> rems(mods.size(), -1);
	auto query = [&] (long long a, long long b) {
		assert (b - a == z);
		int ans;


		#ifdef LOCAL
			ans = __gcd(n + a, n + b);
		#else
			cout << "? " << a << " " << b << endl;
			cin >> ans;
			assert (ans != -1);
		#endif
		for(int i = 0; i < mods.size(); ++i){
			int x = mods[i];
			if ((ans % x) == 0){
				int cur = ((-a % x) + x) % x;
				assert (rems[i] == -1 || rems[i] == cur);
				rems[i] = cur;
			}
		}
	};


	for(int i = 1; i < 26; ++i){
		query(i, z + i);
	}

	assert (count(rems.begin(), rems.end(), -1) == 0);
	auto Q = NumberTheory::CRT(rems, mods);
	assert (Q[1] == z);

	#ifdef LOCAL
		assert (n == Q[0]);
	#endif
	cout << "! " << Q[0] << endl;



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