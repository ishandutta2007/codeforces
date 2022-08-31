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

const int N = (1 << 22);
int n, m;
int a[N];
bool vis[N][2];
bool present[N];
inline int ulta(int x){ return ((1 << n) - 1) ^ x;}

void dfs(int s, int dummy = 0){
	vis[s][dummy] = 1;
	if(dummy){
		if(present[s] && !vis[s][0]) dfs(s, 0);
		for(int i = 0; i < n; i++) if(s >> i & 1){
			int node = s ^ (1 << i);
			if(!vis[node][1]) dfs(node, 1); 
		}
	}
	int dummy_s = ulta(s);
	if(!dummy){
		if(!vis[dummy_s][1]) dfs(dummy_s, 1);
	}
}

int main(){
	sd(n); sd(m);
	for(int i = 0; i < m; i++){
		sd(a[i]);
		present[a[i]] = 1;
	}
	int ans = 0;
	for(int i = 0;i < m; i++) if(!vis[a[i]][0]){
		ans++;
		dfs(a[i], 0);
	}
	printf("%d\n", ans);
}