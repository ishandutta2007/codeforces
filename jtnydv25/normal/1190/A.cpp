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
const int N = 100005;
ll p[N];
void solve(){
	ll n, k;
	int m;
	scanf("%lld %d %lld", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		scanf("%lld", p + i);
		p[i]--;
	}
	int ans = 0;
	for(int i = 1; i <= m;){
		int shift = i - 1;
		ll block = (p[i] - shift) / k;
		while(i <= m && (p[i] - shift) / k == block) i++;
		ans++;
	}
	printf("%d\n", ans);
}

int main(){
	int t = 1;
	// sd(t);
	for(int tt = 1; tt <= t; tt++){
		// printf("Case #%d: ", tt);
		solve();
	}
}