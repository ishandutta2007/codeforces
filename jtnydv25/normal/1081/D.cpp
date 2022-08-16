#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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

const int N = 1e5 + 10;

vector<int> v[N];
int par[N];
pair<int, pair<int, int> > edges[N];

int root(int x){return x == par[x] ? x : (par[x] = root(par[x]));}

int n, m, k;
int ans[N];
void merge(int x, int y, int w){
	x = root(x); y = root(y);
	if(x == y) return;
	if((int)v[x].size() < (int)v[y].size()) swap(x, y);
	int sz1 = v[x].size(), sz2 = v[y].size();

	if(sz1 + sz2 == k && sz1 && sz2){
		for(auto it : v[x]) ans[it] = w;
		for(auto it : v[y]) ans[it] = w;
	}

	for(auto it : v[y]) v[x].push_back(it);
	v[y].clear();
	par[y] = x;
}

int main(){
	sd(n); sd(m); sd(k);
	for(int i = 1; i <= n; i++) par[i] = i;
	for(int i = 1; i <= k; i++){
		int t;
		sd(t);
		v[t].push_back(i);
	}
	for(int i =1; i <= m; i++){
		int a, b, w; sd(a); sd(b); sd(w);
		edges[i] = {w, {a, b}};
	}
	sort(edges + 1, edges + m + 1);
	for(int i = 1; i <= m; i++) merge(edges[i].S.F, edges[i].S.S, edges[i].F);
	for(int i = 1; i <= k; i++) printf("%d ", ans[i]); printf("\n");
}