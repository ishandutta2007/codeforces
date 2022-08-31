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
const int N = 500005;
int d[N];
ll pref[N];

inline ll getSum(int i, int j){
	return i > j ? 0 : pref[j] - pref[i - 1];
}

int main(){
	int n; scanf("%d", &n);
	int parity = 0;
	ll sm = 0;
	for(int i = 1; i <= n; i++) scanf("%d", d + i), parity ^= (d[i] & 1), sm += d[i];		
	if(sm > (n * (ll) ( n + 1))){
		printf("-1\n");
		return 0;
	}

	sort(d + 1, d + n + 1, [](int i, int j){return i > j;});	
	for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + d[i];
	ll mx = n;
	ll mn = 0;
	int ind = n;

	for(int k = 1; k <= n + 1; k++){
		while(ind >= 0 && d[ind] < k) ind--;
		// 1 - ind -> >= k, else <= k
		mx = min(mx, k * (ll) (k - 1) + k * (ll) (max(0, ind - k + 1)) + pref[n] - pref[max(ind, k - 1)] - pref[k - 1]);
		if(k <= n){
			ll t = pref[k] - k * (ll) (k - 1) - k * (ll) max(0, ind - k) - pref[n] + pref[max(ind, k)];
			if(k < t){
				printf("-1\n");
				return 0;
			}
			mn = max(mn, t);
		}
	}
	vector<int> sol;
	for(ll x = mn; x <= mx; x++) if((x & 1) == parity){
		sol.push_back(x);
	}
	if(sol.empty()) printf("-1\n");
	else{
		// printf("%d\n", (int) sol.size());
		for(auto it : sol) printf("%d ", it);
		printf("\n");
	}
}