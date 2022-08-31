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

/*/-----------------------------Code begins----------------------------------/*/
const int N = 55;
vector<int> adj[N];


/*O(min(fm,mn^2)), for any unit capacity network 
O(m*sqrt(n)), in practice it is pretty fast for any 
bipartite network, **vertices are 1-indexed**
e=(u,v),e.flow represent effective flow from u to v 
(i.e f(u->v) - f(v->u))
*use int if possible 
1.To put lower bound on edge capacities form a new 
graph G' with source s' and t' for each edge u->v
 in G with cap (low, high), replace it with
s'->v with low, u->t' with low
u->v with high - low
2.To convert circulation with edge lower bounds
to circulation without edge lower bounds
old=> e=u->v,l(e)<=f(e)<=c(e), d(u), d(v).
new=> d'(u)=d(u)+l(e), d'(v)=d(v)-l(e), c'(e)=c(e)-l(e))*/
#define ll long long
#define vll vector<long long>
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
		adj[from].push_back(e.size()); e.pb(e1);
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
	}
	void dfs2(int m, vector<bool>& vis){
		vis[m] = true;
		for(auto id: adj[m]){
			if (e[id].flow < e[id].cap && !vis[e[id].y]){
				dfs2(e[id].y, vis);
			}
		}
	}
	void min_cut(vector<int>& s, vector<int>& t){
		vector<bool> vis(n);
		dfs2(source, vis);
		for(int i = 0;  i < n; ++i){
			if (i == source || i == sink)
				continue;

			if (vis[i]){
				s.push_back(i);
			}
			else
				t.push_back(i);
		}

	} 
};

const long long INF = 1e16;


void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= m; ++i){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    }

    vector<array<long long, 2>> pts(k);
    cin >> pts;
    	
    long long s = 0;
    for(auto e: pts){
    	s += e[0];
    }
    DinicFlow U(2 * n + 3);
    int src = 2 * n + 1, snk = 2* n + 2;

    for(int i = 1; i <= n; ++i){
    	U.addEdge(src, i, 1);
    	U.addEdge(i + n, snk, 1);
    	for(auto e: adj[i]){
    		U.addEdge(i, e + n, 1);
    	}
    }
    int initial = n - U.maxFlow(src, snk);
    auto get_removable = [&] (const vector<int>& s){
    	vector<bool> a(2 * n + 1, false);
    	for(auto e: s){
    		if (e <= 2 * n)
    			a[e] = true;
    	}
    	vector<int> cur;
    	for(int i = 1;  i <= n; ++i){
    		if (!a[i]){
    			cur.push_back(i);
    		}
    	}
    	for(int i = n + 1; i <= 2* n; ++i){
    		if (a[i])
    			cur.push_back(-(i - n));
    	}
    	return cur;
    };
    vector<int> S, t;
    U.min_cut(S, t);

    auto z = get_removable(S);
    assert(z.size() + initial == n);

    vector<vector<int>> output(k + 34);
    pair<long long, long long> mini = {INF, -1};

    long long oth = s;

    vector<long long> dp(k + 1);

    int init = initial;

    for(int i = 1; i <= k; ++i){
    	dp[i] = dp[i - 1];
    	mini = min(mini, {pts[i - 1][1], i});
    	if (i < initial)
    		continue;

    	assert(i == initial);
    	// output[mini.second].push_back(z.back());
    	// oth -= mini.first;
    	// z.pop_back();
    	// ++initial;
    	dp[i] += mini.first;
    	++initial;
    }

    int pos = k;
    long long val = dp[k];

    for(int i = 1; i <= k; ++i){
    	if (val > dp[i - 1] + pts[i - 1][0]){
    		val = dp[i - 1] + pts[i - 1][0];
    		pos = i - 1;
    	}
    }

	mini = {INF, -1};

	for(int i = 1; i <= pos; ++i){
    	mini = min(mini, {pts[i - 1][1], i});
    	if (i < init)
    		continue;

    	assert(i == init);
    	output[mini.second].push_back(z.back());
    	z.pop_back();
    	++init;
    }
    for(auto e: z){
    	output[pos + 1].push_back(e);
    }

    // trace(s - val);
	vector<int> res;

	for(int i = 1; i <= k; ++i){
		for(auto e: output[i])
			res.push_back(e);
		res.push_back(0);
	}

    cout << res.size() << endl;
    for(auto e: res){
    	cout << e << " ";
    }
    cout << endl;
    // trace(ans);
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