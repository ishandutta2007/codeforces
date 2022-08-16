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

const int N = 105;
int a[N];
int main(){
	int n;
	sd(n);
	int lo = 0;
	int sm = 0;
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		lo =max(lo, a[i]);
		sm += a[i];
	}

	int hi = 1e5;
	while(lo < hi){
		int mid = (lo + hi) >> 1;
		int x = 0;
		for(int i = 1; i  <= n; i++) x += mid - a[i];
		if(x > sm){
			hi = mid;
		} else lo = mid + 1;
	}
	printf("%d\n", lo);
}