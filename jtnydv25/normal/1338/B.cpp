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


int main(){
	int n; sd(n);
	vector<int> L(n);
	vector<vector<int>> adj(n);
	int l = 0;
	for(int i = 1; i < n; i++){
		int u, v; sd(u); sd(v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int rt = 0;
	for(int i = 0; i < n; i++){
		if(sz(adj[i]) == 1) l++;
		else{
			rt = i;
			for(int j : adj[i]) if(sz(adj[j]) == 1) L[i]++;
		}
	}
	int mx = n - 1;
	for(int i = 0; i < n; i++) mx -= max(0, L[i] - 1);
	vector<int> num(2, 0);

	function<void(int, int, int)> dfs = [&](int s, int p, int d){
		if(sz(adj[s]) == 1){
			num[d]++;
		}
		for(int v : adj[s]) if(v != p) dfs(v, s, d ^ 1);
	};
	dfs(rt, -1, 0);
	if(num[0] && num[1]){
		printf("%d %d\n", 3, mx);
	} else printf("%d %d\n", 1, mx);
}