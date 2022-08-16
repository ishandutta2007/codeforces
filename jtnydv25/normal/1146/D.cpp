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

const int N = 200005;
bool vis[N];
ll f(int n){
	return (n * (ll) (n + 1)) >> 1;
}

int cnt = 0;
int x = 0, m, a, b;
void dfs(int s){
	if(!vis[s]){
		vis[s] = 1;
		cnt++;
	}
	else{
		return;
	}

	if(s + a <= x) dfs(s + a);
	if(s - b >= 0) dfs(s - b);
}

int main(){
	cin >> m >> a >> b;
	int g = __gcd(a, b);
	a /= g; b /= g;
	dfs(0);
	ll ans = 0;
	for(x = 1; x * g <= m; x++){
		ans += g * (ll) cnt;
		if(x - a >= 0 && vis[x - a]){
			dfs(x);
		}
		if(cnt == x + 1 && x >= a){
			break;
		}
	}
	if(x * g > m){
		ans += (m - (x - 1) * g + 1) * (ll) cnt;
		printf("%lld\n", ans);
		return 0;
	}
	ans += g * (ll) (f(m / g) - f(x));
	ans += (m - g * (m / g) + 1) * (ll) (m / g + 1);
	printf("%lld\n", ans);
}