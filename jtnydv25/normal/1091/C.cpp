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

inline ll sm(ll x){return (x * (x + 1)) >> 1;}
set<ll> ans;
void add(ll d, ll n){
	ans.insert(n / d + d * sm(n / d - 1));
}
int main(){
	long long n; scanf("%lld", &n);
	for(ll t = 1; t* t <= n; t++){
		if(n % t == 0){
			add(t, n);
			add(n / t, n);
		}
	}
	// printf("%d\n", (int)ans.size());
	for(auto it : ans) printf("%lld ", it);
}