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
vector<ll> vec;
int main(){
	ll n;
	cin >> n;
	set<ll> st;
	for(int i = 0; i <= min(100, (int)n); i++)
		for(int j = 0; i + j <= min(100, (int)n); j++){
			for(int k = 0; i + j + k <= min(100, (int)n); k++){
				long long val = 4 * (ll) i + 9 * (ll) j + 49 * (ll) k;
				st.insert(val + n);
			}
		}

	if(n <= 100){
		cout << st.size();
		return 0;
	}

	for(int i = 0; i <= 100; i++)
		for(int j = 0; i + j <= 100; j++){
			for(int k = 0; i + j + k <= 100; k++){
				long long val = 4 * (ll) i + 9 * (ll) j + 49 * (ll) k;
				st.insert(val + n);
			}
		}


	long long mn = n + 100;
	long long mx = 50 * (n - 20) - 1;

	long long ans = mx - mn + 1;
	
	for(int x50 = n - 50; x50 <= n; x50++){
		for(int x5 = 0; x5 + x50 <= n; x5++){
			for(int x10 = 0; x10 + x5 + x50 <= n; x10++){
				long long val = x5 * (ll) 4 + x10 * (ll) 9 + x50 * (ll) 49;
				st.insert(n + val);
			}
		}
	}
	for(auto it : st) if(it > mx || it < mn) ans++;
	cout << ans;
}