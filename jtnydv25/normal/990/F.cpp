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

const int N = 	200005;
int g[N];
int vis[N];
vector<int> con[N];
int ans[N];
int x[N], y[N];

bool ok = 1;
int dfs(int s, int p = 0){
	vis[s] = 1;
	int total_give = g[s];
	for(int edge : con[s]){
		int v = s ^ x[edge] ^ y[edge];
		if(!vis[v]){
			int val = dfs(v, s);
			total_give += val;
			if(x[edge] == v) ans[edge] = -val;
			else ans[edge] = val;
		}
	}
	if(p == 0 && total_give != 0) ok = 0;
	return total_give;
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++) sd(g[i]);
	int m; sd(m);
	for(int i = 1; i <= m; i++) sd(x[i]), sd(y[i]), con[x[i]].push_back(i), con[y[i]].push_back(i);
	for(int i = 1; i <= n; i++) if(!vis[i]){
		dfs(i);
	}
	if(!ok){
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	for(int i =1; i <= m; i++) printf("%d\n", ans[i]);	
}