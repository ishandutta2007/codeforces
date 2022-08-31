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

const int N = 300005;
ll a[N];
int f[N];
int cnt(ll x){
	// trace(x);
	int ret = 0;
	for(; x; x >>= 1) ret += (x & 1);
		return ret;
}
int g[N];
int pref[2][N];
int main(){	
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		// a[i] = rand();
		scanf("%lld", a + i);
		f[i] = cnt(a[i]);
		g[i] = (g[i - 1] + f[i]) & 1;
		pref[0][i] = pref[0][i - 1];
		pref[1][i] = pref[1][i - 1];
		pref[g[i]][i]++;
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		int mx = 0, sm = 0;
		int j = i;
		for(; j <= n; j++){
			if(j - i >= 70) break;
			sm += f[j];
			mx = max(mx, f[j]);

			if(2 * mx <= sm && (sm % 2 == 0)){
				ans++;
			}
		}
		ans += pref[g[i - 1]][n] - pref[g[i - 1]][j - 1];
	}
	printf("%lld\n", ans);
}