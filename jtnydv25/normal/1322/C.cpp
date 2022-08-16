#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N = 500005;
ll c[N];
const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

// mt19937_64 for 64 bit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int getRand(int x, int y){
	return uniform_int_distribution<int>(x, y)(rng);
}
int main(){
	int base1 = getRand(N, 10 * N);
	int base2 = getRand(N, 10 * N);
	int t; sd(t);
	while(t--){
		int n, m; sd(n); sd(m);
		vector<vector<int>> adj(n + 1);
		for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
		for(int i = 1; i <= m; i++){
			int u, v; sd(u); sd(v);
			adj[v].push_back(u);
		}
		map<ll, ll> mp;
		for(int i = 1; i <= n; i++){
			sort(all(adj[i]));
			if(adj[i].empty()) continue;
			int h1 = 0, h2 = 0;
			for(int j : adj[i]){
				h1 = (h1 * (ll) base1 + j) % mod1;
				h2 = (h2 * (ll) base2 + j) % mod2;
			}
			mp[(h1 * (ll) (1<<30)) + h2] += c[i];
		}
		ll ret = 0;
		for(auto it : mp){
			ret = __gcd(ret, it.S);
		}
		printf("%lld\n", ret);
	}
}