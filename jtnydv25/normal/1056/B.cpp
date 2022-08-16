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

inline int getCount(int x, int n, int m){
	if(n < x) return 0;
	if(x == 0) return n / m;
	return 1 + (n - x) / m;
}

int main(){
	int n, m; sd(n); sd(m);
	long long ans = 0;
	for(int x = 0; x < m; x++)
		for(int y = 0; y < m; y++){
			if((x * x + y * y) % m == 0) ans += getCount(x, n, m) * (ll) getCount(y, n, m);
		}
	printf("%lld\n", ans);
}