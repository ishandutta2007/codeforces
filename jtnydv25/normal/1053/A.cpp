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


int main(){
	int n, m, k;
	sd(n);sd(m); sd(k);
	ll x = 2ll * n * 1ll * m;
	if(x % k  != 0){
		printf("NO\n");
		return 0;
	}	

	if((2 * m) % (k / __gcd(n, k)) == 0){
		int y = (2 * m) / (k / __gcd(k, n));
		int x = n / __gcd(n, k);
		if(y == 2 * m){
			y /= 2;
			x *= 2;
		}
		if(x <= n && y <= m){
			printf("YES\n");
			printf("%d %d\n", 0, 0);
			printf("%d %d\n", x, 0);
			printf("%d %d\n", 0, y);
			return 0;
		}
	}
	printf("NO\n");
}