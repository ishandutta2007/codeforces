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
int m[N];
int pm[N];
int D[N];
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++) sd(m[i]);
	pm[n + 1] = -1e9;
	for(int i = n; i >= 1; i--){
		pm[i] = max(m[i] - i, pm[i + 1]);
		// trace(i, pm[i]);
	}
	int carry = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		D[i] = max(D[i - 1] + carry, pm[i] + i);
		// trace(D[i])	;
		carry = (D[i] == m[i]);
	}
	for(int i = 1; i < n; i++){
		ans += D[i] - m[i] - (D[i + 1] == D[i]);
	}
	ans += D[n] - m[n] - 1 + (D[n] == m[n]);
	printf("%lld\n", ans);
}