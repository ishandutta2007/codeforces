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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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
int a[N], b[N], w[N];
struct graph {
	vector<vector<int>> adj;
	vector<ll> dp[2];
	int n;
	graph(int n) : n(n), adj(n + 1){
		dp[0].resize(n + 1);
		dp[1].resize(n + 1);
	}
	void add_edge(int u, int v, int i){
		adj[u].push_back(i);
		adj[v].push_back(i);
	}
	ll calculate(int k){
		function<void(int, int)> dfs = [&](int s, int p){
			vector<ll> vec;
			ll sm = 0;
			for(int ind : adj[s]){
				int v = s ^ a[ind] ^ b[ind];
				if(v == p) continue;
				dfs(v, s);
				int wt = w[ind];
				vec.push_back(-dp[1][v] + dp[0][v] - wt);
				sm += dp[0][v];
			}
			sort(all(vec));
			ll sm1 = 0, sm2 = 0;
			ll mx1 = 0, mx2 = 0;
			for(int i = 0; i < sz(vec); i++){
				if(i < k){
					sm1 -= vec[i]; 
				}
				if(i < k - 1) sm2 -= vec[i];
				mx1 = max(mx1, sm1);
				mx2 = max(mx2, sm2);
			}
			dp[0][s] = sm + mx1;
			dp[1][s] = sm + mx2;
		};
		dfs(1, -1);
		return dp[0][1];
	}
};

int main(){
	int t; sd(t);
	while(t--){
		int n, k;
		sd(n); sd(k);
		graph g(n);
		for(int i = 1; i < n; i++){
			sd(a[i]); sd(b[i]); sd(w[i]);
			g.add_edge(a[i], b[i], i);
		}
		printf("%lld\n", g.calculate(k));
	}
}