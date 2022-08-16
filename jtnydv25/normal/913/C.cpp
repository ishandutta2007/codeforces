#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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

const int N = 35;
ll c[N];
int invalid[N];

int n;
const ll inf = 1e18;
ll minCost(ll L){
	// trace(L);
	if(L == 0) return 0;
	ll take = 0;
	int j = 0;
	while((1LL << j) < L) j++;
	ll ret = inf;
	if(j < n){
		for(int k = j + 1; k <= n; k++) ret = min(ret, c[k]);
	}
	int mx = 1;
	for(int i = 1; i <= n; i++){
		if(!invalid[i] && (1LL << (i - 1) <= L))
			mx = i;
	}
	// k * z <= L
	ll k = L >> (mx - 1);
	ret = min(ret, k * c[mx] + minCost(L % (1 << (mx - 1))));
	return ret;
}

int main(){
	ll L;
	sd(n);
	scanf("%lld", &L);
	for(int i = 1; i <= n; i++) scanf("%lld", c + i);
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(c[i] >= (c[j] << (i - j))) invalid[i] = 1;
		}
	}
	printf("%lld\n", minCost(L));
}