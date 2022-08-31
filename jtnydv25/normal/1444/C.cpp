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
const int N = 1000005;
int c[N];

int is_color[N];
int is_bipartite[N];
int colors = 0;
vector<int> adj[N];
int col[N];
int curr_comp;
int comp[N];

void dfs(int s, int color){
	col[s] = color;
	comp[s] = curr_comp + color - 1;
	for(int v : adj[s]) if(c[v] == c[s]){
		if(!col[v]) dfs(v, 3 - color);
		else{
			if(col[v] != 3 - color){
				if(is_bipartite[c[s]]) colors--;
				is_bipartite[c[s]] = 0;
			}
		}
	}
}

template<class T>
struct ArrayMap{
	int version;
	bool iterable;
	vector<T> arr;
	vector<int> lastUpdated;
	vector<int> keys; // to iterate
	
	ArrayMap(){}
	ArrayMap(int n, bool b = false) : version(0), iterable(b), arr(n), lastUpdated(n){}

	void clear(){
		++version;
		if(iterable)
			keys.clear();
	}

	T & operator [] (int pos){ // equivalent to map operator []
		if(lastUpdated[pos] == version){
			return arr[pos];
		}
		lastUpdated[pos] = version;
		if(iterable) keys.push_back(pos);
		arr[pos] = T();
		return arr[pos];
	}

	bool exists(int pos){
		return lastUpdated[pos] == version;
	}

	void erase(int pos){
		lastUpdated[pos] = version - 1;
	}
};

int main(){
	// ios_base::sync_with_stdio(false); 
	// cin.tie(NULL);
	int n, m, k;
	// cin >> n >> m >> k;
	scanf("%d %d %d", &n, &m, &k);
	map<pii, vector<pii>> edges;
	for(int i = 0; i < n; i++){
		scanf("%d", c + i);
		// cin >> c[i];
		c[i]--;
	}

	for(int i = 0; i < m; i++){
		int u, v;
		// cin >> u >> v;
		scanf("%d %d", &u, &v);
		u--; v--;
		if(c[u] > c[v]) swap(u, v);
		if(c[u] != c[v]) edges[make_pair(c[u], c[v])].push_back(make_pair(u, v));
		adj[u].push_back(v);
		adj[v].push_back(u);

		is_color[c[u]] = is_color[c[v]] = 1;
	}

	colors = k;
	fill(is_bipartite, is_bipartite + k, 1);

	for(int i = 0; i < n; i++) if(!col[i] && is_bipartite[c[i]]){
		dfs(i, 1);
		curr_comp += 2;
	}

	ll ans = (colors * 1LL * (colors - 1)) / 2;

	ArrayMap<vector<int>> adj_c(2 * n);
	ArrayMap<int> present(2 * n, true);
	ArrayMap<int> C(2 * n);
	bool error = false;
	function<void(int, int)> go = [&](int s, int color){
		C[s] = color;
		for(int v : adj_c[s]){
			if(!C[v]) go(v, 3 - color);
			else{
				if(C[v] != 3 - color) error = true;
			}
		}
	};
	for(auto it : edges){
		int a = it.first.first;
		int b = it.first.second;
		if(!is_bipartite[a] || !is_bipartite[b]) continue;
		adj_c.clear();
		present.clear();
		C.clear();
		for(auto E : it.second){
			int u = E.first, v = E.second;
			int cu = comp[u], cv = comp[v];
			adj_c[cu].push_back(cv);
			adj_c[cv].push_back(cu);
			present[cu] = present[cu ^ 1] = 1;
			present[cv] = present[cv ^ 1] = 1;
		}
		for(int p : present.keys){
			adj_c[p].push_back(p ^ 1);
		}
		error = false;
		for(int p : present.keys) if(!C[p]) go(p, 1);
		if(error) ans--;
	}
	printf("%lld\n", ans);
	// cout << ans << endl;
}