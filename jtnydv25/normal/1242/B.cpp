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
const int N = 100005;
bitset<N> ALL;
vector<int> adj[N];
bitset<N> vis;
int comp = 0;
void bfs(int s){
	comp++;
	queue<int> q;
	q.push(s);
	vis[s] = 0;
	while(!q.empty()){
		s = q.front();
		q.pop();
		bitset<N> BS = ALL & vis;
		for(int v : adj[s]) BS[v] = 0;
		for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i)){
			q.push(i);
			vis[i] = 0;
		}	
	}
}
int main(){
	int n, m; sd(n); sd(m);
	for(int i = 1; i <= m; i++){
		int u, v;
		sd(u); sd(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) ALL[i] = 1;
	vis = ALL;
	for(int i = 1; i <= n; i++) if(vis[i]) bfs(i);
	printf("%d\n", comp - 1);
}