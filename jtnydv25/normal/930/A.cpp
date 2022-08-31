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

const int N = 1e5 + 5;
vector<int> con[N];
int depth[N];
int cnt[N];
void dfs(int s = 1, int p = 0){
	depth[s] = depth[p] + 1;
	cnt[depth[s]] ^= 1;
	for(int v : con[s]) dfs(v, s);
}

int main(){
	int n;
	sd(n);
	for(int i = 2; i <= n; i++){
		int x;
		sd(x);
		con[x].push_back(i);
		// con[i].push_back(x);
	}
	dfs();
	int ans = 0;
	for(int i = 1; i < N; i++) ans += cnt[i];
	printf("%d\n", ans);
}