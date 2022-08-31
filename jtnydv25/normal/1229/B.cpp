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

const int N = 100005;
const int logN = 20;
vector<int> con[N];
int depth[N];
ll a[N];
ll g[logN][N];
int par[logN][N];
void dfs(int s = 1, int d = 1, int p = 0){
    depth[s] = d;
    g[0][s] = a[s];
	par[0][s] = p;
    for(int v:con[s])
        if(v!=p)
            dfs(v,d+1,s);
}
void pre(int n){
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++){
            g[j][i] = __gcd(g[j-1][i], g[j-1][par[j-1][i]]);
			par[j][i] = par[j - 1][par[j - 1][i]];
		}
}
const int mod = 1e9 + 7;
ll get(int node){
	ll curr = a[node];
	ll old = 0;
	ll ret = 0;
	int now = node;
	while(now){
		int orig = now;
		ll G = old;
		for(int k = logN - 1; k >= 0; k--){
			if(!now) continue;
			if((1 << k) > depth[now] + 1) continue;
			ll _g = __gcd(old, g[k][now]);
			if(_g == curr) now = par[k][now], old = _g;
		}
		ret += (depth[orig] - depth[now]) * curr;
		// trace(node, orig, now, curr);
		old = curr;
		curr = __gcd(curr, a[now]);
	}
	return ret % mod;
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	for(int i = 1; i < n; i++){
		int u, v;
		sd(u); sd(v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	dfs();
	pre(n);
	ll ret = 0;
	for(int i = 1; i <= n; i++) ret += get(i);
	printf("%lld\n", ret % mod);
}