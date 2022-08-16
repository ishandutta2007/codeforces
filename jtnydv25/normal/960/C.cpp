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

int get(int n){
	int x = 0;
	while((1 << x) - 1 <= n) x++;
	x--;
	return x;
}
vector<ll> ans;
int main(){
	ll X, d;
	scanf("%lld %lld", &X, &d);
	long long curr = d;
	while(X){
		int x = get(X);
		for(int j = 0; j < x; j++) ans.push_back(curr);
		X -= (1 << x) - 1;
		curr += 2 * d;
	}
	printf("%d\n", (int)ans.size());
	for(auto it : ans) printf("%lld ", it);
}