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
const int mod = 1e9 + 7;

/*/-----------------------------Code begins----------------------------------/*/

const int N = 105;
const int INF = 1e6;
int dp[N][N][2];
pair<int,int> idx[N][N];
int sub[N];
vector<int> adj[N];

void dfs(int n){
	// static int tmp[N];


	sub[n] = 1;
	for(int i = 0; i < N; ++i){
		dp[n][i][0] = INF;
		dp[n][i][1] = INF;
		idx[n][i] = {-1,-1};

	}
	dp[n][0][0] = 0;
	dp[n][0][1] = 0;
	dp[n][1][0] = 0;
	dp[n][1][1] = 0;
	for(auto e: adj[n]){

		dfs(e);

		sub[n] += sub[e];


		// for(int i = 0; i < N; ++i){
		// 	tmp[i] = INF;
		// }

		// for(int i = 0; i < N; ++i){
		// 	for(int j = 0; i + j < N; ++j){
		// 		tmp[i + j] = min(tmp[i + j], dp[n][i][1] + 1 + dp[e][j][0]);
		// 	}
		// }


		for(int i = N - 1; i >= 0; --i){
			for(int j = 1; j <= i; ++j){
				if (dp[n][i][0] > dp[n][i - j][0] + 2 + dp[e][j][1]){
					idx[n][i] = idx[n][i - j];
					dp[n][i][0] = dp[n][i - j][0] + 2 + dp[e][j][1];
				}
				// dp[n][i][0] = min(dp[n][i][0], dp[n][i - j][0] + 2 + dp[e][j][1]);
			}
		}

		for(int i = 0; i < N; ++i){
			for(int j = 0; i + j < N; ++j){
				if (dp[n][i + j][0] > dp[n][i][1] + 1 + dp[e][j][0]){
					idx[n][i + j] = {e, j};
					// if (n == 1){
					// 	trace(i + j, idx[n][i + j], dp[n][6][0]);
					// }
					dp[n][i + j][0] = dp[n][i][1] + 1 + dp[e][j][0];
				}
				// dp[n][i + j][0] = min(dp[n][i + j][0], dp[n][i][1] + 1 + dp[e][j][0]);
			}
		}


		for(int i = N - 1; i >= 0; --i){
			for(int j = 1; j <= i; ++j){
				dp[n][i][1] = min(dp[n][i][1], dp[n][i - j][1] + 2 + dp[e][j][1]);
			}
		}
	}
}




void fill(int n, int K, int loose, vector<int>& path){
	static int delts[N][N];
	static int cdp[N];

	assert(K <= sub[n]);


	// if (loose == 0){
	// 	trace(n, K);
	// }
	// trace(n, K);
	if (K == 0)
		return;

	path.push_back(n);
	if (K == 1)
		return;


	if (idx[n][K].first == -1){
		assert(dp[n][K][0] == dp[n][K][1]);
		loose = 1;
	}

	int achieve = dp[n][K][loose];

	int e = -1;

	vector<int> extr;
	if (loose == 0){
		e = idx[n][K].first;
		int j = idx[n][K].second;
		achieve -= dp[e][j][loose] + 1;
		fill(e, j, loose, extr);
		K -= j;
	}


	vector<int> children;
	for(auto child: adj[n]){
		if (child == e)
			continue;
		children.push_back(child);
	}
	if (n == 5){
		// trace(K, achieve, children);
	}

	int sz = children.size();

	for(int i = 0; i <= sz; ++i){
		for(int j = 0; j < N; ++j){
			delts[i][j] = 0;
		}
	}
	for(int i = 0; i < N; ++i){
		cdp[i] = INF;
	}
	cdp[0] = 0;

	for(int i = 0; i < sz; ++i){
		for(int k = N - 1; k >= 0; --k){
			for(int j = 0; j <= k; ++j){
				if (cdp[k] > cdp[k - j] + 2 + dp[children[i]][j][1]){
					cdp[k] = cdp[k - j] + 2 + dp[children[i]][j][1];
					delts[i][k] = j;
				}
			}
		}
	}
	--K;
	// if (n == 7)
	// 	trace(cdp[K], K, sz, delts[0][K]);
	assert(cdp[K] == achieve);

	vector<pair<int,int>> asgn;
	int i = sz - 1;
	while(K > 0 && i >= 0){

		if (delts[i][K] > 0){
			// if (n == 7){
			// 	trace(i, K);
			// 	trace(children[i], path);

			// 	trace("removing, ", delts[i][K]);
			// }

			asgn.push_back({children[i], delts[i][K]});
			// fill(children[i], delts[i][K], 1, path);

			
			// path.push_back(n);

			int s = delts[i][K];
			K -= s;

			// if (n == 7){
			// 	trace("----------------------");
			// 	trace(i, K);
			// 	trace(children[i], path);
			// }
		}
		

		--i;	
	}	

	for(auto e: asgn){
		fill(e.first, e.second, 1, path);
		path.push_back(n);
	}
	// if (n == 7)
	// 	trace("Finally,",K);






	for(auto e: extr){
		path.push_back(e);
	}
}


void gen(int n, int k){
	cout << n << " " << k << endl;

	for(int i = 2; i <= n; ++i){
		cout << random_long(1, i - 1) << " ";
	}
	cout << endl;
}

void genT(int t, int l, int r){
	cout << t << endl;

	for(int k = 1; k <= t; ++k){
		int n = random_long(l, r);
		int K = random_long(1, n);
		gen(n, K);
	}
}

void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; ++i){
    	adj[i].clear();
    }

    // trace(n, k);
    for(int i = 2; i <= n; ++i){
    	int p;
    	cin >> p;
    	adj[p].push_back(i);
    }

    for(int i = 1; i <= n; ++i){
    	// trace(i, adj[i]);
    }
    dfs(1);
    


    cout << dp[1][k][0] << endl;

    vector<int> U;
    fill(1, k, 0, U);
    // trace(U, k, dp[2][k - 1][0]);
    // trace(idx[2][k - 1]);
    // trace()
    assert(U.size() == dp[1][k][0] + 1);
    for(auto e: U){
    	cout << e << " " ;
    }
    cout << endl;

    // trace(dp[1][k][0], dp[1][k][1], dp[3][2][1], dp[2][3][1], dp[2][3][0], idx[1][k]);

}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();


    // genT(10, 10, 20);
    int t = 1;
    cin >> t;
    
    while (t--) {
    	// trace(t);
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}