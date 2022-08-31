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

const int N = 100005;
ll a[N], sm[N];
vector<int> con[N];
bool ok = 1;
ll ans = 0;
void dfs(int s, int p = 0, int d = 0){
	if(!ok) return;
	if(d & 1){
		ll min_child = 1e18;
		ll sm_child = 0;
		ll up = sm[p];
		int num = 0;
		for(int v : con[s]){
			if(v != p){
				sm_child += sm[v];
				min_child = min(min_child, sm[v]);
				num++;
			}
		}
		if(min_child < up){
			ok = 0;
			return;
		}
		sm[s] = num == 0 ? up : min_child;
	}

	a[s] = sm[s] - sm[p];

	for(int v : con[s]){
		if(v != p){
			dfs(v, s, d ^ 1);
		}
	}

}

int main(){
	int n; sd(n);
	for(int i = 2; i <= n; i++){
		int p; sd(p);
		con[i].push_back(p);
		con[p].push_back(i);
	}
	for(int i = 1; i <=  n; i++) scanf("%lld", sm + i);
	dfs(1);
	if(!ok){
		printf("-1\n");
	}
	else{
		ll ans = 0;
		for(int i = 1; i <= n; i++) ans += a[i];
		printf("%lld\n", ans);
	}
}