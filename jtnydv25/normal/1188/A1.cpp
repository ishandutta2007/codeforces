#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#ifdef LOCAL
#define cerr cout
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

void solve(){
	int n; sd(n);
	vector<int> deg(n + 1, 0);
	for(int i = 1;  i < n; i++){
		int u, v;
		sd(u); sd(v);
		deg[u]++;
		deg[v]++;
	}

	for(int i = 1;  i<=n; i++) if(deg[i] == 2){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(){
	int t = 1;
	for(int tt = 1; tt <= t; tt++){
		solve();
	}
}