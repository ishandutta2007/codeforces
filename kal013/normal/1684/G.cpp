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


using ll = long long;

using vll = vector<long long>;
#define pb push_back

struct edge {ll x, y, cap, flow;};
struct DinicFlow {
	// *** change inf accordingly *****
	const ll inf = (1e18);
	vector <edge> e; vll cur, d;
	vector<vll> adj; ll n, source, sink;
	DinicFlow() {}
	DinicFlow(ll v){ n=v; cur=vll(n+1);
		d = vll(n+1); adj = vector<vll>(n+1);}
	void addEdge(ll from, ll to, ll cap) {
		edge e1 = {from, to, cap, 0};
		edge e2 = {to, from, 0, 0}; 
		adj[from].pb(e.size()); e.pb(e1);
		adj[to].pb(e.size()); e.pb(e2); }
	ll bfs(){ queue <ll> q;
		for(ll i = 0; i <= n; ++i) d[i] = -1;
		q.push(source); d[source] = 0;
		while(!q.empty() and d[sink] < 0) {
			ll x = q.front(); q.pop();
			for(ll i = 0; i < (ll)adj[x].size(); ++i){
				ll id = adj[x][i], y = e[id].y;
				if(d[y]<0 and e[id].flow < e[id].cap){
					q.push(y); d[y] = d[x] + 1;
		} } } return d[sink] >= 0; }
	ll dfs(ll x, ll flow) { if(!flow) return 0;
		if(x == sink) return flow;
		for(;cur[x] < (ll)adj[x].size(); ++cur[x]){
			ll id = adj[x][cur[x]], y = e[id].y;
			if(d[y] != d[x] + 1) continue;
			ll pushed = dfs(y,min(flow,e[id].cap-e[id].flow));
			if(pushed){ e[id].flow+=pushed; 
				e[id^1].flow -= pushed; return pushed; }
		} return 0; }
	ll maxFlow(ll src, ll snk) {
		this->source=src;this->sink = snk; ll flow=0;
		while(bfs()){ for(ll i=0;i<=n;++i) cur[i]=0;
		 while(ll pushed=dfs(source,inf))flow+=pushed;
		} return flow;
} };

/*/-----------------------------Code begins----------------------------------/*/

void solve(){
	long long n, m;
	cin >> n >> m;
	vector<long long> t(n);
	cin >> t;
	sort(t.begin(), t.end());

	vector<long long> small, big;

	for(auto z: t){
		if (3 * z <= m){
			small.push_back(z);
		}
		else if ((2 * z + 1) <= m){
			big.push_back(z);
		}
		else{
			cout << "-1\n";
			return;
		}
	}


	DinicFlow dev(n + 4);
	int src = n + 2, snk = n + 3;
	int k1 = small.size(), k2 = big.size();
	assert (k1 + k2 == n);

	for(int i = 0; i < big.size(); ++i){
		long long r1 = big[i];
		dev.addEdge(src, i, 1);
		for(int j = 0; j < small.size(); ++j){
			long long r2 = small[j];
			if ((r1 % r2) != 0)
				continue;
			if (2 * r1 + r2 > m)
				continue;
			dev.addEdge(i, j + k2, 1);
		}
	}
	for(int j = k2; j < n; ++j){
		dev.addEdge(j, snk, 1);
	}

	int z = dev.maxFlow(src, snk);
	if (z < k2){
		cout << "-1\n";
		return;
	}

	vector<array<int, 2>> ans;
	vector<bool> used(k1);
	for(auto X: dev.e){
		int u = X.x, v = X.y;
		if (u < k2 && v < n && v >= k2){
			if (X.flow == 1){
				assert (!used[v - k2]);

				int r1 = big[u], r2 = small[v - k2];
				used[v - k2] = true;
				ans.push_back({r1 + r2, 2 * r1 + r2});
			}
			else{
				assert (X.flow == 0);
			}
		}
	}
	assert (ans.size() == k2);


	for(int i = 0; i < k1; ++i){
		if (!used[i]){
			ans.push_back({3 * small[i], 2 * small[i]});
		}
	}

	cout << ans.size() << "\n";
	for(auto [a, b]: ans){
		cout << a << " " << b << "\n";
	}

}  

int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}