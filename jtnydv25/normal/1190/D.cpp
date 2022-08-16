#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#ifdef LOCAL
#define cerr cout
#endif

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 200005;
int x[N], y[N];

int get_in_range(int a, int b, ordered_set & os){
	if(a > b) return 0;
	int ret = os.order_of_key(b + 1) - os.order_of_key(a);
	// trace(ret, a, b);
	return ret;
}

ll num(int x){
	return (x * (ll) (x + 1)) >> 1;
}

void solve(){
	int cnt = 0;
	int n; sd(n);
	map<int, set<int>> mp;
	for(int i = 1; i <= n; i++){
		sd(x[i]); 
		sd(y[i]);
		mp[-y[i]].insert(x[i]);
	}

	ordered_set os;
	ll ans = 0;
	for(auto it : mp){
		int sz = os.size();
		for(auto z : it.S){
			if(!get_in_range(z, z, os)) sz++;
		}

		ans += num(sz);
		int mn = -1;
		for(auto z : it.S){
			ans -= num(get_in_range(mn + 1, z - 1, os));
			mn = z;
		}
		ans -= num(get_in_range(mn + 1, (int)2e9, os));

		for(auto z : it.S) os.insert(z);
		// trace(os.size());
	}
	printf("%lld\n", ans);
}

int main(){
	int t = 1;
	// sd(t);
	for(int tt = 1; tt <= t; tt++){
		// printf("Case #%d: ", tt);
		solve();
	}
}