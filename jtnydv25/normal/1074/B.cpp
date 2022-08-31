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
const int N = 1005;
vector<int> con[N];
int par[N];
void dfs(int s, int p = -1){
	par[s] = p;
	for(int v : con[s]) if(v != p){ dfs(v, s); }
}

int query1(int x){
	printf("A %d\n", x);
	fflush(stdout);
	int y; scanf("%d", &y);
	return y;
}

int query2(int x){
	printf("B %d\n", x);
	fflush(stdout);
	int y; scanf("%d", &y);
	return y;
}

int U[N], V[N];
bool thereU[N], thereV[N];
int main(){
	int t; sd(t);
	while(t--){
		int n; sd(n);
		memset(par, -1, sizeof par);
		for(int i = 1; i <= n; i++) con[i].clear();
		for(int i = 1; i < n; i++){
			int a, b; scanf("%d %d", &a, &b);
			con[a].push_back(b);
			con[b].push_back(a);
		}
		memset(thereU, 0, sizeof thereU);
		memset(thereV, 0, sizeof thereV);
		int k1, k2;	
		sd(k1);
		for(int i = 1; i <= k1; i++) sd(U[i]), thereU[U[i]] = 1;
		sd(k2);
		for(int i = 1; i <= k2; i++) sd(V[i]), thereV[V[i]] = 1;
		dfs(U[1]);
		int node = query2(V[1]);
		while(node != -1 && !thereU[node]) node = par[node];
		assert(node != -1);
		int _node = query1(node);
		if(!thereV[_node]){
			printf("C -1\n");
			fflush(stdout);
		} else{
			printf("C %d\n", node);
			fflush(stdout);
		}
	}
}