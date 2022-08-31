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
int lst[N];
bool blocked[N];
int a[N], s[N];
int main(){
	int n, m, k;
	sd(n); sd(m); sd(k);
	int mn = 1;
	for(int i = 1; i <= m; i++){
		sd(s[i]);
		// if(i > 1) mn = max(mn, s[i] - s[i - 1] + 1);
		blocked[s[i]] = 1;
	}

	for(int i = 1; i <= k; i++) sd(a[i]);

	if(blocked[0]){
		printf("-1\n");
		return 0;
	}

	for(int i = 0; i < n; i++){
		lst[i] = blocked[i] ? lst[i - 1] : i;
		mn = max(mn, i - lst[i]);
	}
	long long ans = 1e18;
	for(int l = mn; l <= k; l++){
		int curr = 0;
		bool ok = 1;
		int cnt = 0;
		while(curr < n){
			cnt++;
			int prev = curr;
			curr += l;
			if(curr < n){
				curr = lst[curr];
				if(curr <= prev){
					ok = 0;
					break;
				}
			}
		}
		if(ok){
			ans = min(ans, a[l] * (ll) cnt);
		}
	}
	if(ans >=1e15) ans = -1;
	printf("%lld\n", ans);
}