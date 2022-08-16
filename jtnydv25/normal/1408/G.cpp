#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

struct dsu{
    int n;
    vector<int> par, sizes;
	vector<vector<int>> nodes;
    dsu(int n) : n(n), par(n), sizes(n), nodes(n){
        iota(par.begin(), par.end(), 0);
    }
    int root(int x){
        return x == par[x] ? x : (par[x] = root(par[x]));
    }
};
const int mod = 998244353;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
const int N = 4000;

int dp[N][N];
int a[N][N];
vector<int> g[N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n; cin >> n;
	vector<pii> vec;
	dsu D(2 * n - 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j< n; j++){
			cin >> a[i][j];
			if(i < j) vec.push_back({i, j});
		}
		dp[i][1] = 1;
		D.sizes[i] = 1;
		D.nodes[i] = {i};
	}
	sort(all(vec), [&](const pii & p, const pii & q){
		return a[p.F][p.S] < a[q.F][q.S];
	});
	int root = n - 1;
	for(auto it : vec){
		int u = it.F, v = it.S;
		u = D.root(u);
		v = D.root(v);
		if(u == v) continue;
		++root;
		D.sizes[root] = D.sizes[u] + D.sizes[v];
		D.nodes[root] = D.nodes[u];
		copy(all(D.nodes[v]), back_inserter(D.nodes[root]));
		D.par[u] = D.par[v] = root;
		int mx_in = -1, mn_out = 1 << 30; 
		dp[root][1] = 1;
		vector<bool> there(n);
		for(int i : D.nodes[root]) there[i] = 1;
		for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
			if(there[i] && there[j]) mx_in = max(mx_in, a[i][j]);
			if(there[i] && !there[j]) mn_out = min(mn_out, a[i][j]);
			if(there[j] && !there[i]) mn_out = min(mn_out, a[i][j]);
			if(mn_out < mx_in){
				dp[root][1] = 0;
				break;
			}
		}
		for(int i = 1; i <= D.sizes[u]; i++) for(int j = 1; j <= D.sizes[v]; j++){
			dp[root][i + j] = add(dp[root][i + j], mul(dp[u][i], dp[v][j]));
		}
	}
	for(int k = 1; k <= n; k++) cout << dp[root][k] << " ";
	cout << endl;
}