#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())


#ifdef LOCAL
#define cerr cout
#else
#endif

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
const int N = 300005;
int a[N];
int main(){
	int n, q; sd(n); sd(q);
	int m = -1, ind = -1;
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		if(a[i] > m){
			m = a[i];
			ind = i;
		}
	}
	vector<pii> v = {{0, 0}};
	int cnt = n;
	for(int i = 1; i < ind; i++){
		int mx = max(a[i], a[i + 1]);
		int mn = min(a[i], a[i + 1]);
		v.push_back({a[i], a[i + 1]});
		a[++cnt] = mn;
		a[i + 1] = mx;
	}
	while(q--){
		ll x;
		scanf("%lld", &x);
		if(x < (int)v.size()){
			printf("%d %d\n", v[x].F, v[x].S);
		} else{
			printf("%d %d\n", m, a[ind + 1 + (x - (int)v.size()) % (cnt - ind)]);
		}
	}
}