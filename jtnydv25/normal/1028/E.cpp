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
const int N = 150000;
ll a[N];
int b[N];
int n;
int nxt(int x){return x == n ? 1 : x + 1;}
int prev(int x){return x != 1 ? x - 1 : n;}
int main(){
	sd(n);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		sd(b[i]);
		if(b[i]) cnt++;
	}
	if(!cnt){
		printf("YES\n");
		for(int i = 1; i <= n; i++) printf("%d ", 1);
		return 0;
	}
	bool found = 0;
	for(int i = 1; i <= n; i++){
		if(b[prev(i)] < b[i]){
			a[i] = b[i];
			a[prev(i)] = a[i] * (ll) 1e9 + b[prev(i)];
			for(int j = prev(prev(i)); j != i && j != prev(i); j = prev(j)){
				a[j] = a[nxt(j)] + b[j];
			} 
			found = 1;
			printf("YES\n");
			for(int i = 1; i <= n; i++) printf("%lld ", a[i]); printf("\n");
			for(int i = 1; i <= n; i++){
				assert(a[i] % a[nxt(i)] == b[i]);
			}
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}