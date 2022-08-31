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

const int N = 200005;
int a[N];
int main(){
	int n, k;
	sd(n); sd(k);
	for(int i = 1; i <= n; i++) sd(a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int pos = upper_bound(a + 1, a + n + 1, a[i]) - a;
		if(pos > n || a[pos] > a[i] + k) ans++;
	}
	printf("%d\n", ans);
}