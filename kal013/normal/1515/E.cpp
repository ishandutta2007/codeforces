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
int mod;

int add(int x, int y){
	x += y;
	if (x >= mod)
		return x - mod;
	return x;
}
int sub(int x, int y){
	x -= y;
	if (x < 0)
		return x + mod;
	return x;
}

int mul(int x, int y){
	return (x * 1LL * y) % mod;
}

const int N = 405;

// int dp[N][N][N][2], prf[N][N][N][2];
// bool vis[N][N][N][2], vis2[N][N][N][2];

// int state(int n, int len, int pos, int aft);

// int pref(int n, int len, int pos, int aft){
// 	if (n == 0){
// 		return 0;
// 	}
// 	assert(n >= 1 && aft >= 0 && aft <= 1);

// 	if (vis2[n][len][pos][aft]){
// 		return prf[n][len][pos][aft];
// 	}
// 	vis2[n][len][pos][aft] = true;
// 	if (pos == 0){
// 		prf[n][len][pos][aft] = 0;
// 		return 0;
// 	}
// 	prf[n][len][pos][aft] = add(state(n, len, pos, aft), pref(n, len, pos - 1, aft));
// 	return prf[n][len][pos][aft];

// }

// int pref2(int n, int len, int l1, int r1, int aft){
// 	assert(l1 - 1 <= r1 && l1 >= 1);
// 	return sub(pref(n, len, r1, aft), pref(n, len, l1 - 1, aft));
// }
// int state(int n, int len, int pos, int aft){
// 	if (n == 0){
// 		return 0;
// 	}
// 	assert(n >= 1 && aft >= 0 && aft <= 1);
// 	if (len > n || pos > len || pos <= 0 || len == 0){
// 		return 0;
// 	}
// 	if (vis[n][len][pos][aft]){
// 		return dp[n][len][pos][aft];
// 	}
// 	vis[n][len][pos][aft] = true;
// 	int ans = 0;
// 	if (n == 1){
// 		assert(len == 1 && pos == 1);
// 		dp[n][len][pos][aft] = 1 - aft;
// 		return 1 - aft;
// 	}
// 	if (aft == 1){
// 		ans = add(pref(n - 1, len - 1, pos - 1, 0) , pref(n - 1, len - 1, pos - 1, 1));
// 	}
// 	else{
// 		// trace("yo");
// 		// ans = sub(pref(n - 1, len - 1, len - 1, 0) , pref(n - 1, len - 1, pos - 1, 0));
// 		ans = pref2(n - 1, len - 1, pos, len - 1, 0);
// 		if (n == 4){
// 			// trace(ans);
// 		}
// 		// trace(ans, n - 1, len - 1, pos, len - 1);
// 		if (len < n){

// 			ans = add(ans, pref2(n - 2, len - 1, 1, len - 1, 1));
// 			ans = add(ans, pref2(n - 2, len - 1, 1, len - 1, 0));

// 			if (n == 4){
// 				// trace(ans);	
// 			}
// 		}
// 	}

// 	// trace(n, len, pos, aft, ans);


// 	dp[n][len][pos][aft] = ans;
// 	return ans;
// }


/*/-----------------------------Code begins----------------------------------/*/

int dp[3][N][N][2], prf[3][N][N][2];
// bool vis[N][N][N][2], vis2[N][N][N][2];

void solve(){
	int n;
	cin >> n >> mod;    


	int ret = 0;

	int cur = 0;

	for(int z = 0; z < N; ++z){
		for(int k = 0; k < N; ++k){
			dp[cur][z][k][0] = 0;
			dp[cur][z][k][1] = 0;
			prf[cur][z][k][0] = 0;
			prf[cur][z][k][1] = 0;
		}
	}

	for(int i = 1; i <= n; ++i){
		int prv = cur;
		cur += 1;
		cur %= 3;

		// trace(prv, cur);
		for(int len = 0; len < N; ++len){
			for(int pos = 0; pos < N; ++pos){
				for(int aft = 0; aft < 2; ++aft){
					dp[cur][len][pos][aft] = 0;
					if (len > i || pos > len || pos == 0 || len == 0){
						continue;
					}
					if (i == 1){
						dp[cur][len][pos][aft] = 1 - aft;
						continue;
					}

					int ans = 0;
					if (aft == 1){
						ans = add(prf[prv][len - 1][pos - 1][0], prf[prv][len - 1][pos - 1][1]);
					}
					else{
						// bool pr = false;
						// if (i == 3 && len == 2 && pos == 1){
						// 	pr = true;
						// }
						ans = sub(prf[prv][len - 1][len - 1][0] , prf[prv][len - 1][pos - 1][0]);
						// if (pr){
							// trace(ans);
						// }
						if (len < i && i >= 2){
							int prv2 = (cur + 1) % 3;
							ans = add(ans, prf[prv2][len - 1][len - 1][0]);
							// if (pr){
								// trace(ans);
							// }
							ans = add(ans, prf[prv2][len - 1][len - 1][1]);
							// if (pr){
								// trace(ans);
							// }
						}
					}
					dp[cur][len][pos][aft] = ans;
				}
			}
		}

		for(int len = 0; len < N; ++len){
			for(int pos = 0; pos < N; ++pos){
				for(int aft = 0; aft < 2; ++aft){
					if (pos == 0){
						prf[cur][len][pos][aft] = 0;
						continue; 
					}
					prf[cur][len][pos][aft] = add(dp[cur][len][pos][aft], prf[cur][len][pos - 1][aft]);
					
				}
			}
		}

	}
	
	
	

	// trace(state(4, 3, 1, 0));
	for(int len = 1; len <= n; ++len){
		for(int pos = 1; pos <= len; ++pos){
			ret = add(ret, dp[cur][len][pos][0]);
			ret = add(ret, dp[cur][len][pos][1]);
			// trace(ret, len, pos);
			// ret = add(ret, state(n, len, pos, 0));
			// ret = add(ret, state(n, len, pos, 1));

			// trace(n, len, pos);
			// trace(state(n, len, pos, 0));
			// trace(state(n, len, pos, 1));
			// trace("---");
		}
	}

	cout << ret << endl;
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