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
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N = 200005;
const ll INF = 1LL << 59;
int a[N], b[N], c[N], st[N], en[N];
int timer;


vector<int> adj[N];
set<int> positions[2];
vector<int> removals[2];
void dfs(int s = 0, int p = -1){
	st[s] = ++timer;
	for(int v : adj[s]) if(v != p) dfs(v, s);
	en[s] = timer;
}
int main(){
	int n; sd(n);
	int sm = 0;
	vector<int> perm(n);
	for(int i = 0; i < n; i++){
		sd(a[i]); sd(b[i]); sd(c[i]);
		perm[i] = i;
	}
	for(int i = 1; i < n; i++){
		int u, v; sd(u); sd(v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for(int i = 0; i < n; i++) if(b[i] != c[i]){
		positions[b[i]].insert(st[i]);
		// trace(i, b[i], c[i]);
	}
	if(sz(positions[0]) != sz(positions[1])){
		printf("-1\n");
		return 0;
	}
	sort(all(perm), [&](int i, int j){return a[i] < a[j];});
	ll ans = 0;
	for(int node : perm){
		removals[0].clear();
		removals[1].clear();
		auto it1 = positions[0].upper_bound(st[node] - 1);
		auto it2 = positions[1].upper_bound(st[node] - 1);
		int num = 0;
		while(it1 != positions[0].end() && it2 != positions[1].end()){
			if(*it1 > en[node] || *it2 > en[node]){
				break;
			}
			removals[0].push_back(*it1);
			removals[1].push_back(*it2);
			num++;
			it1++; it2++;
		}
		ans += num * (ll)a[node];
		for(auto it : removals[0]) positions[0].erase(it);
		for(auto it : removals[1]) positions[1].erase(it);
	}
	printf("%lld\n", 2 * ans);
}