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
const int N = 2e5 + 10;
int a[N];
int main(){
	int n, s; sd(n); sd(s);
	for(int i = 1; i <= n; i++) sd(a[i]);
	sort(a + 1, a + n + 1);
long long ans = 0;
	for(int i = 1; i <= n; i++){
		if(2 * i - 1 < n){
			if(a[i] > s) ans += a[i] - s;
		} else if(2 * i - 1 == n) ans += abs(s - a[i]);
		else if(a[i] < s) ans += s - a[i];
	}
	printf("%lld\n", ans);
}