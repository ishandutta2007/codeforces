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

const int N = 200005;
vector<int> con[N];
vector<int> child[N];
int par[N], w[N], deg[N];
set<pair<int, int>> st;

ll mx[N], mx2[N];
int _root[N];

bool isRoot(int x){
	return deg[par[x]] >= 2 || deg[x] == 0;
}

ll dfs(int s, int rt){
	mx[s] = w[s];
	_root[s] = rt;
	for(int v : child[s]){
		mx[s] = max(mx[s], w[s] + dfs(v, rt));
	}
	return mx[s];
}

ll dfs2(int s, int p = -1){
	mx2[s] = w[s];
	for(int v : child[s]) if(v != p){
		mx2[s] = max(mx2[s], w[s] + dfs2(v, s));
	}
	int v = par[s];
	if(v && v != p) mx2[s] =  max(mx2[s], w[s] + dfs2(v, s));
	return mx2[s];
}

int main(){
	int n, m; sd(n); sd(m);
	for(int i = 1; i <= n; i++) sd(w[i]);
	for(int j = 1; j <= m; j++){
		int u, v;
		sd(u); sd(v);
		con[u].push_back(v);
		con[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	for(int i = 1; i <= n; i++) st.insert({deg[i], i});
	vector<int> nodes;
	vector<int> roots;
	while(!st.empty()){
		auto it = *st.begin();
		if(it.F >= 2) break;
		if(it.F == 0){
			assert(st.size() == 1);
			break;
		}
		assert(it.F == 1);
		int s = it.S;
		nodes.push_back(s);
		st.erase(it);
		// trace(s, deg[s]);
		for(auto v : con[s]) if(par[v] != s){
			st.erase({deg[v], v});
			deg[v]--;
			par[s] = v;
			child[v].push_back(s);
			st.insert({deg[v], v});
		}
	}

	int s;
	sd(s);
	ll ans2 = 0;
	if(deg[s] < 2){
		ans2 = dfs2(s);
	}
	// trace(deg[s], par[1], par[2], par[3]);
	// trace(ans2);
	ll ans = 0;
	for(int i = 1; i <= n; i++) if(isRoot(i)) dfs(i, i);
	for(int i = 1; i <= n; i++) if(deg[i] >= 2) ans += w[i];
	if(deg[s] >= 2){
		ll MX = 0;
		for(int i = 1; i <= n; i++) MX = max(MX, mx[i]);
		ans += MX;
	} else{
		int u = s;

		while(u && deg[u] < 2){
			ans += w[u];
			w[u] = 0;
			u = par[u];
		}
		if(u != 0 && deg[u] >= 2){
			int rt = _root[s];
			dfs(rt, rt);
			ll MX = 0;
			for(int i = 1; i <= n; i++) MX = max(MX, mx[i]);
			ans += MX;
		}
	}

	printf("%lld\n", max(ans, ans2));
}