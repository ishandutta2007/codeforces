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
int x[N];
int f[N], g[N];

int main(){
	int n, k; sd(n); sd(k);
	for(int i = 1; i <= n; i++) g[i] = k + 1;
	for(int i = 1; i <= k; i++){
		sd(x[i]);
		f[x[i]] = i;
		g[x[i]] = min(g[x[i]], i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!f[i]) ans++;
		if(i != n){
			ans += (g[i] > f[i + 1]);
		}
		if(i != 1) ans += g[i] > f[i - 1];
	}
	printf("%d\n", ans);
}