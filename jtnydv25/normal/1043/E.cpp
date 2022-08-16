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
int perm[N], x[N], y[N];
ll ans[N];
int main(){
	int n, m; sd(n); sd(m);
	long long sumx = 0, sumy = 0;
	for(int i = 1; i <= n; i++) sd(x[i]), sd(y[i]), perm[i] = i, sumx += x[i], sumy+= y[i];
	sort(perm + 1, perm + n + 1, [](int i, int j){return x[i] - y[i] > x[j] - y[j];});
	ll sx = 0, sy = 0;
	for(int ind =1; ind <= n; ind++){
		int i = perm[ind];
		// j < i -> x[i] + y[j]
		ans[i] = x[i] * (ll) (ind - 1) + sy + (sumx - sx - x[i]) + y[i] * (ll)(n - ind);
		sx += x[i];
		sy += y[i];
	}

	for(int i = 1; i <= m; i++){
		int a, b; sd(a); sd(b);
		int sc = min(x[a] + y[b], y[a] + x[b]);
		ans[a] -= sc;
		ans[b] -= sc;
	}

	for(int i = 1; i <= n; i++) printf("%lld ", ans[i]); printf("\n");
}