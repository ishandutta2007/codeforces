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

const int N = 1e7 + 10;
int a[N];

int main(){
	int t; cin >> t;
	while(t--){
		int n, l, r;
		unsigned int b1, b2, x, y, z;
		cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
		bool found = 0;

		a[1] = l + (b1 % (r - l + 1));
		a[2] = l + (b2 % (r - l + 1));

		for(int i = 3; i <= n; i++){
			unsigned int X = x * b1 + y * b2 + z;
			b1 = b2;
			b2 = X;
			a[i] = l + (b2 % (r - l + 1));
		}

		int mn = INT_MAX;
		long long ans = 8e18;	
		for(int i = 1; i <= n; i++){
			if(a[i] >= 0){
				if(mn < a[i]){
					found = 1;
					ans = min(ans, a[i] * (ll) mn);
				}
			}
			mn = min(mn, a[i]);
		}
		int mx = INT_MIN;
		for(int i = n; i >= 1; i--){
			if(a[i] <= 0 && mx > a[i]){
				found = 1;
				ans = min(ans, a[i] * (ll) mx);
			}
			mx = max(mx, a[i]);
		}

		if(!found){
			printf("IMPOSSIBLE\n");
		} else printf("%lld\n", ans);
	}
}