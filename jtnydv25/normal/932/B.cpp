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

const int N = 1000006;
int st[N];
vector<int> vec[10];
int f(int n){
	int ret = 1;
	while(n){
		int q = n / 10;
		int t = n - 10 * q;
		if(t) ret *= t;
		n = q;
	}
	return ret;
}

int g(int n){
	if(n < 10) return n;
	if(st[n]) return st[n];
	return st[n] = g(f(n));
}

int main(){
	for(int i = 1; i < N; i++) vec[g(i)].push_back(i);
	int q;
	sd(q);
	while(q--){
		int l, r, k;
		sd(l); sd(r); sd(k);
		printf("%d\n", (int)(upper_bound(vec[k].begin(), vec[k].end(), r) - upper_bound(vec[k].begin(), vec[k].end(), l-1)));
	}
}